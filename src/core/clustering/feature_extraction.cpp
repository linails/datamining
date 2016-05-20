/*
 * Progarm Name: feature_extraction.cpp
 * Created Time: 2016-03-04 16:50:32
 * Last modified: 2016-03-16 17:47:12
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "feature_extraction.h"
#include <cmath>
#include <iostream>
#include <cstdio>
#include <map>
#include <list>
#include <vector>
#include <sys/time.h>

using std::cout;
using std::endl;

/*constructor*/
FeatureExtraction::FeatureExtraction(std::vector<float> &r_orig_dataset)
    :m_orig_dataset(r_orig_dataset)
{
    float variance;
    std::pair<std::vector<float>&, int> datain(this->m_orig_dataset,9);
    std::pair<std::map<float,std::vector<float> > &,float &> dataout(this->m_cluster_dataset,variance);

#if 1
    KMeans kmeans(datain,dataout);
    cout << " ----variance :" << variance << endl;
#endif

#if 1
    do{
        datain.second--;
        kmeans.kmeans_clustering(datain,dataout);
        cout << " ----variance :" << variance << endl;
    }while(datain.second > 1);
#endif
}

/*default destructor*/
FeatureExtraction::~FeatureExtraction()
{
}

/*get feature -> eg. {0.0123   0.3445  0.7665} ,success return true*/
bool FeatureExtraction::get_feature(std::vector<float> &r_feature)
{
    return true;
}

/*constructor
 * std::pair<std::vector<float> &r_orig_dataset,int k> &r_in
 * std::pair<std::map<float,std::vector<float> > &r_cluster_dateset,float &r_dvariance> &r_out*/
KMeans::KMeans(std::pair<std::vector<float> &,int> &r_in,
               std::pair<std::map<float,std::vector<float> > &,float &> &r_out)
    :m_k(r_in.second)
    ,m_orig_dataset(r_in.first)
{

    while(this->get_centroid()){
        this->clustering();
    }

    r_out.first = this->m_cluster_dataset;
    this->get_dataset_variance(r_out.second);
#if 0
    for(auto iter = this->m_cluster_dataset.begin();
             iter != this->m_cluster_dataset.end(); iter++){
        cout << "core : " << iter->first << " - count :" << iter->second.size() << endl;

        int i = 0;
        for(auto iter_vec = iter->second.begin();
                 iter_vec != iter->second.end(); iter_vec++){
                printf("%10f",iter->second[i]);
                if((++i + 1)%5 == 0)
                    cout << endl;
        }
        cout << endl;

    }
#endif
}

/*default destructor*/
KMeans::~KMeans()
{
}

/*kmenas clustering*/
bool KMeans::kmeans_clustering(std::pair<std::vector<float> &,int> &r_in,
                               std::pair<std::map<float,std::vector<float> > &,float &> &r_out)
{
    this->m_k = r_in.second;
    this->m_orig_dataset = r_in.first;
    this->m_cluster_dataset.clear();

    while(this->get_centroid()){
        this->clustering();
    }

    r_out.first = this->m_cluster_dataset;
    this->get_dataset_variance(r_out.second);

    return true;
}

/*get featrue -> eg. {0.0123   0.3445  0.7665}*/
void KMeans::get_feature(std::vector<float> &r_feature)
{
    for(auto iter = this->m_cluster_dataset.begin();
             iter != this->m_cluster_dataset.end(); iter++){
        r_feature.push_back(iter->first);
    }
}

/*get dataset variance*/
void KMeans::get_dataset_variance(float &r_dvariance)
{
    cout << "list variance : ";
    r_dvariance = 0.0;
    float variance_unit = 0.0;
    for(auto iter = this->m_cluster_dataset.begin();
             iter != this->m_cluster_dataset.end(); iter++){
        variance_unit = this->get_variance(iter->first,iter->second);
        r_dvariance += variance_unit;
        cout << variance_unit << " " ;
    }
    cout << endl;
}

/*clustering*/
void KMeans::clustering(void)
{
    std::vector<
        std::pair<
            int ,
            std::pair<float,std::map<float,std::vector<float> >::iterator> 
                > 
        > eucindex;

    for(auto iter = this->m_orig_dataset.begin();
             iter != this->m_orig_dataset.end(); iter++){

        eucindex.clear();

        std::map<float,std::vector<float> >::iterator iter_map = this->m_cluster_dataset.begin();

        for(int i=0; i<this->m_k; i++,iter_map++){
            if(eucindex.size()){
                float distance = this->get_eucdistance(iter_map->first,*iter);

                if(eucindex[0].second.first > distance){
                    eucindex.pop_back();
                    eucindex.push_back(std::make_pair(i,std::make_pair(distance,iter_map)));
                }
            }else{
                eucindex.push_back(
                        std::make_pair(i,std::make_pair(this->get_eucdistance(iter_map->first,*iter),iter_map))
                        );
            }
        }

        eucindex[0].second.second->second.push_back(*iter);

#if 0
        static int j = 0;
        printf("%3d : data :%10f -> core : %10f -> index : %2d \n"
               ,++j,*iter,eucindex[0].second.second->first,eucindex[0].first);
#endif
    }
}

/*if f1 == f2 ; then return true*/
bool KMeans::isequal(float f1,float f2) // equal return true
{
    return fabs(f1 - f2) < 0.000001f ? true : false ;
}

/*get cetroid , success return true*/
bool KMeans::get_centroid(void)
{
    if(this->m_cluster_dataset.size() == 0){
        float means = 0.0;
        float min = this->m_orig_dataset[0];
        float max = this->m_orig_dataset[0];
        for(auto iter = this->m_orig_dataset.begin();
                iter != this->m_orig_dataset.end(); iter++){
            means += *iter;
            min = min > *iter ? *iter : min ;
            max = max < *iter ? *iter : max ;
        }
        means /= this->m_orig_dataset.size();

        float mingap,maxgap;
        if(this->m_k % 2){
            /*this->m_k is odd num*/

            mingap = (means - min) / ((this->m_k + 1) / 2 * 1.0);
            maxgap = (max - means) / ((this->m_k + 1) / 2 * 1.0);

            std::vector<float> empty;
            for(int i=0; i<this->m_k; i++){
                if(i < (this->m_k-1) / 2)
                    this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                            ::value_type(min+(i+1)*mingap,empty));
                else if(i == (this->m_k - 1)/2)
                    this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                            ::value_type(means,empty));
                else
                    this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                            ::value_type(means+(i-(this->m_k-1)/2+1)*maxgap,empty));
            }
        }else{
            mingap = (means - min) / (this->m_k  * 1.0);
            maxgap = (max - means) / (this->m_k  * 1.0);

            /*
             * eg. this->m_k = 4 
             * ***^***^***$***^***^***
             * ^ is centroid
             * */
            std::vector<float> empty;
            for(int i=0; i<this->m_k; i++){
                if(i < this->m_k / 2)
                    this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                            ::value_type(min+(i*2+1)*mingap,empty));
                else
                    this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                            ::value_type(means+((i-this->m_k/2)*2+1)*maxgap,empty));
            }
        }
#if 0
        cout << "print m_cluster_dataset:" << endl;
        int i = 0;
        for(auto iter = this->m_cluster_dataset.begin();
                 iter != this->m_cluster_dataset.end(); iter++){
            cout << "cluster : " << ++i ; 
            cout << " centroid : " << iter->first << " vecter<> siez : " << iter->second.size() << endl; 
        }
#endif
        return true;
    }else{

        bool flag = true;
        std::vector<std::pair<float,float> > vcore_old_new;
        for(auto iter = this->m_cluster_dataset.begin();
                 iter != this->m_cluster_dataset.end(); iter++){
            
            float means = 0.0;
            for(auto iter_vec = iter->second.begin();
                     iter_vec != iter->second.end(); iter_vec++){
                means += *iter_vec;
            }
            means /= iter->second.size() * 1.0;

            if(this->isequal(iter->first,means) == false) flag = false;

            vcore_old_new.push_back(std::make_pair(iter->first,means));
        }

        if(flag == false){

            this->m_cluster_dataset.clear();

            std::vector<float> empty;
            for(auto iter = vcore_old_new.begin();
                    iter != vcore_old_new.end(); iter++){
                this->m_cluster_dataset.insert(std::map<float,std::vector<float> >\
                        ::value_type(iter->second,empty));
            }

            return true;
        }
        return false;
    }
}

/*get euclidean distance - 1D data*/
float KMeans::get_eucdistance(float centroid,float data)
{
    return centroid > data ? centroid - data : data - centroid;
}

/*get variance*/
float KMeans::get_variance(float core,std::vector<float> &r_vdata)
{
    double variance = 0.0;
    for(auto iter = r_vdata.begin();
             iter != r_vdata.end(); iter++){
        variance += (*iter - core)*(*iter - core);
    }
    variance = sqrt(variance /(r_vdata.size() * 1.0));
    return variance;
}

/*constructor*/
DensityBasedCluster::DensityBasedCluster()
{
}

/*default destructor*/
DensityBasedCluster::~DensityBasedCluster()
{
}

/*constructor*/
Leaders::Leaders()
{
}

/*default destructor*/
Leaders::~Leaders()
{
}

/*constructor*/
Dbscan::Dbscan()
{
}

/*default destructor*/
Dbscan::~Dbscan()
{
}







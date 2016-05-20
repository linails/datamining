/*
 * Progarm Name: cluster_dataset.cpp
 * Created Time: 2016-03-02 16:33:20
 * Last modified: 2016-03-04 16:44:18
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "cluster_dataset.h"
#include <vector>
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <sys/time.h>

using namespace std;

/*constructor*/
ClusterDataSet::ClusterDataSet(std::vector<float> &r_vecf,unsigned int dnum,int k)
    :m_k(k)
    ,m_dnum(dnum)
{
    this->generate_dataset();
    this->uniform_mixdata(r_vecf);
}

/*default destructor*/
ClusterDataSet::~ClusterDataSet()
{
}

/*uniform mixing dataset*/
void ClusterDataSet::uniform_mixdata(std::vector<float> &r_vecf)
{
    for(unsigned int i=0; i< this->m_dnum/this->m_k; i++){
        for(auto coniter = this->m_dataset.begin();
               coniter != this->m_dataset.end();
               coniter++){
            r_vecf.push_back(coniter->second.second[i]);
        }
    }

    auto coniter = --this->m_dataset.end();
    for(unsigned int i=0; i< this->m_dnum%this->m_k; i++)
        r_vecf.push_back(coniter->second.second[coniter->second.first - i - 1]);
}

/*generate dataset*/
void ClusterDataSet::generate_dataset(void)
{
    this->generate_centroid();

    struct timeval time;
    gettimeofday(&time,NULL);
    long seed = time.tv_usec;

    for(auto const_iter = this->m_dataset.begin();
            const_iter != this->m_dataset.end(); const_iter++){
        for(unsigned int i=0; i<const_iter->second.first; i++){
            const_iter->second.second.push_back(this->gauss(const_iter->first,this->m_delt,seed));
        }
    }
}

/*generate cent*/
void ClusterDataSet::generate_centroid(void)
{
    struct timeval time;
    gettimeofday(&time,NULL);
    long seed = time.tv_usec;

    for(int i=0; i<this->m_k ; i++){

        float cent_tmp;
        do{
            cent_tmp = this->gauss(0.5,this->m_delt,seed);
            if(cent_tmp < 0) cent_tmp = -cent_tmp;
            if(cent_tmp > 1.0) cent_tmp -= (int)cent_tmp;

            for(auto iter = this->m_dataset.begin(); iter != this->m_dataset.end(); iter++){
                if(iter->first > cent_tmp){
                    if(iter->first - cent_tmp < 0.2){
                        cent_tmp = - cent_tmp;
                        break;
                    }
                }else{
                    if(cent_tmp - iter->first < 0.2){
                        cent_tmp = - cent_tmp;
                        break;
                    }
                }
            }
        }while(cent_tmp < 0);

        std::vector<float> float_vec;

        unsigned int num_temp;
        if(i+1 == this->m_k){
            num_temp = this->m_dnum % this->m_k;
            num_temp += this->m_dnum / this->m_k;
        }else{
            num_temp = this->m_dnum / this->m_k;
        }

        cout << "centroid :" << cent_tmp << " - set num :" << num_temp << endl;

        this->m_dataset.insert(std::map<float,std::pair<unsigned int,std::vector<float> > >\
                ::value_type(cent_tmp,make_pair(num_temp,float_vec)));
    }
}

/*gauss , reference : dsp*/
double ClusterDataSet::gauss(float u,float delt,long int &seed)
{
    double x = 0.0, y = 0.0;
    for(int i=0; i<12; i++)
        x += this->uniform(0.0,1.0,seed);
    x -= 6.0;
    y = u + x * delt;
    return y;
}

/*uniform ,reference :dsp*/
double ClusterDataSet::uniform(double lower,double up,long int &seed)
{
    double t;
    seed = 2045 * seed + 1;
    seed = seed - (seed / 1048576) * 1048576;
    t = seed / 1048576.0;
    t = lower + (up - lower) * t;
    return t;
}


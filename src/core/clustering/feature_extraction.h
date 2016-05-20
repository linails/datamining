/*
 * Progarm Name: feature_extraction.h
 * Created Time: 2016-03-04 16:50:36
 * Last modified: 2016-03-14 16:29:57
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _FEATURE_EXTRACTION_H_
#define _FEATURE_EXTRACTION_H_
#include <vector>
#include <list>
#include <map>

/*feature extraction
 * get feature -> eg. {0.0123   0.3445  0.7665} ,success return true*/
class FeatureExtraction{
public:
    typedef std::vector<float> OrigDataset_t;
    typedef std::map<float,std::vector<float> > ClusterDataset_t;

    FeatureExtraction(std::vector<float> &r_orig_dataset);
    ~FeatureExtraction();
    bool get_feature(std::vector<float> &r_feature);
    void get_clustere_dataset(std::map<float,std::vector<float> > &r_cluster_dateset);
private:
private:
    std::list<std::pair<int,float> > m_dataset_variance;
    OrigDataset_t                    &m_orig_dataset;
    ClusterDataset_t                 m_cluster_dataset;
};

/*k means clustering
 *
 *  KMeans(std::pair<std::vector<float> &,int> &r_in,
 *         std::pair<std::map<float,std::vector<float> > &,float &> &r_out);
 *   r_in : std::pair<std::vector<float> &r_orig_dataset,int k>
 *   r_out: std::pair<std::map<float,std::vector<float> > &r_cluster_dateset,float &r_dvariance>
 *
 * float equal --> precision : 0.000001f
 * isequal() : if f1 == f2 ; then return true*/
class KMeans{
public:
    KMeans(std::pair<std::vector<float> &,int> &r_in,
           std::pair<std::map<float,std::vector<float> > &,float &> &r_out);
    ~KMeans();
    bool kmeans_clustering(std::pair<std::vector<float> &,int> &r_in,
           std::pair<std::map<float,std::vector<float> > &,float &> &r_out);
private:
    void get_feature(std::vector<float> &r_feature);
    void get_dataset_variance(float &r_dvariance);
    void clustering(void);
    bool isequal(float f1,float f2);
    bool get_centroid(void);
    float get_eucdistance(float centroid,float data);
    float get_variance(float core,std::vector<float> &r_vdata);
private:
    int m_k;
    FeatureExtraction::OrigDataset_t    m_orig_dataset;
    FeatureExtraction::ClusterDataset_t m_cluster_dataset;
};

/*density based clustering
 * */
class DensityBasedCluster{
public:
    DensityBasedCluster();
    ~DensityBasedCluster();
private:
};

/*Leaders clustering*/
class Leaders{
public:
    Leaders();
    ~Leaders();
private:
};

/*DBSCAN clustering*/
class Dbscan{
public:
    Dbscan();
    ~Dbscan();
private:
};

#endif //_FEATURE_EXTRACTION_H_


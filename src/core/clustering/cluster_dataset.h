/*
 * Progarm Name: cluster_dataset.h
 * Created Time: 2016-03-02 16:33:23
 * Last modified: 2016-03-04 14:05:19
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _CLUSTER_DATASET_H_
#define _CLUSTER_DATASET_H_
#include <vector>
#include <map>

/*cluster data set generator
 * k: eg.k=3
 * all core center => (0,1]
 * default contain 10000 elements
 * */
class ClusterDataSet{
public:
    ClusterDataSet(std::vector<float> &r_vecf,unsigned int dnum = 10000,int k = 1);
    ~ClusterDataSet();
private:
    void uniform_mixdata(std::vector<float> &r_vecf);
    void generate_dataset(void);
    void generate_centroid(void);
    double gauss(float u,float delt,long int &seed);
    double uniform(double lower,double up,long int &seed);
private:
    typedef std::map<float,std::pair<unsigned int,std::vector<float> > > DataSetType_t;
    int           m_k    = 1;
    float         m_delt = 0.4;
    unsigned int  m_dnum;
    DataSetType_t m_dataset;
};

#endif //_CLUSTER_DATASET_H_


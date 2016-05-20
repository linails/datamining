/*
 * Progarm Name: apriori.h
 * Created Time: 2016-03-16 15:43:48
 * Last modified: 2016-04-12 22:53:53
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _APRIORI_H_
#define _APRIORI_H_
#include <vector>
#include <map>
#include <string>
#include <list>
#include <bitset>
#include <tuple>

/*Apriori
 * std::map<int,GroupItemSet_t>
 * std::map<int,std::list<std::pair<std::bitset<NUM>,float> > >
 *       <num of combination, group list<<item group>, support> >
 * std::pair<float,std::bitset<NUM> >
 *    eg.<0.3324f , 0x0002>
 * std::pair<std::pair<std::bitset<NUM>,std::bitset<NUM> >,float>
 *       <<first,second>,confident>
 * */

/*set bitset NUM
 * std::vector<std::bitset<NUM> >
 * std::vector<std::bitset<800> >
 * */
#define     NUM     80

class Apriori{
public:
    Apriori(float p_dataset[][10],unsigned row,unsigned column);
    Apriori(std::map<unsigned ,std::vector<float> > &r_orig_dataset);
    Apriori(std::map<unsigned ,std::bitset<NUM> > &r_orig_dataset);
    void  calc_rules(void);
    void  get_rules(std::vector<std::tuple<std::bitset<NUM>,std::bitset<NUM>,float> > &r_rules_vector);
    void  get_rules(std::vector<std::pair<std::pair<std::vector<float>,std::vector<float> >,float> > &r_rules_vector);
    void  get_rules(std::vector<std::tuple<std::vector<float>,std::vector<float>,float> > &r_rules_vector);
    void  set_minsupport(float minsupport);
    void  set_minconfidence(float minconfidence);
    float get_minsupport(void);
    float get_minconfidence(void);
    ~Apriori();
private:
    typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t;
    typedef std::map<unsigned ,std::vector<float> > OrigDataSet_t;
    typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
    typedef std::list<std::pair<IndexBitSet_t,float> > GroupItemSet_t;
    typedef std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > Confidence_t;
    typedef std::map<IndexBitSet_t,std::map<int,Confidence_t> > ItemsetConfidence_t;

    void  get_data2bitset(void);
    void  get_base_dataset(void);
    void  get_group_itemset(void);
    void  get_itemset_confidence(void);

    int   isexist(float val);
    bool  isequal(float f1,float f2);
    float calc_support(std::bitset<NUM> bsdata);
    float calc_confidence(std::bitset<NUM> bsdata);
    bool  isexist(std::bitset<NUM> &r_unit,GroupItemSet_t &r_set);
    bool  isexist(std::bitset<NUM> &r_unit,Confidence_t &r_set);
    IndexBitSet_t get_index(std::bitset<NUM> &r_bsdata);
    std::bitset<NUM> confidence_get_antecedent(
            const std::bitset<NUM> &r_seccedent,
            const std::bitset<NUM> &r_bitset);
    void  confidence_iterator(float spt_AB,const std::bitset<NUM> &r_bsdata,std::map<int,Confidence_t> &r_unit);
    void  confidence_get_unitbitset(const std::bitset<NUM> &r_bsdata,std::vector<IndexBitSet_t> &r_unitbitset);
private:
    float                                m_support    =   0.0111;
    float                                m_confidence =   0.000001;
    OrigDataSet_t                        m_orig_dataset;        //原始数据集
    std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset;         //不含统计数据:float -> bitset
    std::map<unsigned ,IndexBitSet_t>    m_base_dataset;        //(data,vec float) -> (data,bitset)
    std::vector<std::bitset<NUM> >       m_bitset_vec;          //位向量列表，用于临时存储位向量

    std::map<int,GroupItemSet_t>         m_group_itemset;       //组合项集
    ItemsetConfidence_t                  m_itemset_confidence;  //可信度项集
};

#endif //_APRIORI_H_


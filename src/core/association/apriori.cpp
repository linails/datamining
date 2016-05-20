/*
 * Progarm Name: apriori.cpp
 * Created Time: 2016-03-16 15:43:48
 * Last modified: 2016-03-30 09:47:56
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "apriori.h"
#include <vector>
#include <map>
#include <string>
#include <list>
#include <bitset>
#include <tuple>
#include <iostream>
#include <cstdio>
#include <cmath>
#include "timer.h"

using std::cout;
using std::endl;

/*constructor
 * std::map<unsigned ,std::vector<float> > &r_orig_dataset
 *         <logic_data , float vector >
 * logic_data : data or time or times etc.
 *eg.
 *  1 -> 0.00234 0.03992 0.9877 0.2231 0.3345
 *  2 -> 0.03324 0.44345 0.2234 0.4434 0.2221
 *  ...
 *  */
Apriori::Apriori(std::map<unsigned ,std::vector<float> > &r_orig_dataset)
    :m_orig_dataset(r_orig_dataset)
{
    /*
     * typedef std::map<unsigned ,std::vector<float> > OrigDataSet_t;
     * OrigDataSet_t  m_orig_dataset;  //原始数据集
     * */

    this->get_data2bitset();
    this->get_base_dataset();
}

/*constructor*/
Apriori::Apriori(float p_dataset[][10],unsigned row,unsigned column)
{
    cout << "**p_dataset row column" << endl;

    std::vector<float> float_vec;

    for(unsigned i=0; i<row; i++){
        /*
         * std::map<unsigned ,std::vector<float> > OrigDataSet_t;
         * */
        this->m_orig_dataset.insert(
                std::map<unsigned ,std::vector<float> >::value_type(i,float_vec));
        for(unsigned j=0; j<column; j++){
            this->m_orig_dataset[i].push_back(p_dataset[i][j]);
        }
    }

    this->get_data2bitset();
    this->get_base_dataset();
#if 0
    cout << "sizeof m_orig_dataset : " << this->m_orig_dataset.size() << endl;
    for(auto iter = this->m_orig_dataset.begin();
             iter!= this->m_orig_dataset.end(); iter++){
        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            printf(" %.8f ",*iter2);
        }
        cout << endl;
    }
#endif
}

/*
 * constructor
 * std::map<unsigned ,std::bitset<NUM> > &r_orig_dataset
 *         <logic_data , bitset >
 * logic_data : data or time or times etc.
 *eg.
 *  1 -> 0x0103
 *  2 -> 0x0001
 *  ...
 *  */
Apriori::Apriori(std::map<unsigned ,std::bitset<NUM> > &r_orig_dataset)
{
    /*
     * typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t;
     * typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *
     * std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset;  //不含统计数据:float -> bitset
     * std::map<unsigned ,IndexBitSet_t>    m_base_dataset; //(data,vec float) -> (data,bitset)
     * std::vector<std::bitset<NUM> >       m_bitset_vec;   //位向量列表，用于临时存储位向量
     * */
}

/*default destructor*/
Apriori::~Apriori()
{
}

void Apriori::calc_rules(void)
{
    this->get_group_itemset();
    this->get_itemset_confidence();

#if 1
    cout << "================================================" << endl;
    /*
     * typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     * typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *
     * std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset
     * */
        cout << "sizeof bitset_vec : " << this->m_bitset_vec.size() << endl;
        for(auto iter = this->m_data2bitset.begin();
                iter!= this->m_data2bitset.end(); iter++){
            cout << "-0b" << this->m_bitset_vec[iter->first].to_string() << " - " << iter->second.second << endl;
        }
    
    cout << "----------- this->m_base_dataset --------------" << endl;
    unsigned int i = 0;
    for(auto iter = this->m_base_dataset.begin();
             iter!= this->m_base_dataset.end(); iter++ , i++){
        cout << "-0b" << this->m_bitset_vec[iter->second].to_string() << " - " << i << endl;
    }
    cout << "----------- this->m_group_itemset --------------" << endl;
    for(auto iter = this->m_group_itemset.begin();
             iter!= this->m_group_itemset.end(); iter++){
        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            cout << "-0b" << this->m_bitset_vec[iter2->first].to_string() << " - spt : " << iter2->second << endl;
        }
    }
    cout << "----------- this->m_itemset_confidence ------------" << endl;
    /*
     * typedef std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > Confidence_t;
     * typedef std::map<IndexBitSet_t,std::map<int,Confidence_t> > ItemsetConfidence_t;
     * */
    i = 0;
    for(auto iter = this->m_itemset_confidence.begin();
             iter!= this->m_itemset_confidence.end(); iter++){
        for(auto iter1 = iter->second.begin();
                 iter1!= iter->second.end(); iter1++){
            for(auto iter2 = iter1->second.begin();
                     iter2!= iter1->second.end(); iter2++){
                if(i > 10000) break;
                cout << "cfd-:A0b" << this->m_bitset_vec[iter2->first.first].to_string() << " i = " << i++ << endl;
                cout << "cfd :B0b" << this->m_bitset_vec[iter2->first.second].to_string()
                     << " - cfd : " << iter2->second << endl;
            }
        }
    }
#endif
}

void Apriori::get_rules(std::vector<std::tuple<std::bitset<NUM>,std::bitset<NUM>,float> > &r_rules_vector)
{
    /*
     * typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t;
     * typedef std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > Confidence_t;
     * typedef std::map<IndexBitSet_t,std::map<int,Confidence_t> > ItemsetConfidence_t;
     * ItemsetConfidence_t   m_itemset_confidence;  //可信度项集
     *
     * typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     * std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset;   //不含统计数据:float -> bitset
     * */

}

void Apriori::get_rules(std::vector<std::pair<std::pair<std::vector<float>,std::vector<float> >,float> > &r_rules_vector)
{
    std::vector<float> v1,v2;
    std::vector<IndexBitSet_t> vi;

    for(auto iter = this->m_itemset_confidence.begin();
             iter!= this->m_itemset_confidence.end(); iter++){
        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            for(auto iter3 = iter2->second.begin();
                     iter3!= iter2->second.end(); iter3++){
                v1.clear();v2.clear();
                vi.clear();
                this->confidence_get_unitbitset(this->m_bitset_vec[iter3->first.first],vi);
                for(auto iter = vi.begin();
                         iter!= vi.end(); iter++){
                    v1.push_back(this->m_data2bitset[*iter].second);
                }
                vi.clear();
                this->confidence_get_unitbitset(this->m_bitset_vec[iter3->first.second],vi);
                for(auto iter = vi.begin();
                         iter!= vi.end(); iter++){
                    v2.push_back(this->m_data2bitset[*iter].second);
                }

                r_rules_vector.push_back(std::make_pair(
                            std::make_pair(v1,v2),
                            iter3->second));
            }
        }
    }
}

void Apriori::get_rules(std::vector<std::tuple<std::vector<float>,std::vector<float>,float> > &r_rules_vector)
{
    std::vector<IndexBitSet_t> vi;
    std::tuple<std::vector<float>,std::vector<float>,float> t1;

    for(auto iter = this->m_itemset_confidence.begin();
             iter!= this->m_itemset_confidence.end(); iter++){
        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            for(auto iter3 = iter2->second.begin();
                     iter3!= iter2->second.end(); iter3++){
                std::get<0>(t1).clear();
                std::get<1>(t1).clear();
                vi.clear();
                this->confidence_get_unitbitset(this->m_bitset_vec[iter3->first.first],vi);
                for(auto iter = vi.begin();
                         iter!= vi.end(); iter++){
                    std::get<0>(t1).push_back(this->m_data2bitset[*iter].second);
                }
                vi.clear();
                this->confidence_get_unitbitset(this->m_bitset_vec[iter3->first.second],vi);
                for(auto iter = vi.begin();
                         iter!= vi.end(); iter++){
                    std::get<1>(t1).push_back(this->m_data2bitset[*iter].second);
                }
                std::get<2>(t1) = iter3->second;

                r_rules_vector.push_back(t1);
            }
        }
    }
}

void Apriori::set_minsupport(float minsupport)
{
    this->m_support = minsupport;
}

void Apriori::set_minconfidence(float minconfidence)
{
    this->m_confidence = minconfidence;
}

float Apriori::get_minsupport(void)
{
    return this->m_support;
}

float Apriori::get_minconfidence(void)
{
    return this->m_confidence;
}

/*if f1 == f2 ; then return true*/
bool Apriori::isequal(float f1,float f2) // equal return true
{
    return fabs(f1 - f2) < 0.000001f ? true : false ;
}

/*if val exist in this->m_itemset; return index; else return -1*/
int  Apriori::isexist(float val)
{
    /*
     * typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     * typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *
     * std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset
     * */
    int index = 0;
    for(auto iter = this->m_data2bitset.begin();
             iter!= this->m_data2bitset.end(); iter++,index++){
        if(this->isequal(val,iter->second.second)){
            return index;
        }
    }
    return -1;
}

/*get data2bitset*/
void Apriori::get_data2bitset(void)
{
    /*
     * std::map<unsigned ,std::vector<float> > OrigDataSet_t;
     *
     * typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     * typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *
     * std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset
     * */

    std::bitset<NUM> data_mapped("1");

    for(auto iter = this->m_orig_dataset.begin();
             iter!= this->m_orig_dataset.end(); iter++){

        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            if(this->isexist(*iter2) < 0){
                std::map<IndexBitSet_t,Data2Bit_t>::size_type index = this->m_data2bitset.size();

                this->m_bitset_vec.push_back(data_mapped << index);
                this->m_data2bitset.insert(
                            std::map<IndexBitSet_t,Data2Bit_t>::value_type(index,
                            std::make_pair(index,*iter2)));
            }
        }

    }
}

/*
 *  get base_dataset
 *  m_orig_dataset -> base_dataset
 *  <unsigned,vector> --> <unsigned, bitset>
 * */
void Apriori::get_base_dataset(void)
{
    /*
     * 1. std::map<unsigned ,std::vector<float> > OrigDataSet_t;
     *
     * 2. typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     *    typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *    std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset
     *
     * 3. std::map<unsigned ,IndexBitSet_t>   m_base_dataset;
     *    (data,vec float) -> (data,bitset)
     *
     * 4. std::vector<std::bitset<NUM> >   m_bitset_vec;  //位向量列表，用于临时存储位向量
     * */

    std::bitset<NUM> bittmp(0);

    for(unsigned i=0; i<this->m_orig_dataset.size(); i++){
        bittmp.reset();
        for(auto iter = this->m_orig_dataset[i].begin();
                 iter!= this->m_orig_dataset[i].end(); iter++){
            int index = this->isexist(*iter) ;
            if(index >= 0){
                bittmp |= this->m_bitset_vec[index];
            }
        }

        std::map<IndexBitSet_t,Data2Bit_t>::size_type index2 = this->m_bitset_vec.size();
        this->m_bitset_vec.push_back(bittmp);

        this->m_base_dataset.insert(std::make_pair(i,index2));
    }
}

/*get group itemset*/
void Apriori::get_group_itemset(void)
{
    /*
     * 1. typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     *    typedef std::pair<IndexBitSet_t,float> Data2Bit_t;
     *    std::map<IndexBitSet_t,Data2Bit_t>   m_data2bitset; //不含统计数据:float -> bitset
     *
     * 2. std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     *    typedef std::list<std::pair<IndexBitSet_t,float> > GroupItemSet_t;
     *
     * 3. std::map<int,GroupItemSet_t>  m_group_itemset;
     * */

    GroupItemSet_t gis_unit;
    std::bitset<NUM> bittmp(0);

    cout << "m_data2bitset size : " << this->m_data2bitset.size() << endl;
    for(unsigned long i=0; i<this->m_data2bitset.size(); i++){
        cout << " i = " << i << endl;
        gis_unit.clear();
        if(i == 0){
            /*init this->m_group_itemset*/
            for(auto iter = this->m_data2bitset.begin();
                     iter!= this->m_data2bitset.end(); iter++){
                float support = this->calc_support(this->m_bitset_vec[iter->first]);
                if(support > this->m_support){
                    gis_unit.push_back(std::make_pair(
                                iter->second.first,support));
                }
            }
            this->m_group_itemset.insert(std::make_pair(i+1,gis_unit));
        }else{
            bittmp.reset();
#if 0
            printf("m_group_itemset[%u] - size : %u\n" ,
                    (unsigned int)i,(unsigned int)this->m_group_itemset[i].size());
            printf("i = %d - size : %d\n" ,(int)i,(int)this->m_group_itemset.size());
            for(auto iter = this->m_group_itemset[i].begin();
                     iter!= this->m_group_itemset[i].end(); iter++){
                cout << "*0b" << this->m_bitset_vec[iter->first] << endl;
            }
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
#endif

            auto k_begin = this->m_group_itemset[i].begin(); k_begin++;
            auto j_iter = this->m_group_itemset[i].begin();
            /*
             * std::map<int,GroupItemSet_t>  m_group_itemset;
             * */
            for(unsigned long j = 0;
                    j < this->m_group_itemset[i].size()-1; j_iter++,j++,k_begin++){
                for(auto k_iter = k_begin;
                         k_iter!= this->m_group_itemset[i].end(); k_iter++){
                    bittmp.reset();
                    /*
                     * typedef std::list<std::pair<IndexBitSet_t,float> > GroupItemSet_t
                     * */
                    bittmp |= this->m_bitset_vec[j_iter->first];
                    bittmp |= this->m_bitset_vec[k_iter->first];
#if 0
                    cout << "&0b" << this->m_bitset_vec[j_iter->first].to_string() << "-"<< endl;
                    cout << "&0b" << this->m_bitset_vec[k_iter->first].to_string() << "-"<< endl;
#endif

                    /*
                     * std::vector<std::bitset<NUM> >  m_bitset_vec;
                     * 位向量列表，用于临时存储位向量
                     * */
                    if((bittmp.count() == i+1) && !(this->isexist(bittmp,gis_unit))){
                        this->m_bitset_vec.push_back(bittmp);
                        float support = this->calc_support(bittmp);
                        if(support > this->m_support){
                            gis_unit.push_back(std::make_pair(
                                        this->m_bitset_vec.size() - 1,support));
                        }
                    }
                }
            }

            if(gis_unit.size() == 0) break;
            this->m_group_itemset.insert(std::make_pair(i+1,gis_unit));
        }
    }
}

/*get itemset_confidence*/
void Apriori::get_itemset_confidence(void)
{
    /*
     * std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     * typedef std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > Confidence_t;
     * typedef std::map<IndexBitSet_t,std::map<int,Confidence_t> > ItemsetConfidence_t;
     *
     * ItemsetConfidence_t   m_itemset_confidence;  //可信度项集
     * */
    std::map<int,Confidence_t> icfd_unit;

    /*
     * 1. std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     *    typedef std::list<std::pair<IndexBitSet_t,float> > GroupItemSet_t;
     *
     * 2. std::map<int,GroupItemSet_t>  m_group_itemset;
     * */
    for(auto iter = this->m_group_itemset.begin();
             iter!= this->m_group_itemset.end(); iter++){
        for(auto iter2 = iter->second.begin();
                 iter2!= iter->second.end(); iter2++){
            if(iter->first > 1){
#if 0
                {
                    /*for test print*/
                    static int i = 0;
                    cout << "- " << i++;
                    cout << " - map[i] : " << iter->first ; 
                    cout << " - get_itemset_confidence..." << endl;
                    cout << "-0b" << this->m_bitset_vec[iter2->first].to_string() << "========" << endl;
                }
#endif
                icfd_unit.clear();

                this->confidence_iterator(
                        iter2->second,
                        this->m_bitset_vec[iter2->first],
                        icfd_unit);

                this->m_itemset_confidence.insert(std::make_pair(iter2->first,icfd_unit));
            }
        }
    }
}

void Apriori::confidence_iterator(
        float spt_AB,
        const std::bitset<NUM> &r_bsdata,
        std::map<int,Confidence_t> &r_unit)
{
    /*
     *  typedef std::vector<std::bitset<NUM> >::size_type IndexBitSet_t
     * */
    std::vector<IndexBitSet_t> unitbitset;
    this->confidence_get_unitbitset(r_bsdata,unitbitset);

    /*
     *  typedef std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > Confidence_t;
     * */
    Confidence_t cfd_unit;
    std::pair<std::bitset<NUM>,std::bitset<NUM> > bitpair(0x00,0x00);

#if 0
    {
        cout << "-0b" << r_bsdata.to_string() << " - ";
        cout << "unitbitset.size() : " << unitbitset.size() << endl;
        for(auto iter = unitbitset.begin();
                 iter!= unitbitset.end(); iter++){
            cout << "u0b" << this->m_bitset_vec[*iter].to_string() << endl;
        }
        cout << "---" << endl;
    }
#endif
    for(unsigned long i = 0; i<unitbitset.size(); i++){
        cfd_unit.clear();
        if(i == 0){
            /*init r_unit*/
            for(auto iter = unitbitset.begin();
                     iter!= unitbitset.end(); iter++){
                bitpair.first.reset();
                bitpair.second.reset();

                /*get antecedent
                 *(const std::bitset<NUM> &r_seccedent,const std::bitset<NUM> &r_bitset)
                 * */
                bitpair.first |= this->confidence_get_antecedent(
                        this->m_bitset_vec[*iter],
                        r_bsdata
                        );

                /*
                 * confidence (A => B)
                 * cofidence = support(AUB)/support(A)
                 * */
                float spt_ant = this->calc_support(bitpair.first);
                float confidence = spt_AB / spt_ant;
                if(this->isequal(spt_ant,0.0) == true) continue;

                bitpair.second |= this->m_bitset_vec[*iter];
                if(confidence > this->m_confidence){
                    /*
                     *typedef 
                     * std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> >
                     * Confidence_t;
                     * */
                    cfd_unit.push_back(std::make_pair(
                                std::make_pair(
                                    this->get_index(bitpair.first),
                                    this->get_index(bitpair.second))
                                ,confidence));
                }
            }
            r_unit.insert(std::make_pair(i+1,cfd_unit));
        }else{
            bitpair.first.reset();
            bitpair.second.reset();

            auto k_begin = r_unit[i].begin(); k_begin++;
            auto j_iter = r_unit[i].begin();
            /*
             * std::map<int,Confidence_t> &r_unit
             * */
            for(unsigned long j = 0;
                    j < r_unit[i].size()-1; j_iter++,j++,k_begin++){
                for(auto k_iter = k_begin;
                         k_iter!= r_unit[i].end(); k_iter++){
                    bitpair.first.reset();
                    bitpair.second.reset();
                    /*
                     *typedef 
                     * std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> >
                     * Confidence_t;
                     * */
                    bitpair.second |= this->m_bitset_vec[j_iter->first.second];
                    bitpair.second |= this->m_bitset_vec[k_iter->first.second];
#if 0
                    cout << "s0b" << bitpair.second.to_string() << endl;
                    cout << "|0b" << this->m_bitset_vec[j_iter->first.second].to_string() << endl;
                    cout << "|0b" << this->m_bitset_vec[k_iter->first.second].to_string() << endl;
#endif

                    /*get antecedent
                     *(const std::bitset<NUM> &r_seccedent,const std::bitset<NUM> &r_bitset)
                     * */
                    bitpair.first |= this->confidence_get_antecedent(
                            bitpair.second,
                            r_bsdata
                            );
                    //cout << "a0b" << bitpair.first.to_string() << endl;

                    /*
                     * std::vector<std::bitset<NUM> >  m_bitset_vec;
                     * 位向量列表，用于临时存储位向量
                     * */
                    if((bitpair.second.count() == i+1) && !(this->isexist(bitpair.second,cfd_unit))){
                        //this->m_bitset_vec.push_back(bittmp);
                        /*
                        * confidence (A => B)
                        * cofidence = support(AUB)/support(A)
                        * */
                        float spt_ant = this->calc_support(bitpair.first);
                        float confidence = spt_AB / spt_ant;
                        if(this->isequal(spt_ant,0.0) == true) continue;

                        if(confidence > this->m_confidence){
                            /*
                             *typedef 
                             * std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> >
                             * Confidence_t;
                             * */
                            cfd_unit.push_back(std::make_pair(
                                std::make_pair(
                                    this->get_index(bitpair.first),
                                    this->get_index(bitpair.second)),
                                confidence));
#if 0
                            {
                                cout << "A0b" << bitpair.first.to_string() << endl;
                                cout << "B0b" << bitpair.second.to_string() << " - cfd : " << confidence 
                                     << " - spt_AB : " << spt_AB << " - spt_ant " << spt_ant << endl;
                            }
#endif
                        }
                    }

                }
            }

            if(cfd_unit.size() == 0) break;
            r_unit.insert(std::make_pair(i+1,cfd_unit));
        }
    }
}

void Apriori::confidence_get_unitbitset(
        const std::bitset<NUM> &r_bsdata,
        std::vector<IndexBitSet_t> &r_unitbitset)
{
    std::bitset<NUM> b(0x01);
    int count = r_bsdata.count();
    r_unitbitset.clear();
    for(int i=0; i<NUM; i++){
        if((r_bsdata & b) == b ){
            r_unitbitset.push_back(this->get_index( b ));
            if(--count <= 0) break;
        }
        b <<= 1;
    }
}

std::bitset<NUM> Apriori::
confidence_get_antecedent(const std::bitset<NUM> &r_seccedent,const std::bitset<NUM> &r_bitset)
{
    std::bitset<NUM> b;
    b = ~(r_seccedent | ~r_bitset);
    return b;
}

/************************************************************************************************/

float Apriori::calc_support(std::bitset<NUM> bsdata)
{
    float support = 0.0;
    unsigned count = 0;
    std::bitset<NUM> b;
    /*
     * 1. std::map<unsigned ,IndexBitSet_t>   m_base_dataset;
     *    (data,vec float) -> (data,bitset)
     * */
    if(bsdata.none()) return 0.0;
    for(auto iter = this->m_base_dataset.begin();
             iter!= this->m_base_dataset.end(); iter++){
        b.reset();
        b |= (this->m_bitset_vec[iter->second] & bsdata) ^ bsdata;
        if(b.none()) count++;
    }
    support = (count*1.0) / (this->m_base_dataset.size() * 1.0);
    return support;
}

/*if r_set contian r_unit , return true ,else return false*/
bool Apriori::isexist(std::bitset<NUM> &r_unit,GroupItemSet_t &r_set)
{
    std::bitset<NUM> tmp;
    for(auto iter = r_set.begin();
             iter!= r_set.end(); iter++){
        tmp.reset();
        tmp |= r_unit ^ this->m_bitset_vec[iter->first];
        if(tmp.none()){
            return true;
        }
    }
    return false;
}

/*if r_set contian r_unit , return true ,else return false*/
bool Apriori::isexist(std::bitset<NUM> &r_unit,Confidence_t &r_set)
{
    /*
     * typedef 
     * std::list<std::pair<std::pair<IndexBitSet_t,IndexBitSet_t>,float> > 
     * Confidence_t;
     * */
    std::bitset<NUM> tmp;
    for(auto iter = r_set.begin();
             iter!= r_set.end(); iter++){
        tmp.reset();
        tmp |= r_unit ^ this->m_bitset_vec[iter->first.second];
        if(tmp.none()){
            return true;
        }
    }
    return false;
}

/*get index of m_bitset_vec; return index*/
Apriori::IndexBitSet_t Apriori::get_index(std::bitset<NUM> &r_bsdata)
{
    std::bitset<NUM> b;
    IndexBitSet_t index = 0;
    for(auto iter = this->m_bitset_vec.begin();
             iter!= this->m_bitset_vec.end(); iter++ ,index++){
        b.reset();
        b = r_bsdata ^ *iter;
        if(b.none()){
            return index;
        }
    }

    this->m_bitset_vec.push_back(r_bsdata);
    return this->m_bitset_vec.size() - 1;
}


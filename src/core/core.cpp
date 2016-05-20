/*
 * Progarm Name: core.cpp
 * Created Time: 2016-02-29 09:26:26
 * Last modified: 2016-04-13 22:13:01
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "core.h"
#include "feature_extraction.h"
#include "association.h"
#include <iostream>
#include <cstdio>
#include "cluster_dataset.h"
#include <vector>
#include <tuple>
#include "timer.h"
#include "sqlite3.h"
#include "json/json.h"

#include "apriori.h"
#include "combinmath.h"
#include "operate_test.h"
#include "database.h"


using namespace std;

/*size type print*/
static void sizetype_print(void);
static void rules_print(std::vector<std::tuple<std::vector<float>,std::vector<float>,float> > &r_rules_vector);

static float TestData[20][10] = 
{
    0.0001, 0.0002, 0.0003, 0.0004, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0001, 0.0002, 0.0013, 0.0004, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0011, 0.0002, 0.0013, 0.0004, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0011, 0.0002, 0.0013, 0.0004, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0011, 0.0012, 0.0013, 0.0014, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0011, 0.0012, 0.0013, 0.0014, 0.0015, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0101, 0.0012, 0.0013, 0.0014, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0101, 0.0012, 0.0013, 0.0014, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0101, 0.0012, 0.0013, 0.0014, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0101, 0.0012, 0.0013, 0.0034, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0101, 0.0012, 0.0013, 0.0034, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0401, 0.0012, 0.0023, 0.0034, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0401, 0.0302, 0.0023, 0.0034, 0.0025, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0401, 0.0302, 0.0023, 0.0034, 0.0035, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0401, 0.0302, 0.0023, 0.0034, 0.0035, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0081, 0.0302, 0.0033, 0.0034, 0.0035, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0081, 0.0302, 0.0033, 0.0034, 0.0035, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0081, 0.0302, 0.0043, 0.0054, 0.0045, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0081, 0.0302, 0.0043, 0.0054, 0.0045, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
    0.0081, 0.0302, 0.0053, 0.0054, 0.0055, 0.0006, 0.0007, 0.0008, 0.0009, 0.0010,
};

/*core*/
void core(void)
{
    cout << "core ..." << endl;
    sizetype_print();


    std::vector<float> dataset;
    Timer timer;
#if 0
    timer.timing();
    ClusterDataSet cds(dataset,100,4);
    //ClusterDataSet cds(3);
    //cds.get_dataset(dataset,1000000);
    timer.timing();
    cout << "dataset size :" << dataset.size() << endl;
#endif

#if 0
    double means = 0.0;
    unsigned int i=0;
    for(std::vector<float>::const_iterator iter_float = dataset.begin();
            iter_float!=dataset.end();iter_float++,i++){
        means += *iter_float ;
        if(i < 100){
            printf("%10f",*iter_float);
            if((++i + 1)%5 == 0)
                cout << endl;
        }
    }
    means /= dataset.size();
    cout << "means = " << means << endl;
#endif
    //-----------------------------------------------------
#if 0
    timer.timing();
    //KMeans kmeans(dataset,4);
    FeatureExtraction featureextra(dataset);
    timer.timing();
#endif

    //Apriori apriori(dataset);
#if 0
    Apriori apriori(TestData,20,10);

    timer.timing();
    apriori.calc_rules();
    timer.timing();

    std::vector<std::tuple<std::vector<float>,std::vector<float>,float> > rules;
    apriori.get_rules(rules);
    rules_print(rules);
#endif
#if 0
    Json::Reader reader;
    sqlite3 *db = NULL;
#endif

//    operate_test();

    void mdb_test(void);
    mdb_test();
}

/*size type print*/
void sizetype_print(void)
{
    cout << "----------- size type -----------" << endl;
    cout << "int : " << sizeof(int) << endl;
    cout << "unsigned : " << sizeof(unsigned) << endl;
    cout << "unsigned int : " << sizeof(unsigned int) << endl;
    cout << "unsigned short int : " << sizeof(unsigned short int) << endl;
    cout << "unsigned long int : " << sizeof(unsigned long int) << endl;
    cout << "unsigned long : " << sizeof(unsigned long) << endl;
    cout << "----------- size type -----------" << endl;
}

void rules_print(std::vector<std::tuple<std::vector<float>,std::vector<float>,float> > &r_rules_vector)
{
    cout << "rules print ..." << endl;
    unsigned i = 0;
    for(auto iter = r_rules_vector.begin();
             iter!= r_rules_vector.end(); iter++,i++){

        for(auto iter1 = get<0>(*iter).begin(), iter2 = get<1>(*iter).begin() ; ; ){
            if(iter1!= get<0>(*iter).end()){
                printf(" %.6f ",*iter1);
                iter1++;
            }
            if(iter2!= get<1>(*iter).end()){
                printf("  -  %.6f \n",*iter2);
                iter2++;
            }
            if((iter2 == get<1>(*iter).end()) && (iter2 == get<1>(*iter).end())){
                break;
            }
        }
        cout << "--------cfd : " << get<2>(*iter) << endl;
    }
}

void mdb_test(void)
{
    //mdbManager mdb("first.db");
    mdbManager mdb;

    mdb.open_db("second");

    mdb.set_dbpath("/home/minphone/space_sdc/workspace/dm_space/datamining-core/src/data/");
    mdb.open_db("first");

    string createTableSQL = 
        "create table testtable(int_col int,float_col real,string_col text)";

    mdb.create_table(createTableSQL);

    mdb.drop_table("drop table testtable");
}


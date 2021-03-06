/*
 * Progarm Name: data.cpp
 * Created Time: 2016-03-29 13:03:09
 * Last modified: 2016-04-12 22:58:51
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "data.h"
#include <iostream>

using namespace std;

/*
 * 原始的数据
 *
 *  A -> B
 *  ^    |
 *  |    V
 *  D <- C
 *
 *  A : 0x0001
 *  B : 0x0002
 *  C : 0x0003
 *  D : 0x0004
 *
 *  [A] -> [B]
 *   ^      |
 *   |      V
 *  [D] <- [C]
 *
 * */
const struct operate_data_orig origdata1[] = {
    /* date    time     nwk   ep  cluster*/
    {"3/12","6:30:12",0x0102,0x01,0x0001},  //0
    {"3/12","7:31:32",0x0102,0x01,0x0002},  //1
    {"3/12","6:31:32",0x0103,0x01,0x0012},  //2
    {"3/12","6:31:32",0x0102,0x01,0x0011},  //3
    {"3/12","6:31:32",0x0103,0x01,0x0002},  //4
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //5
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //6
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //7
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //8
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //9
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //10
    {"3/12","6:31:32",0x0102,0x01,0x0002},  //11
    /* date    time     nwk   ep  cluster*/
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},
    {"3/13","6:31:32",0x0102,0x01,0x0002},  //21
    /* date    time     nwk   ep  cluster*/
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},  //25
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},
    {"3/14","6:30:12",0x0102,0x01,0x0001},  //34
    /* date    time     nwk   ep  cluster*/
    {"3/15","6:30:12",0x0102,0x01,0x0001},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},  //40
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},
    {"3/15","6:31:32",0x0102,0x01,0x0002},  //46
    /* date    time     nwk   ep  cluster*/
    {"3/16","6:30:12",0x0102,0x01,0x0001},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},  //50
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},
    {"3/16","6:31:32",0x0102,0x01,0x0002},  //58
    /* date    time     nwk   ep  cluster*/
    {"3/17","6:30:12",0x0102,0x01,0x0001},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},
    {"3/17","6:31:32",0x0102,0x01,0x0002},  //70
    /* date    time     nwk   ep  cluster*/
    {"3/18","6:30:12",0x0102,0x01,0x0001},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
    {"3/18","6:31:32",0x0102,0x01,0x0002},
};

const struct operate_data_orig origdata2[] = {
    /* date    time     nwk   ep  cluster*/
    {"3/12","6:30:12",0x0102,0x01,0x0001},  //0
    {"3/12","6:30:15",0x0103,0x01,0x0005},  //0
    {"3/12","6:30:15",0x0104,0x01,0x0006},  //0
    {"3/12","6:30:15",0x0105,0x01,0x0010},  //0
    {"3/12","6:30:15",0x0106,0x01,0x0002},  //0

#if 0
    {"3/12","6:30:19",0x0107,0x01,0x0007},  //0
    {"3/12","6:30:19",0x0108,0x01,0x0011},  //0
    {"3/12","6:30:19",0x0109,0x01,0x0015},  //0
#endif

    {"3/12","6:30:19",0x0110,0x01,0x0003},  //0
    {"3/12","6:30:22",0x0103,0x01,0x0005},  //0
    {"3/12","6:30:22",0x0111,0x01,0x0009},  //0
    {"3/12","6:30:22",0x0105,0x01,0x0010},  //0
    {"3/12","6:30:22",0x0112,0x01,0x0014},  //0
    {"3/12","6:30:22",0x0113,0x01,0x0017},  //0
    {"3/12","6:30:22",0x0114,0x01,0x0020},  //0

#if 0
    {"3/12","6:30:23",0x0115,0x01,0x0004},  //0
    {"3/12","6:30:23",0x0107,0x01,0x0007},  //0
    {"3/12","6:30:23",0x0116,0x01,0x0018},  //0
    {"3/12","6:30:23",0x0117,0x01,0x0024},  //0
    {"3/12","6:30:23",0x0118,0x01,0x0008},  //0
    {"3/12","6:30:23",0x0109,0x01,0x0015},  //0
#endif

    //-----------------------------------------
    {"3/13","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/13","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/13","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/13","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/13","6:30:24",0x0106,0x01,0x0002},  //0

#if 0
    {"3/13","6:30:25",0x0107,0x01,0x0007},  //0
    {"3/13","6:30:25",0x0108,0x01,0x0011},  //0
    {"3/13","6:30:25",0x0109,0x01,0x0015},  //0

#endif
    {"3/13","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/13","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/13","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/13","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/13","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/13","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/13","6:30:27",0x0114,0x01,0x0020},  //0

    //-----------------------------------------
    {"3/14","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/14","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/14","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/14","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/14","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/14","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/14","6:30:27",0x0114,0x01,0x0020},  //0

    //-----------------------------------------
    {"3/15","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/15","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/15","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/15","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/15","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/15","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/15","6:30:27",0x0114,0x01,0x0020},  //0

    //-----------------------------------------
    {"3/16","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/16","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/16","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/16","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/16","6:30:24",0x0106,0x01,0x0002},  //0

    //-----------------------------------------
    {"3/17","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/17","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/17","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/17","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/17","6:30:24",0x0106,0x01,0x0002},  //0

    {"3/17","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/17","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/17","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/17","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/17","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/17","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/17","6:30:27",0x0114,0x01,0x0020},  //0

    //-----------------------------------------
    {"3/18","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/18","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/18","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/18","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/18","6:30:24",0x0106,0x01,0x0002},  //0

    //-----------------------------------------
    {"3/19","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/19","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/19","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/19","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/19","6:30:24",0x0106,0x01,0x0002},  //0

    {"3/19","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/19","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/19","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/19","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/19","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/19","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/19","6:30:27",0x0114,0x01,0x0020},  //0

    //-----------------------------------------
    {"3/20","6:30:21",0x0102,0x01,0x0001},  //0
    {"3/20","6:30:24",0x0103,0x01,0x0005},  //0
    {"3/20","6:30:24",0x0104,0x01,0x0006},  //0
    {"3/20","6:30:24",0x0105,0x01,0x0010},  //0
    {"3/20","6:30:24",0x0106,0x01,0x0002},  //0

    {"3/20","6:30:25",0x0110,0x01,0x0003},  //0
    {"3/20","6:30:27",0x0103,0x01,0x0005},  //0
    {"3/20","6:30:27",0x0111,0x01,0x0009},  //0
    {"3/20","6:30:27",0x0105,0x01,0x0010},  //0
    {"3/20","6:30:27",0x0112,0x01,0x0014},  //0
    {"3/20","6:30:27",0x0113,0x01,0x0017},  //0
    {"3/20","6:30:27",0x0114,0x01,0x0020},  //0

};

void orig_data_print(void)
{
    cout << "size : " << sizeof(origdata1)/sizeof(struct operate_data_orig) << endl;
    for(unsigned i=0; i<sizeof(origdata1)/sizeof(struct operate_data_orig); i++){
        cout << " " << origdata1[i].date;
        cout << " " << origdata1[i].time;
        printf(" 0x%.4x  0x%.2x  0x%.4x\n",
                origdata1[i].nwk,origdata1[i].ep,origdata1[i].clusterid);
    }
}


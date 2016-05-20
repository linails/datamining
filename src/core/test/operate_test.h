/*
 * Progarm Name: operate_test.h
 * Created Time: 2016-03-29 10:28:40
 * Last modified: 2016-03-30 16:29:29
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _OPERATE_TEST_H_
#define _OPERATE_TEST_H_

extern void operate_test(void);

/*
 * 经过一级加工的数据
 * */
struct operate_data1{
    unsigned        date;
    float           time;
    unsigned short  nwk;
    unsigned char   ep;
    unsigned short  clusterid;
};

/*
 * 经过二级加工可以使用的数据
 * */
struct operate_data2{
    unsigned        date;
    float           time;
    float           operate;
};

/*
 * nwk/ep/clusterid -> operate (float)
 * */
struct operate{
    float           operate;
    unsigned short  nwk;
    unsigned char   ep;
    unsigned short  clusterid;
};

typedef struct{
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char min;
    unsigned char sec;
}ExeTime_t;

extern void operate_map(struct operate_data_orig *pdata);

#endif //_OPERATE_TEST_H_


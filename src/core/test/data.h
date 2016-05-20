/*
 * Progarm Name: data.h
 * Created Time: 2016-03-29 13:03:14
 * Last modified: 2016-03-30 14:41:03
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _DATA_H_
#define _DATA_H_
#include "operate_test.h"

/*
 * 原始的数据
 * */
struct operate_data_orig{
    const char     *date;
    const char     *time;
    unsigned short  nwk;
    unsigned char   ep;
    unsigned short  clusterid;
};

extern const struct operate_data_orig origdata1[];
extern const struct operate_data_orig origdata2[];

extern void orig_data_print(void);

#endif //_DATA_H_


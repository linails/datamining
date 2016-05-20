/*
 * Progarm Name: operate_test.cpp
 * Created Time: 2016-03-29 10:28:35
 * Last modified: 2016-03-30 16:43:25
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "operate_test.h"
#include "data.h"


void operate_test(void)
{
    orig_data_print();
}


/**
  * 标准时间转换成浮点时间，12:03-->0.50208
  */
void StdTime2FltTime(float *pft,ExeTime_t *pet)
{
    unsigned seconds = 0;/*秒总数*/
	seconds = (pet->hour * 60 + pet->min) * 60 + pet->sec;
	*pft = (float)(seconds * 1.0 /86400.0);
}

/**
  * 浮点时间转换成标准时间，0.50208-->12:03
  */
void FltTime2StdTime(ExeTime_t *pet,float *pft)
{
	float	min_f=0.0f;
    unsigned short minutes = 0;
    unsigned char reminder;
	min_f = (float)(*pft * 1440.0);
	minutes = (unsigned short)min_f;
	reminder = (unsigned char)((min_f-(float)minutes)*10.0);
	if(reminder > 4) minutes++;
	pet->hour = minutes / 60;
	pet->min = minutes % 60;
}

void get_operate_map(struct operate_data_orig *pdata)
{
}



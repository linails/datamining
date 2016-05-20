/*
 * Progarm Name: combinmath.h for big number
 * Created Time: 2016-03-21 16:42:30
 * Last modified: 2016-03-23 21:01:15
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _COMBINMATH_H_
#define _COMBINMATH_H_
#include <vector>

/*
 * CombinMath for big number
 *
 * std::vector<unsigned char> 
 *   eg.[0x01,0x03] = 0x0103
 *      [0x01,0x03,0x45,0xfe,0x89] = 0x010345fe89
 * */
class CombinMath{
public:
    CombinMath();
    ~CombinMath();
    std::vector<unsigned char> combin_calc(unsigned Cm,unsigned Cn);
private:
    typedef std::vector<unsigned char> exInt_t;
    exInt_t factorial(const exInt_t &n);
    exInt_t factorial(unsigned un);
    exInt_t plus(const exInt_t &n1,const exInt_t &n2);      //n1+n2
    exInt_t plus(const exInt_t &n1,unsigned char cn2);      //n1+n2
    exInt_t minus(const exInt_t &n1,const exInt_t &n2);     //n1-n2
    exInt_t minus(const exInt_t &n1,unsigned char cn2);     //n1-n2
    exInt_t multiply(const exInt_t &n1,const exInt_t &n2);  //n1*n2
    exInt_t multiply(unsigned un1,const exInt_t &n2);       //n1*n2
    exInt_t multiply(const exInt_t &n1,unsigned un2);       //n1*n2
    exInt_t multiply(unsigned un1,unsigned un2);            //n1*n2
    exInt_t divide(const exInt_t &n1,const exInt_t &n2);    //n1/n2
    exInt_t subfactorial(const exInt_t &n);
    exInt_t subplus(const exInt_t &n1,const exInt_t &n2);       //n1+n2
    exInt_t subminus(const exInt_t &n1,const exInt_t &n2);      //n1-n2
    exInt_t submultiply(const exInt_t &n1,const exInt_t &n2);   //n1*n2
    bool iszero(const exInt_t &n);
    void test(void);
};

#endif //_COMBINMATH_H_


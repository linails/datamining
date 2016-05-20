/*
 * Progarm Name: combinmath.cpp
 * Created Time: 2016-03-21 16:42:25
 * Last modified: 2016-03-24 13:24:08
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "combinmath.h"
#include <iostream>
#include <cstdio>
#include <vector>
#include "timer.h"

using std::cout;
using std::endl;

CombinMath::CombinMath()
{
#if 1
    this->test();
#endif
}

void CombinMath::test(void)
{
    Timer timer;
    std::vector<unsigned char> n1;
    std::vector<unsigned char> n2;
    std::vector<unsigned char> ans;

    n2.push_back(0xff);
    n1.push_back(0x02);
    n1.push_back(0x01);
    n1.push_back(0x01);

    ans = this->plus(n1,n2);

    cout << "plus" << endl;
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    //--------------------------------

    n1.clear();
    n2.clear();

    n1.push_back(0x01);
    n2.push_back(0x01);
    n2.push_back(0x01);
    ans = this->plus(n1,n2);

    cout << "plus" << endl;
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    cout << "minus " << endl;
    n1.clear();
    n2.clear();

    n1.push_back(0x11);
    n1.push_back(0x01);
    n2.push_back(0x12);
    ans = this->minus(n1,n2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    n1.clear();
    if(this->iszero(n1)){
        cout << "zero" << endl;
    }else{
        cout << "is not zero" << endl;
    }

    //--------------------------------

    n1.clear();
    n2.clear();

    n1.push_back(0x00);
    n1.push_back(0x00);
    n1.push_back(0x01);
    n2.push_back(0x01);
    ans = this->minus(n1,n2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    cout << "-------------------------" << endl;
#if 0
    n1.clear();
    n2.clear();

    n1.push_back(0x05);
    n1.push_back(0x40);
    n1.push_back(0x01);
    n2.push_back(0x01);

    do{
        n1 = this->minus(n1,n2);

        cout << "n1 = 0x";
        for(auto iter = n1.rbegin();
                iter!= n1.rend(); iter++){
            printf("%.2x",*iter);
        }
        cout << endl;

    }while(!this->iszero(n1));
#endif

    cout << "-------------------------" << endl;
    //--------------------------------
    
#if 0
    cout << "multiply" << endl;
    n1.clear();
    n2.clear();
    
    n1.push_back(0x34);
    n1.push_back(0x34);
    n1.push_back(0x01);
    n1.push_back(0x01);
    n2.push_back(0x42);
    n2.push_back(0x42);
    ans = this->multiply(n1,n2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
#if 0
    n1.clear();

    n1.push_back(0x34);
    n1.push_back(0x34);
    n1.push_back(0x01);
    n1.push_back(0x01);
    unsigned un2 = 0x4242;
    ans = this->multiply(n1,un2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    unsigned un1 = 0x01013434;
    ans = this->multiply(un1,n2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    ans = this->multiply(un1,un2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
    cout << "-------------------------" << endl;
#if 1
    n1.clear();
    
    n1.push_back(0x32);
    //n1.push_back(0x16);
    ans = this->factorial(n1);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    ans = this->factorial(0x32);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    timer.timing();
    ans = this->factorial(800);
    timer.timing();
    timer.timing();
    exInt_t ans1 = this->factorial(100);
    timer.timing();
    timer.timing();
    ans = this->divide(ans,ans1);
    timer.timing();
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
    cout << "-------------------------" << endl;
#if 0
    ans.clear();
    n1.clear();
    n1.push_back(0x16);
    ans.push_back(0x00);
    ans.push_back(0x00);
    ans.push_back(0xc4);
    ans.push_back(0xb8);
    ans.push_back(0x36);
    ans.push_back(0x7d);
    ans.push_back(0x07);
    ans.push_back(0xc5);
    ans.push_back(0x02);

    ans = this->multiply(ans,n1);
    //ans = this->multiply(n1,ans);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
    //---------------------------
    n1.clear();
    n1.push_back(0x17);
    ans = this->multiply(ans,n1);
    //ans = this->multiply(n1,ans);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
    //---------------------------
    n1.clear();
    n1.push_back(0x18);
    ans = this->multiply(ans,n1);
    //ans = this->multiply(n1,ans);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
#if 0
    n1.clear();
    n2.clear();
    n1.push_back(0x64);
    n1.push_back(0x19);

    n2.push_back(0x34);

    ans = this->divide(n1,n2);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
#if 0
    cout << "------combin_calc------" << endl;
    //ans = this->combin_calc(3,7);
# if 1
    ans = this->combin_calc(4,8);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
# endif
    timer.timing();
    ans = this->combin_calc(3,7);
    timer.timing();
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    cout << "C30,50 :" << endl;
    timer.timing();
    ans = this->combin_calc(30,50);
    timer.timing();
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;

    cout << "C100,800 :" << endl;
    timer.timing();
    ans = this->combin_calc(100,800);
    timer.timing();
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
#if 0
    cout << "---------------- 0x2a * 6 --------------" << endl;
    ans = this->multiply(0x2a,6);
    cout << "ans = 0x";
    for(auto iter = ans.rbegin();
             iter!= ans.rend(); iter++){
        printf("%.2x",*iter);
    }
    cout << endl;
#endif
}

CombinMath::~CombinMath()
{
}

std::vector<unsigned char> CombinMath::combin_calc(unsigned Cm,unsigned Cn)
{ 
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
#if 0
    exInt_t exans;
    exans.push_back(0x00);

    unsigned n = Cn;

    cout << "n = " << n << endl;
    exans = this->multiply(n,--n);

    //=========================================
    while(n != (Cm+1)){
        cout << "n = " << n << endl;
        exans = this->multiply(exans,--n);

#if 0
        cout << "exans = 0x";
        for(auto iter = exans.rbegin();
                 iter!= exans.rend(); iter++){
            printf("%.2x",*iter);
        }
        cout << endl;
#endif
    }
    //=========================================
        cout << "exans = 0x";
        for(auto iter = exans.rbegin();
                 iter!= exans.rend(); iter++){
            printf("%.2x",*iter);
        }
        cout << endl;


    exans = this->divide(exans,this->factorial(Cn - Cm));

    return exans;
#else
    return  this->divide(
            this->factorial(Cn),
            this->multiply(this->factorial(Cm),this->factorial(Cn - Cm)));
#endif
}

CombinMath::exInt_t CombinMath::factorial(const exInt_t &n)
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    return this->subfactorial(n);
}

CombinMath::exInt_t CombinMath::factorial(unsigned un)
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n;

    for(int i=0; i<4; i++){
        if((un >> (8*i)) & 0x000000ff){
            n.push_back((un >> (8*i)) & 0x000000ff);
        }
    }

    return this->subfactorial(n);
}

CombinMath::exInt_t CombinMath::subfactorial(const exInt_t &n)
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
#if 1
    exInt_t exans;
    exans.push_back(0x00);

    if(!this->iszero(n)){
        exans = this->multiply(n,this->factorial(this->minus(n,0x01)));
    }
    if(this->iszero(exans)) exans[0] = 0x01;

    return exans;
#else
    exInt_t exans;


    return exans;
#endif
}

CombinMath::exInt_t CombinMath::plus(const exInt_t &n1,const exInt_t &n2)      //n1+n2
{ 
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    return this->subplus(n1,n2);
}

CombinMath::exInt_t CombinMath::plus(const exInt_t &n1,unsigned char cn2)      //n1+n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n2;
    n2.push_back(cn2);

    return this->subplus(n1,n2);
}

CombinMath::exInt_t CombinMath::subplus(const exInt_t &n1,const exInt_t &n2)   //n1+n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    std::vector<unsigned char>::const_iterator iter1 = n1.size() >= n2.size() ? n1.begin() : n2.begin();
    std::vector<unsigned char>::const_iterator iter2 = n1.size() >= n2.size() ? n2.begin() : n1.begin();
    std::vector<unsigned char>::const_iterator end1 = n1.size() >= n2.size() ? n1.end() : n2.end();
    std::vector<unsigned char>::const_iterator end2 = n1.size() >= n2.size() ? n2.end() : n1.end();

    exInt_t exans;

    for(unsigned i=0; iter1 != end1; iter1++,i++){
        if(iter2 != end2){

            if(exans.size() == i){
                unsigned short int ans = *iter1 + *iter2;
                exans.push_back(ans & 0x00ff);
                if(ans & 0xff00){
                    exans.push_back((ans >>= 8 & 0x00ff));
                }
            }else{
                unsigned short int ans = *iter1 + *iter2 + exans[i];
                exans[i] = ans & 0x00ff;
                if(ans & 0xff00){
                    exans.push_back((ans >>= 8 & 0x00ff));
                }
            }

            iter2++;
        }else{
            if(exans.size() == i){
                exans.push_back(*iter1);
            }else{
                unsigned short int ans = *iter1 + exans[i];
                exans[i] = ans & 0x00ff;
                if(ans & 0xff00){
                    exans.push_back((ans >>= 8 & 0x00ff));
                }
            }
        }
    }
    
    return exans;
}

CombinMath::exInt_t CombinMath::minus(const exInt_t &n1,const exInt_t &n2)     //n1-n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    return this->subminus(n1,n2);
}

CombinMath::exInt_t CombinMath::minus(const exInt_t &n1,unsigned char cn2)     //n1-n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n2;
    n2.push_back(cn2);

    return this->subminus(n1,n2);
}

CombinMath::exInt_t CombinMath::subminus(const exInt_t &n1,const exInt_t &n2)  //n1-n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    std::vector<unsigned char>::const_iterator iter1 = n1.size() >= n2.size() ? n1.begin() : n2.begin();
    std::vector<unsigned char>::const_iterator iter2 = n1.size() >= n2.size() ? n2.begin() : n1.begin();
    std::vector<unsigned char>::const_iterator end1 = n1.size() >= n2.size() ? n1.end() : n2.end();
    std::vector<unsigned char>::const_iterator end2 = n1.size() >= n2.size() ? n2.end() : n1.end();

    exInt_t exans;

    char carry = 0;

    for(int i=0; iter1 != end1; iter1++,i++){
        if(iter2 != end2){

            if((*iter1 - *iter2 + carry) >= 0){
                unsigned char ans = *iter1 - *iter2 + carry;
                exans.push_back(ans);
                carry = 0;
            }else{
                carry = -1;
                unsigned char ans = 0xff - *iter2 + *iter1 +1;
                exans.push_back(ans);
            }

            iter2++;
        }else{
            if(carry < 0){
                if(*iter1 + carry >= 0){
                    unsigned char ans = *iter1 + carry;
                    exans.push_back(ans);
                    carry = 0;
                }else{
                    carry = -1;
                    unsigned char ans =0xff - *iter1;
                    exans.push_back(ans);
                }
            }else{
                exans.push_back(*iter1);
            }
        }
    }

    return exans;
}

CombinMath::exInt_t CombinMath::multiply(const exInt_t &n1,const exInt_t &n2)  //n1*n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    return this->submultiply(n1,n2);
}

CombinMath::exInt_t CombinMath::multiply(unsigned un1,const exInt_t &n2)       //n1*n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n1;

    for(int i=0; i<4; i++){
        if((un1 >> (8*i)) & 0x000000ff){
            n1.push_back((un1 >> (8*i)) & 0x000000ff);
        }else{
            break;
        }
    }

    return this->submultiply(n1,n2);
}

CombinMath::exInt_t CombinMath::multiply(const exInt_t &n1,unsigned un2)       //n1*n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n2;

    for(int i=0; i<4; i++){
        if((un2 >> (8*i)) & 0x000000ff){
            n2.push_back((un2 >> (8*i)) & 0x000000ff);
        }else{
            break;
        }
    }

    return this->submultiply(n1,n2);
}

CombinMath::exInt_t CombinMath::multiply(unsigned un1,unsigned un2)            //n1*n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
    exInt_t n1;
    exInt_t n2;

    for(int i=0; i<4; i++){
        if((un1 >> (8*i)) & 0x000000ff){
            n1.push_back((un1 >> (8*i)) & 0x000000ff);
        }
        if((un2 >> (8*i)) & 0x000000ff){
            n2.push_back((un2 >> (8*i)) & 0x000000ff);
        }
    }

    return this->submultiply(n1,n2);
}

CombinMath::exInt_t CombinMath::submultiply(const exInt_t &n1,const exInt_t &n2)   //n1*n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
#if 1
    exInt_t tmp  = n1.size() >= n2.size() ? n2 : n1;
    exInt_t exn2 = n1.size() >= n2.size() ? n1 : n2;

    exInt_t exans;
    exInt_t minuend;
    exans.push_back(0x00);
    minuend.push_back(0x01);

    bool flag = false;
    do{
        flag = this->iszero(tmp);
        if(!flag){
            exans = this->plus(exans,exn2);
        }
        tmp = this->minus(tmp,minuend);
#if 0
        cout << "tmp = 0x";
        for(auto iter = tmp.rbegin();
                 iter!= tmp.rend(); iter++){
            printf("%.2x",*iter);
        }
        cout << endl;
#endif
    }while(!flag);

    return exans;
#else
    exInt_t exans;


    return exans;
#endif
}

/*暂时仅针对整除*/
CombinMath::exInt_t CombinMath::divide(const exInt_t &n1,const exInt_t &n2)    //n1/n2
{
    /*
     * typedef std::vector<unsigned char>  exInt_t;
     * */
#if 1
    exInt_t exans;
    exInt_t tmp = n1;
    exans.push_back(0x00);

    do{
        tmp = this->minus(tmp,n2);
        exans = this->plus(exans,0x01);
#if 0
        cout << "tmp = 0x";
        for(auto iter = tmp.rbegin();
                 iter!= tmp.rend(); iter++){
            printf("%.2x",*iter);
        }
        cout << endl;
#endif
    }while(!this->iszero(tmp));

    return exans;
#else
    exInt_t exans;
    return exans;
#endif
}

/*zero return true*/
bool CombinMath::iszero(const exInt_t &n)
{
    for(auto iter = n.begin(); 
             iter!= n.end(); iter++){
        if(*iter) return false;
    }
    return true;
}


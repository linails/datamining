/*
 * Progarm Name: database.cpp
 * Created Time: 2015-12-26 20:50:54
 * Last modified: 2016-04-30 11:14:11
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#include "database.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>

using std::cout;
using std::endl;
using std::string;

/*default constructor*/
mdbManager::mdbManager(void)
{
}

/*constructor*/
mdbManager::mdbManager(string dbname)
{
    this->m_dbname  =  dbname;

    /*append '.db'*/
    if(this->m_dbname.rfind(".") == string::npos){
        this->m_dbname  +=  ".db";
    }
}

/*default destructor*/
mdbManager::~mdbManager(void)
{
    sqlite3_close(this->m_conn);
}

bool    mdbManager::set_dbpath(std::string path)
{
    this->m_path = path;

    if(this->m_path[this->m_path.size() - 1] == '/'){
        this->m_path  =  this->m_path.substr(0,this->m_path.size() - 1);
    }

    return true;
}

bool    mdbManager::open_db(std::string dbname)
{
    if(this->m_conn != NULL){
        sqlite3_close(this->m_conn);
    }

    this->m_dbname  =   dbname;

    /*append '.db'*/
    if(this->m_dbname.rfind(".") == string::npos){
        this->m_dbname  +=  ".db";
    }

    int result      =   0;

    if(this->m_path.empty()){
        /*in current path create db |(程序运行目录)*/
        result      =   sqlite3_open(this->m_dbname.c_str(),&this->m_conn);
    }else{
        string  dbn =   this->m_path + "/" + this->m_dbname;
        result      =   sqlite3_open(dbn.c_str(),&this->m_conn);
    }

    printf("&this->m_conn : 0x%.16x\n",this->m_conn);

    if(result != SQLITE_OK){
        sqlite3_close(this->m_conn);
        return false;
    }else{
        return true;
    }
}

bool    mdbManager::create_table(std::string sql)
{
    int len = sql.length();
    sqlite3_stmt *stmt = NULL;

    if(this->m_conn != NULL){
        if(sqlite3_prepare_v2(this->m_conn,sql.c_str(),len,&stmt,NULL) != SQLITE_OK){
            if(stmt){
                sqlite3_finalize(stmt);
            }
            return false;
        }

        if(sqlite3_step(stmt) != SQLITE_DONE){
            sqlite3_finalize(stmt);
            return false;
        }

        sqlite3_finalize(stmt);

        return true;
    }else{
        return false;
    }
}

bool    mdbManager::drop_table(std::string sql)
{
    sqlite3_stmt *stmt3 = NULL;

    if(this->m_conn != NULL){
        if(sqlite3_prepare_v2(this->m_conn,sql.c_str(),sql.length(),&stmt3,NULL) != SQLITE_OK){
            if(stmt3)
                sqlite3_finalize(stmt3);
            return false;
        }
        if(sqlite3_step(stmt3) == SQLITE_DONE){
            cout<<"The test table has been dropped."<<endl;
        }
        sqlite3_finalize(stmt3);
        return true;
    }else{
        return false;
    }
}









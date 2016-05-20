/*
 * Progarm Name: database.h
 * Created Time: 2015-12-26 20:50:59
 * Last modified: 2016-04-30 11:32:30
 * @author: minphone.linails linails@foxmail.com 
 * @version 0.0.1
 */

#ifndef _DATABASE_H_
#define _DATABASE_H_
#include <string>
#include <map>
#include <vector>
#include "sqlite3.h"

/*meta info database manager class*/
class mdbManager{
public:
    mdbManager(void);
    mdbManager(std::string dbname);
    ~mdbManager(void);

    bool  set_dbpath(std::string path);
    bool  open_db(std::string dbname);
    bool  create_table(std::string sql);
    bool  drop_table(std::string sql);

    bool  add(void);
    bool  del(void);
    bool  search(void);
    bool  update(void);
private:
    sqlite3     *m_conn     = NULL;
    std::string m_path;
    std::string m_dbname    = "test.db";
};

#endif //_DATABASE_H_


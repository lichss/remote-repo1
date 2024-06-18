#ifndef _WORKERS_H__
#define _WORKERS_H__

#include <string>

class Worker_base
{
friend void test_read_c(Worker_base workers[]);
public:
    Worker_base();
    Worker_base(int index,const char* name,int id);

    virtual void edit(int index,const char* new_name,int new_id);
    virtual void show();
    virtual int job_id();
    virtual void save(const char* path);
    virtual std::string ret_Function(){
        return "Error";
    };
    
    void read(const char* path);
    
public:
    int m_Index_n;
    std::string m_Name;
    int m_Job_id;

};



#endif


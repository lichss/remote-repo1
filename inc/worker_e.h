#ifndef __WORKER_EMPLOYEE_H__
#define __WORKER_EMPLOYEE_H__

#include <string>
#include "worker.h"

class Worker_e:public Worker_base
{
public:
    Worker_e(int index,std::string name,int id );
    void save(const char*);
    void show();
    std::string ret_Function();
    
    std::string m_Function;
};

#endif

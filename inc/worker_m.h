#ifndef __MANAGER_H__
#define __MANAGER_H__
#include <string>
#include "worker.h"

class Worker_m:public Worker_base
{
public:
    Worker_m(int index,std::string name,int id );
    void save(const char*);
    void show();
    std::string ret_Function();
    
    std::string m_Function;
};

#endif

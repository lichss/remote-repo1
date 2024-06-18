#ifndef __WORKER_BOSS_H__
#define __WORKER_BOSS_H__

#include <string>
#include "worker.h"

class Worker_b:public Worker_base
{
public:
    Worker_b(int index,std::string name,int id );
    void save(const char*);
    void show();
    std::string ret_Function();
    std::string m_Function;
};

#endif

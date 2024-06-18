#include <iostream>
#include <fstream>
#include <string>

#include "worker_m.h"

Worker_m::Worker_m(int index,std::string name,int id)
{
    this->m_Index_n = index;
    this->m_Name = name;
    this->m_Job_id = id;
    this->m_Function = "jingli";
}

void Worker_m::save(const char* path)
{
    std::ofstream ofs;
    ofs.open(path,std::ios::binary|std::ios::out|std::ios::app);
    if(!ofs.is_open()){
        std::cerr << "Error open file:"<<path<<std::endl;
        return;
    }

    ofs << this->m_Index_n<<'\t';
    ofs << this->m_Name << '\t';
    ofs << this->m_Job_id << '\t';
    ofs << this->m_Function <<'\t';
    ofs << '\n';

    ofs.close();
    
}

std::string Worker_m::ret_Function()
{
    return this->m_Function;
}

void Worker_m::show()
{

}

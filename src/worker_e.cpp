#include <iostream>
#include <fstream>
#include <string>

#include "Worker_e.h"

Worker_e::Worker_e(int index,std::string name,int id)
{
    this->m_Index_n = index;
    this->m_Name = name;
    this->m_Job_id = id;
    this->m_Function = "yuangong";
}

void Worker_e::save(const char* path)
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

std::string Worker_e::ret_Function()
{
    return this->m_Function;
}

void Worker_e::show()
{

}

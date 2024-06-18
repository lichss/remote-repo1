#include <iostream>
#include <string>
#include <fstream>

#include "worker.h"

Worker_base::Worker_base()
{
}

Worker_base::Worker_base(int index,const char* name,int id)
{
    m_Index_n = index;
    m_Name = name;
    m_Job_id = id;
}

void Worker_base::edit(int index,const char* new_name,int new_id)
{
    m_Name = new_name;
    std::cout << "new name:"<<new_name;
    m_Job_id = new_id;
    std::cout << "new ID:"<<new_id;
}

void Worker_base::show()
{
    std::cout << "worker name:"<<m_Name<<std::endl;
    std::cout << "worker ID:"<<m_Job_id<<std::endl;
}

void Worker_base::save(const char* path)
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
    ofs << '\n';

    ofs.close();
    

}
void Worker_base::read(const char* path)
{
    std::ifstream ifs;
    ifs.open(path,std::ios::in|std::ios::binary);
    if(!ifs.is_open()){
        std::cerr << "Error open file:"<<path<<std::endl;
        return;
    }
    Worker_base w;
    ifs.read((char*)this,sizeof(Worker_base));
    std::cout<<"read complete.\n";

    //w.show();
    ifs.close();
}

int Worker_base::job_id()
{
    return m_Job_id;
}
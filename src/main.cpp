#include <iostream>
#include <fstream>
#include <string>

#include "worker.h"
#include "worker_m.h"
#include "worker_e.h"
#include "worker_b.h"


int g_workers_index=0;
const char* path = "files\\records";


void menu();
void list_workers(Worker_base* workers[]);
void sort_workers(Worker_base* workers[]);

int testwrite()
{
    Worker_e w1 = {1,"AAA",23,};
    w1.show();
    w1.save(path);

    Worker_m w2 = {2,"BBB",484};
    w2.show();
    w2.save(path);
    
    Worker_b w3 = {3,"CCC",3};
    w3.show();
    w3.save(path);

    std::cout <<"save down\n";
    return 0;
}
void add_worker(Worker_base *workers[], int index, std::string name, int id)
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    string function = "yuangong";

    if (function == "yuangong"){
        workers[g_workers_index] = new Worker_e(index, name, id);
        g_workers_index++;

        std::cout << id << "\tread\t" << function << std::endl;
    }

    else if (function == "jingli"){
        workers[g_workers_index] = new Worker_m(index, name, id);
        g_workers_index++;

        std::cout << id << "\tread\t" << function << std::endl;
    }

    else if (function == "Boss"){
        workers[g_workers_index] = new Worker_b(index, name, id);
        g_workers_index++;

        std::cout << id << "\tread\t" << function << std::endl;
    }
}

void delete_worker(Worker_base* workers[],int delete_index)
{
    for(int i=0;i<g_workers_index;i++){ /*遍历指针组查找删除目标*/
        if(workers[i]!=nullptr){    /*排除已删除目标*/
            if(workers[i]->m_Index_n == delete_index){  /*第一个符合删除索引的目标*/
                delete workers[i];
                workers[i] = nullptr;
                std::cout<<"index "<<delete_index<<" deleted\n";
            }
        else
            continue;
        }
    }

}
void init_record()
{
    std::ofstream ofs;
   
    ofs.open(path,std::ios::out|std::ios::trunc);
    if(ofs.is_open())
        std::cout<<"init records file.\n";
    else
        std::cerr << "Error writing to file." << std::endl;
    ofs.close();

}


void test_read_c(Worker_base* workers[])
{

    std::ifstream ifs;
    ifs.open(path,std::ios::in|std::ios::binary);
    if(ifs.is_open())
        std::cout<<"open file\n";
    else {
        std::cerr << "Error open file:"<<path<<std::endl;
        return;
    }
    int index;
    int id;
    std::string name;
    std::string function;
    
    while(ifs>>index&& ifs>>name && ifs>>id && ifs>>function)
    {   
        if     (function == "yuangong"){
            workers[g_workers_index] = new Worker_e(index,name,id);
            g_workers_index++;

            std::cout<<id<<"\tread\t"<<function<<std::endl;

        }

        else if (function == "jingli"){
            workers[g_workers_index] = new Worker_m(index,name,id);
            g_workers_index++;

            std::cout<<id<<"\tread\t"<<function<<std::endl;
        }

        else if (function == "Boss"){
            workers[g_workers_index] = new Worker_b(index,name,id);
            g_workers_index++;

            std::cout<<id<<"\tread\t"<<function<<std::endl;

        }
        
    }
    std::cout << "\n----read over "<<g_workers_index<<" workers.\n";
}


int main()
{
    // menu();
    // char c = '\0';
    // while(std::cin>>c){
    //     std::cout<<"get:"<<c<<"\n";

    // }
    // init_record();

    Worker_base* workers[99] = {0,};

    // testwrite();
    test_read_c(workers);
    add_worker(workers,14,"DDD",936);
    
    
    // delete_worker(workers,2);
    // delete_worker(workers,5);
    // delete_worker(workers,11);

    
    list_workers(workers);
    sort_workers(workers);
    std::cout<<"\n\nsort\n";
    list_workers(workers);

    return 0;
}

void list_workers(Worker_base* workers[])
{
    using std::cout;
    using std::endl;
    for(int i=0;i<g_workers_index;i++){
        if(workers[i] != nullptr){
            cout<<workers[i]->m_Index_n<<'\t';
            cout<<workers[i]->m_Name<<'\t';
            cout<<workers[i]->m_Job_id<<'\t';

            cout<<workers[i]->ret_Function()<<endl;
        }

    }

}
void menu()
{
    
    using std::cout;
    cout << "********************************************\n";
    cout << "******0 退出系统*****************************\n";
    cout << "******1增加职工信息**************************\n";
    cout << "******2显示职工信息**************************\n";
    cout << "******3删除职工信息**************************\n";
    cout << "******4修改职工信息**************************\n";
    cout << "******5查找职工信息**************************\n";
    cout << "******6按照编号排序**************************\n";
    cout << "******7清空文档记录**************************\n";
    cout << "*******************************************\n";

    return;
}

void sort_workers(Worker_base* workers[])
{
    g_workers_index;
    Worker_base * wptr_temp;
    int sordex_i;
    int sordex_i_last = 0;
    int sordex_temp;

    int index_i;
    int index_i_last = 0;

    for (int j=0;j<g_workers_index;j++){
        for(int i=j;i<g_workers_index;i++){
            if(workers[i]!=nullptr){
                index_i_last = index_i;
                index_i = i;
                
                sordex_i_last = sordex_i;
                sordex_i = workers[i]->m_Index_n;
                if(sordex_i < sordex_i_last){   /*有效顺序中出现逆序*/
                    wptr_temp = workers[index_i];    /*交换有效顺序位置*/
                    workers[index_i] = workers[index_i_last];
                    workers[index_i_last] = wptr_temp;

                    sordex_temp = sordex_i;
                    sordex_i = sordex_i_last;
                    sordex_i_last = sordex_temp;
                }
            else{
                continue;
                }

            
            }
            //
            
            index_i = j;
            index_i_last = index_i;
            sordex_i = 0;
            sordex_i_last = 0;
        }
    }
}
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
void edit_workers(Worker_base* workers[]);

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
void add_workers(Worker_base *workers[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    int index;
    string name;
    int id;
    string function = "yuangong";

    cout << "enter add mode.\n";
    cout << "new index:_____\b\b\b";
    cin >> index;
    cout << "new name:_____\b\b\b";
    cin >> name;
    cout << "new id:_____\b\b\b";
    cin >> id;
    cout << "new function:_____\b\b\b";
    cin >> function;


    

    if (function == "yuangong"){
        workers[g_workers_index] = new Worker_e(index, name, id);
        g_workers_index++;

        std::cout << id << "\tcreat\t" << function << std::endl;
    }

    else if (function == "jingli"){
        workers[g_workers_index] = new Worker_m(index, name, id);
        g_workers_index++;

        std::cout << id << "\tcreat\t" << function << std::endl;
    }

    else if (function == "Boss"){
        workers[g_workers_index] = new Worker_b(index, name, id);
        g_workers_index++;

        std::cout << id << "\tcreat\t" << function << std::endl;
    }
}

void delete_workers(Worker_base* workers[],int delete_index)
{
    for(int i=0;i<g_workers_index;i++){ /*遍历指针组查找删除目标*/
        if(workers[i]!=nullptr){    /*排除已删除目标*/
            if(workers[i]->m_Index_n == delete_index){  /*第一个符合删除索引的目标*/
                delete workers[i];
                workers[i] = nullptr;
                std::cout<<"find  index"<<delete_index<<"\n";
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
    Worker_base* workers[99] = {0,};
    test_read_c(workers);

    menu();
    char c = '\0';
    while(std::cin>>c){
        std::cout<<"get:"<<c<<"\n";
        switch (c)
        {
        case '0':
            break; 
        case '1'/* constant-expression */:
            add_workers(workers);
            break;
        case '2'/* constant-expression */:
            list_workers(workers);
            break;
        case '3'/* constant-expression */:
            list_workers(workers);
            break;
        case '4'/* constant-expression */:
            list_workers(workers);
            break;
        case '5'/* constant-expression */:
            list_workers(workers);
            break;
        case '6'/* constant-expression */:
            list_workers(workers);
            break;
        case '7'/* constant-expression */:
            add_workers(workers);
            break;
        
        default:
            break;
        }
        menu();

    }
    // init_record();


    // testwrite();
    test_read_c(workers);
    //add_worker(workers,14,"DDD",936);
    
    
    delete_workers(workers,2);
    // delete_worker(workers,5);
    // delete_worker(workers,11);

    
    
    sort_workers(workers);
    
    

    return 0;
}
void edit_workers(Worker_base* workers[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;

    int edit_index;
    int is_found = 0;
    cout << "enter edit mode.\nindex: ";
    cin >> edit_index;
    for(int  i=0;i<g_workers_index;i++)
        if(workers[i]!=nullptr){
            if(workers[i]->m_Index_n == edit_index){
                is_found = 1;
                break;/*如果存在多个index 只修改排列顺序第一个*/
            }
        } 
    if(is_found){
        int new_index;
        string new_name;
        int new_id;
        string new_function;

        cout << "\nnew index:  ";
        cin  >> new_index;
        cout << "\nnew name:  ";
        cin  >> new_name;
        cout << "\nnew id:  ";
        cin  >> new_id;
    }
    else{
        cout<<"\n can not find index:"<<edit_index<<endl;
    }
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
        for(int i=0;i<g_workers_index;i++){
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
            }
            //
            else{
                continue;
                }
        }
        index_i = j;
        index_i_last = index_i;
        sordex_i = 0; // 这一行有一个潜在的bug  如果worker[0] == nulptr 程序可能要歇逼
        sordex_i_last = -1;
    }
}


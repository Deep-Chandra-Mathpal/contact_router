#include "include/graph_classes.h"
#include <bits/stdc++.h>
#include <iostream>

int add_vertex_gunit()
{
    vertex_gunit vertex_gunit_obj;
    std::ofstream file;
    file.open("other/graph.sfgss",std::ios::binary | std::ios::trunc);
    file.write((char*)&vertex_gunit_obj,sizeof(vertex_gunit_obj));
    file.close();
    return 0;
}

int add_vertex(int user_graph_id)
{
    std::fstream file;
    smallest_gunit smallest_gunit_obj;
    file.open("other/graph.sfgss",std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
    file.seekp(0,std::ios::beg);
    for(int i=0;i<10;i++)
    {
        file.read((char*)&smallest_gunit_obj,sizeof(smallest_gunit_obj));
        if(smallest_gunit_obj.graph_id == -1)
        {
            smallest_gunit_obj.graph_id = user_graph_id;
            file.seekp(-sizeof(smallest_gunit_obj),std::ios::cur);
            file.write((char*)&smallest_gunit_obj,sizeof(smallest_gunit_obj));
            break;
        }
    }
    file.close();   
    return 0;
}

int add_edge(int user_graph_id, int friend_graph_id)
{
    std::fstream file;
    file.open("other/graph.sfgss",std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
    int end_pos = file.tellp();
    smallest_gunit smallest_gunit_obj;
    smallest_gunit_obj.graph_id = friend_graph_id;
    file.write((char*)&smallest_gunit_obj,sizeof(smallest_gunit_obj));
    file.seekp(0,std::ios::beg);
    smallest_gunit smallest_gunit_obj2;
    for(int i=0;i<10;i++)
    {
        file.read((char*)&smallest_gunit_obj2,sizeof(smallest_gunit_obj2));
        if(smallest_gunit_obj2.graph_id == user_graph_id)
        {   
            while(smallest_gunit_obj2.next_byte!=-1)
            {
                int curr_pos = file.tellp();
                file.seekp((smallest_gunit_obj2.next_byte - curr_pos), std::ios::cur);
                file.read((char*)&smallest_gunit_obj2,sizeof(smallest_gunit_obj2));
            }
            smallest_gunit_obj2.next_byte = end_pos;
            file.seekp(-(sizeof(smallest_gunit_obj2)),std::ios::cur);
            file.write((char*)&smallest_gunit_obj2,sizeof(smallest_gunit_obj2));
            break;
        }
    }
    file.close();
    return 0;
}

std::list<int> return_friend_list(int user_graph_id)
{
    std::list<int> friends_list;
    std::ifstream file;
    smallest_gunit smallest_gunit_obj;
    file.open("other/graph.sfgss",std::ios::binary | std::ios::in);
    for(int i=0;i<10;i++)
    {   
        file.read((char*)&smallest_gunit_obj,sizeof(smallest_gunit_obj));
        if(smallest_gunit_obj.graph_id == user_graph_id)
        {   
            while(smallest_gunit_obj.next_byte>0)
            {
                int curr_pos = file.tellg();
                file.seekg((smallest_gunit_obj.next_byte - curr_pos), std::ios::cur);
                file.read((char*)&smallest_gunit_obj,sizeof(smallest_gunit_obj));
                friends_list.push_back(smallest_gunit_obj.graph_id);
            }
            break;
        }
    }
    return friends_list;
}

int graph_operation_test()
{
    /*int add_vertex_gunit();
    int add_vertex(int);
    int p = add_vertex_gunit();
    add_vertex(1);
    add_vertex(4);
    add_vertex(6);
    add_vertex(7);
    add_edge(4,1);
    add_edge(4,6);
    add_edge(1,4);
    add_edge(4,7);*/
    std::ifstream file;
    smallest_gunit smg;
    int count = 0;
    std::list<int> return_friend_list(int);
    file.open("other/graph.sfgss",std::ios::binary | std::ios::in);
    for(int i=0;i<10;i++){
    file.read((char*)&smg,sizeof(smg));
    std::cout<<"size : "<<sizeof(smg)<<"  , "<<"size of string : "<<sizeof(smg.graph_id)<<" , "<<"size of int : "<<sizeof(smg.next_byte)<<" , ";
    std::cout<<"graph_id : "<<smg.graph_id<<" , "<<"next_byte : "<<smg.next_byte<<" : "<<++count<<"\n";
    }

    std::cout<<"\n";
    for(int i=0;i<5;i++){
    std::cout<<"position : "<<file.tellg()<<"\n";
    file.read((char*)&smg,sizeof(smg));
    std::cout<<"size : "<<sizeof(smg)<<"  , "<<"size of string : "<<sizeof(smg.graph_id)<<" , "<<"size of int : "<<sizeof(smg.next_byte)<<" , ";
    std::cout<<"graph_id : "<<smg.graph_id<<" , "<<"next_byte : "<<smg.next_byte<<" : "<<++count<<"\n";
    }
    std::cout<<file.tellg();
    file.close();
    std::cout<<"\n";
    std::list<int> friends = return_friend_list(4);
    while(!friends.empty())
    {
        std::cout<<"f:"<<friends.front()<<"   ";
        friends.pop_front();
    }
    return 0;
}
/*int main()
{
    int graph_operation_test();
    graph_operation_test();
    return 0;
}*/
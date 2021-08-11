#include<bits/stdc++.h>
#include "include/database_functions.h"
#include "include/user_input_functions.h"
#include "include/python_functions.h"
#include "include/finding_route.h"
#include "include/graph_file_operation.h"

void enter_user_info()
{   
    std::string name,address,contact;
    std::cout<<"\nEnter your Name : ";
    std::getline(std::cin,name);
    std::cout<<"\nEnter your District : ";
    std::getline(std::cin,address);
    std::cout<<"\nEnter your Phone Number : ";
    std::getline(std::cin,contact);
    enter_user_info_v2(name,address,contact);
}

void enter_user_info_v2(std::string name_,std::string address_,std::string contact_)
{
    user_personal_info* user_personal_info_obj = new user_personal_info(name_,address_,contact_);
    save_user_data(user_personal_info_obj);
    add_vertex(find_id(name_));
    std::cout<<"\nProcessing data.............";
    data_delivery_telegram(name_,address_,contact_,"user_detail");
    std::cout<<"\n\nDone\n";
}

void show_all_user()
{
    show_all_users_id_name();
}

void add_friend()
{
    show_all_user();
    int u,v;
    std::cout<<"\nEnter your Id : ";
    std::cin>>u;
    std::cout<<"\nEnter friend Id : ";
    std::cin>>v;
    add_friend_v2(u,v);
}

void add_friend_v2(int u, int v)
{
    add_edge(u,v);
    std::cout<<"\nFriend added";
}

void find_contact()
{
    show_all_user();
    int u;
    std::cout<<"\nEnter Your Id : ";
    std::cin>>u;
    std::string address;
    std::cout<<"\nEnter district name to find the contact : ";
    std::getline(std::cin,address);
    find_contact_v2(u, address);
}

void find_contact_v2(int u, std::string address)
{
    std::list<int> find_route(int,std::string);
    std::list<int> route = find_route(u,address);
    int count=1;
    while(!route.empty())
    {
        std::array<std::string, 3> contact_details = return_name_address_contact(route.front());
        std::cout<<"\nPerson Number "<<count++;
        std::cout<<"\nName     :  "<<contact_details[0];
        std::cout<<"\nAddress  :  "<<contact_details[1];
        std::cout<<"\nContact  :  "<<contact_details[2];
        std::cout<<"\n\nProcessing data.............";
        data_delivery_telegram(contact_details[0],contact_details[1],contact_details[2],"contact_detail");
        std::cout<<"\n\nDone\n";
        route.pop_front();
    }
}

void database_table_and_graph_storage_creation()
{
    create_database_table();
    add_vertex_gunit();
}
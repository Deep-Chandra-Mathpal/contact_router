#include<iostream>
#include "include/user_personal_info.h"
#include "include/user_input_functions.h"

int main()
{
    database_table_and_graph_storage_creation(); //run only one time otherwise comment out the line
    std::cout<<"\n";
    enter_user_info_v2("name_1","nanital","0000000001");
    enter_user_info_v2("name_2","champawat","0000000002");
    enter_user_info_v2("name_3","chamoli","0000000003");
    enter_user_info_v2("name_4","champawat","0000000004");
    enter_user_info_v2("name_5","uttarakhand","0000000005");
    enter_user_info_v2("name_6","uttarkashi","0000000006");
    enter_user_info_v2("name_7","uttarakhand","0000000007");
    add_friend_v2(4,1);
    add_friend_v2(4,6);
    add_friend_v2(1,4);
    add_friend_v2(4,7);
    add_friend_v2(2,1);
    std::cout<<"\n";
    find_contact_v2(2,"uttarakhand");
    return 0;
}
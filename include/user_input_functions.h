#ifndef USER_INPUT_FUNCTIONS_H
#define USER_INPUT_FUNCTIONS_H

void enter_user_info();
void add_friend();
void find_contact();
void show_all_user();
void database_table_and_graph_storage_creation();
void enter_user_info_v2(std::string name_,std::string address_,std::string contact_);
void find_contact_v2(int u, std::string address);
void add_friend_v2(int u, int v);

#endif
#ifndef DATABASE_FUNCTIONS_H
#define DATABASE_FUNCTIONS_H


#include "user_personal_info.h"

int save_user_data(user_personal_info *);
std::string find_address_in_database(int);
void show_all_users_id_name();
int find_id(std::string);
std::array<std::string, 3> return_name_address_contact(int);
int create_database_table();

#endif
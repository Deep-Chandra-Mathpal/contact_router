#include<sqlite3.h>
#include<bits/stdc++.h>
#include "include/user_personal_info.h"
#include "include/database_functions.h"

int create_database_table()
{
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return 0;
    }
    sqlite3_stmt* stmt;
    std::string query = "CREATE TABLE user_info(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR(255), address VARCHAR(255), contact VARCHAR(255));";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

int save_user_data(user_personal_info *user_info_obj)
{
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return 0;
    }
    sqlite3_stmt* stmt;
    std::string query = "INSERT INTO user_info (name,address,contact) VALUES (?1,?2,?3);";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    sqlite3_bind_text(stmt, 1, (user_info_obj->get_name()).c_str(), -1, NULL);
    sqlite3_bind_text(stmt, 2, (user_info_obj->get_address()).c_str(), -1, NULL);
    sqlite3_bind_text(stmt, 3, (user_info_obj->get_contact()).c_str(), -1, NULL);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return 0;
}

std::string find_address_in_database(int user_graph_id_)
{
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return 0;
    }
    sqlite3_stmt* stmt;
    std::string query = "SELECT address FROM user_info WHERE id = ?1";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    sqlite3_bind_int(stmt, 1, user_graph_id_);
    sqlite3_step(stmt);
    unsigned char* temp = new unsigned char[255];
    memcpy(temp,sqlite3_column_text(stmt, 0),255);
    std::string address_(reinterpret_cast< char const* >(temp));
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return address_;
}

void show_all_users_id_name()
{
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return;
    }
    sqlite3_stmt* stmt;
    std::string query = "SELECT id, name FROM user_info";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    while(sqlite3_step(stmt) == SQLITE_ROW)
    {
        std::cout<<sqlite3_column_int(stmt, 0)<<"  :  "<<sqlite3_column_text(stmt, 1)<<"\n";
    }
}

int find_id(std::string name_)
{
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return 0;
    }
    sqlite3_stmt* stmt;
    std::string query = "SELECT id FROM user_info WHERE name = ?1";  
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    sqlite3_bind_text(stmt, 1, name_.c_str(), -1, NULL);
    sqlite3_step(stmt);
    int id = sqlite3_column_int(stmt, 0);
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return id;
}

std::array<std::string, 3> return_name_address_contact(int user_graph_id_)
{   
    std::array<std::string, 3> detail = {"not found","not found","not found"};
    sqlite3* db;
    int rc = sqlite3_open("other/udb.db", &db);
    if (rc) {
	    std::cout <<"Can't open database." << sqlite3_errmsg(db);
	    return detail;
    }
    sqlite3_stmt* stmt;
    std::string query = "SELECT name, address, contact FROM user_info WHERE id = ?1"; 

    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt,NULL);
    sqlite3_bind_int(stmt, 1, user_graph_id_);
    sqlite3_step(stmt);
    for(int i=0;i<3;i++)
    {
        unsigned char* temp = new unsigned char[255];
        memcpy(temp,sqlite3_column_text(stmt, i),255);
        std::string temp2(reinterpret_cast< char const* >(temp));
        detail[i] = temp2;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return detail;
}

/*int main()
{
    //std::array<std::string, 3> return_name_address_contact(int);
    //std::string find_address_in_database(int user_graph_id_);
    //std::array<std::string, 3> detail =  return_name_address_contact(2);
    //std::cout<<detail[0]<<"\n"<<detail[1]<<"\n"<<detail[2];
    //std::cout<<"\n"<<find_address_in_database(2);
    //int find_id(std::string);
    //std::cout<<find_id("same");
    return 0;
}*/
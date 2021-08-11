#include "Python.h"
#include "include/python_functions.h"
#include<bits/stdc++.h>

int data_delivery_telegram(std::string name_, std::string address_,std::string contact_,std::string return_value_)
{
    char *py = new char[255];
    strcpy(py,"python");
    char *pycode = new char[255];
    strcpy(pycode,"other/telegram_bot.py");
    char** argv = new char*[6];
    argv[0] = py;
    argv[1] = pycode; 
    
    char *name = new char[name_.length() + 1];
    strcpy(name, name_.c_str());
    char *address = new char[address_.length() + 1];
    strcpy(address, address_.c_str());
    char *contact = new char[contact_.length() + 1];
    strcpy(contact, contact_.c_str());
    argv[2] = name;
    argv[3] = address;
    argv[4] = contact;
    char *return_value = new char[255];
    strcpy(return_value,return_value_.c_str());
    argv[5] = return_value;

    Py_BytesMain(6,argv);
    return 0;
}
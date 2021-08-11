#include<bits/stdc++.h>
#include "include/database_functions.h"
#include "include/graph_file_operation.h"
#include "include/finding_route.h"

std::list<int> find_route(int user_graph_id_, std::string address_)
{
    std::map<int, int> path_store;
    std::vector<int> visited_nodes;
    std::queue<int> queue_;
    std::list<int> friends;
    std::list<int> route;
    int flag = 0;
    visited_nodes.push_back(user_graph_id_);
    friends = return_friend_list(user_graph_id_);
    while(!friends.empty())
    {
        path_store.insert(std::pair<int,int>(friends.front(),user_graph_id_));
        queue_.push(friends.front());
        friends.pop_front();
    }
    while(!queue_.empty())
    {
        user_graph_id_ = queue_.front();
        queue_.pop();
        if(find_address_in_database(user_graph_id_) == address_)
        {
            flag = 1;
            break;
        }
        else
        {
            friends = return_friend_list(user_graph_id_);
            while(!friends.empty())
            {
                if(find(visited_nodes.begin(), visited_nodes.end(), friends.front()) == visited_nodes.end())
                {
                    visited_nodes.push_back(friends.front());
                    path_store.insert(std::pair<int,int>(friends.front(),user_graph_id_));
                    queue_.push(friends.front());
                    friends.pop_front();
                }
                else
                    friends.pop_front();              
            }
            
        }
    }
    if(flag==1)
    {  
        std::map<int, int>::iterator iter = path_store.find(user_graph_id_);
        route.push_back(user_graph_id_);
        while(iter != path_store.end() )
        {
            route.push_back(iter->second);
            iter = path_store.find(iter->second);
        }
    }   
    return route;
}

/*int main()
{
    std::list<int> find_route(int,std::string);
    std::list<int> route = find_route(1,"almora");
    while(!route.empty())
    {
        std::cout<<"l:"<<route.front()<<"     ";
        route.pop_front();
    }
    return 0;
}*/
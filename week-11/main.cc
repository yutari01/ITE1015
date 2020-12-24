#include <iostream>
#include <vector>
#include <unordered_map>

#include "college.h"
#include "user.h"
#include "building.h"


int main() {
    std::unordered_map<std::string, College*> colleges;
    std::unordered_map<size_t, Building*> buildings;
    std::unordered_map<size_t, User*> users;


    //대학 수 입력
    int number_of_colleges;
    std::cin >> number_of_colleges; 

    //대학 이름 입력 & 이름 중복 여부 확인
    for(int t = 0 ; t < number_of_colleges ; t++)
    {
        std::string college_names;
        std::cin >> college_names;

        if (colleges.find(college_names) != colleges.end())
        {
            std::cout << "Name duplicated error" << std::endl;
            continue;
        }

        College* college = new College(college_names);
        colleges.insert({college_names,college});
    
    }
        

    //건물 수 입력
    int number_of_buildings;
    std::cin >> number_of_buildings;

    //건물 이름, ID, 대학 이름, 방의 수 입력 & ID중복 및 대학 없음 여부 확인
    for(int t = 0 ; t < number_of_buildings ; t++)
    {
        std::string building_name;
        int building_id;
        std::string college_name;
        int number_of_rooms;
        std::cin >> building_name >> building_id >> college_name >> number_of_rooms;

        if(colleges.find(college_name) == colleges.end())    //대학 없음 오류가 먼저 뜬다.
        {
            std::cout << "College not exist error" << std::endl;
            continue;
        }

        if(buildings.find(building_id) != buildings.end())    //ID중복 오류는 나중에 뜬다.
        {
            std::cout << "Id duplicated error" << std::endl;
            continue;
        }

        Building* building= new Building(building_name, building_id, *colleges[college_name], number_of_rooms);
        buildings.insert({building_id, building});
    }


    //사용자 수 입력
    int number_of_peoples;
    std::cin >> number_of_peoples;

    //사용자 직업, 이름, ID, 대학 이름 입력 & ID중복 및 대학 없음 여부 확인
    for (int t = 0 ; t < number_of_peoples ; t++)
    {
        std::string job_name;
        std::string user_name;
        int user_id;
        std::string college_name;

        std::cin >> job_name >> user_name >> user_id >> college_name;

        if(colleges.find(college_name) == colleges.end())    //대학 없음 오류가 먼저 뜬다.
        {
            std::cout << "College not exist error" << std::endl;
            continue;
        }

        if(users.find(user_id) != users.end())    //ID중복 오류는 나중에 뜬다.
        {
            std::cout << "Id duplicated error" << std::endl;
            continue;
        }

        if (job_name == "student")
        {
            User* user = new Student(user_name, user_id, *colleges[college_name]);
            users.insert({user_id, user});
            continue;
        }

        else if(job_name == "professor")
        {
            User* user = new Professor(user_name, user_id, *colleges[college_name]);
            users.insert({user_id, user});
            continue;
        }

        else if (job_name == "employee")
        {
            User* user = new Employee(user_name, user_id, *colleges[college_name]);
            users.insert({user_id, user});
            continue;
        }
    }


    //동작 수 입력
    int command_number;
    std::cin >> command_number;

    //동작 입력 & 엔터 없음 ,학생 없음, 청소할 것 없음, 권한 오류 여부 확인
    for (int t = 0 ; t < command_number ; t++)
    {
        std::string commands;
        std::cin >> commands;

        if (commands == "enter") //done
        {
            int user_ID;
            int building_ID;

            std::cin >> user_ID >> building_ID;

            if (buildings.find(building_ID) != buildings.end() && users.find(user_ID) != users.end())   
            {
                if (buildings[building_ID]->enter(users[user_ID]) != true)
                {
                   std::cout << "Not enter error" << std::endl;       
                } 
            }
        }
        
        else if (commands == "exit") //done
        {
            int user_ID;
            int building_ID;
            bool check = false;

            std::cin >> user_ID >> building_ID;    

            if (buildings.find(building_ID) != buildings.end() && users.find(user_ID) != users.end())
            {
                check = buildings[building_ID]->exit(users[user_ID]);
            }
        }

        else if (commands == "total") //done2
        {
            int building_ID;
            std::cin >> building_ID;  
            
            size_t total_rooms = buildings[building_ID] -> total();
            std::cout << total_rooms << std::endl;
        }

        else if (commands == "clean")   //done2
        {
            int user_ID;
            int num = 0;

            std::cin >> user_ID;     

            if(dynamic_cast<Employee*>(users[user_ID]) == nullptr) 
            {
                std::cout << "Permission error" << std::endl;
            }

            else 
            {
                for(auto building : buildings)
                {
                    if( building.second->clean(user_ID, users[user_ID]) == true)
                    {
                        num = 1;
                        break;
                    }
                }
                
                if(num == 0) 
                {
                    std::cout << "Nothing to clean error" << std::endl;
                }
            }
               
        }

        else if (commands == "attendance")  //done2
        {
            int user_ID;
            int num = 0;

            std::cin >> user_ID;      

            if(dynamic_cast<Professor*>(users[user_ID]) != nullptr) 
            {
                for(auto building : buildings) 
                {
                    if(building.second->attendance(user_ID,users[user_ID]) == true)
                    {
                        num = 1;
                        break;
                    }
                }

                if(num == 0)
                {
                    std::cout << "No students error" << std::endl;
                }
            }

            else 
            {
                std::cout << "Permission error" << std::endl;
            }
        }

        else if (commands == "where") //done2
        {
            int user_ID;
            int num = 0;

            std::cin >> user_ID;           

            for(auto building : buildings) {
                if (building.second->where(user_ID) == true)
                {
                    break;
                }
            }
        }
         

        else if (commands == "all") //done2
        {
            int building_ID;
            std::cin >> building_ID;

            for(auto building : buildings)
            {
                if(building.second->all(building_ID))
                {
                    break;
                }
            }
        }

    }
    return 0;
}

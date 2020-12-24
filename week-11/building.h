#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include <set>
#include <iostream>

#include "college.h"
#include "user.h"
#include "utility.h"

class Building {
public:
    Building(const std::string& name, size_t id, College& college, size_t size)
    : name(name), id(id), college(college), rooms(size) {
    }

    std::string getName() const {
        return name;
    }

    size_t getId() const {
        return id;
    }

    College& getCollege() const {
        return college;
    }

    bool enter(User* user)
    {
        Employee* employee_desuka = dynamic_cast<Employee*>(user);
        Professor* professor_desuka = dynamic_cast<Professor*>(user);
        Student* student_desuka = dynamic_cast<Student*>(user);

        auto room_num = util::select_randomly(rooms.begin(),rooms.end());//랜덤 방 지정
        int room_number = 0;
       for(auto it = rooms.begin(); it != rooms.end() ; it++ ) //auto를 int로 바꾸기
        {
            if(it == room_num)break;
            else room_number++;
        }
        //std::set<User*>::iterator it;

        if (employee_desuka != nullptr)
        {
			for (int i = 0; i < rooms.size(); i++)
            {
				for (auto it = rooms[i].begin(); it != rooms[i].end(); it++)
                {
					Employee * search = dynamic_cast<Employee*>(*it);
					if (search == nullptr)  //employee가 없으면
                    {
                        rooms[room_number].insert(user);
                        std::cout << room_number+1 << std::endl;
                        return true;
					}
				}
			}
		    return false;   //employee가 있으면
        }

        if (professor_desuka != nullptr)
        {
            int professor_imasuka= 0;
			for (int i = 0; i < rooms.size(); i++)
            {
				for(auto it = rooms[i].begin(); it != rooms[i].end(); it++)
                {
					Professor * check = dynamic_cast<Professor*>(*it);
					if (check != nullptr) 
                    {
                        professor_imasuka += 1;
                    }
				}
			}
			if (professor_imasuka == rooms.size())  //교수가 이미 방의 수 만큼 있는 경우
            {
				return false;
			}

            // 그 경우가 아니라면 없는 방을 찾아서 교수님이 들어가자
            int professor_imasenka = 0;
			while (true){
				professor_imasenka = 0;
				for (auto it = rooms[room_number].begin(); it != rooms[room_number].end(); it++)
                {
					Professor * check_new = dynamic_cast<Professor*>(*it);
					if (check_new != nullptr)   //이미 이 방에는 교수님이 있으니까 다른방을 찾자
                    {
                        professor_imasenka = 1; //이미 있음 교수님이

                        auto room_num = util::select_randomly(rooms.begin(),rooms.end());//랜덤 방 지정
                        int room_number = 0;

                        for(auto it = rooms.begin(); it != rooms.end() ; it++ ) //auto를 int로 바꾸기
                            {
                                if(it == room_num)break;
                                else room_number++;
                            }
						break;
					}
				}

				if (professor_imasenka == 0)    //없으면 진행
                {
					break;
				}
			}
            
			rooms[room_number].insert(user);
			std::cout << room_number+1 << std::endl;
			return true;
        }
           
        if (student_desuka != nullptr)
        {
            int count = 0;
            if ((user->getCollege()).getName() == (this->getCollege()).getName()) //본인 대학의 건물만 갈 수 있다.
            {
				rooms[room_number].insert(user);
				std::cout << room_number+1 << std::endl;
				return true;
            }
        }
        return false;
    }



    bool exit(User* user)
    {
        int count = 0;
        for(int i = 0; i < rooms.size(); i++)
        {
            for(auto it = rooms[i].begin(); it != rooms[i].end(); it++)
            {
                if((*it)->getId() == user->getId())
                {
                    rooms[i].erase(it);
                    count = 1;
                }
            }
        }
        if (count == 1)
        {
            return true;
        }
        else
        {
		    return false;
        }
    }
    
    size_t total() const //모든 사람의 수
    {
        size_t all_room = 0;
        for (int t = 0;  t < rooms.size(); t++)
        {
            all_room = all_room + rooms[t].size();
        }
        return all_room;
    }


    bool clean(size_t user_id, User* user)  //user는 employee
    {
        int count = 0;
		for (int i = 0; i < rooms.size(); i++)
        {
			for (auto it = rooms[i].begin(); it != rooms[i].end(); it++)
            {
				if ((*it)->getId() == user->getId())
                {
					for (int j = 0; j < rooms.size(); j++)
                    {
						rooms[j].clear();
					}
					rooms[i].insert(user);
					count = 1;
				}
			}
		}
        if (count == 1)
        {
            return true;
        }
        else
        {
		    return false;
        }

    }

    bool attendance(size_t user_id, User* user)
    {
		int count = 0;

		for (int i = 0; i < rooms.size(); i++)
        {
			for (auto it = rooms[i].begin(); it != rooms[i].end(); it++)
            {
				if ((*it)->getId() == user->getId())
                {
					for (it = rooms[i].begin(); it != rooms[i].end(); it++)
                    {
						Student * stn = dynamic_cast<Student*>(*it);
						
                        if (stn != nullptr)
                        {
							std::cout << (*it)->getId() << std::endl;
							count = 1;
						}
					}

				}
			}
		}
        if (count == 1)
        {
            return true;
        }
        else
        {
		    return false;
        }
    }

    bool where(size_t user_id)
    {
        int check = 0;
        for(auto room : rooms)
         {
             if (check == 0)
            {
                for(auto user: room) 
                {
                    if(user->getId() == user_id)
                    {
                        check = 1;
                        std::cout << this->getName() << std::endl;
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }
        if(check == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    bool all(size_t building_id) //모든 사람의 이름
    {
        int check = 0;

        if(building_id == getId()) 
        {
            check = 1;
            for(auto room : rooms) 
            {
                for(auto user: room)
                {
                    std::cout << user->getName() << std::endl;
                }
            }
        }
        if(check == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


private:
    std::string name;
    size_t id;
    College& college;
    std::vector<std::set<User*>> rooms;
};

#endif
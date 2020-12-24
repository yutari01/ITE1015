#include <iostream>
#include "animal.h"
#include <cassert>


int main() {

    //Basic Setup
    Lion lion{100}; //300-test for lion (rabbit will fight with lion) 
    Human human{100}; //100-he or she will be fighted(?) by lion
    Human human2{100}; //100-test for human(cuz human will die... So I need new person.)
    Rabbit rabbit{100}; //200-test for rabbit
    Rabbit rabbit2{13}; //13-it will be fight by human2


    Apple apple1{10}; //19
    Apple apple2{5};  //28
    
    Blueberry blueberry1{9}; //12
    Blueberry blueberry2{3}; //10
    
    Cucumber cucumber{2}; //17
    
    
    //lion Eat test
    std::cout << "#####lion eat test#####  " << std::endl; //current point
    std::cout << "Before lion point : "<< lion.point << std::endl; //current point
    lion.eat(apple1);
    lion.eat(apple2);
    std::cout << "After lion point : "<< lion.point << std::endl; //current point   

    std::cout << " " << std::endl;

    //lion pop test
    std::cout << "#####lion pop test##### "<< std::endl; //current point
    int temp_lion_point = lion.point;
    std::cout << "Before pop apple1 : " << apple1.point << std::endl; //current point
    std::cout << "Lion stomach size? (before) : "<< lion.stomach.size() << std::endl;   
    Food pop_apple = lion.pop(); //pop apple1
    std::cout << "Lion stomach size? (after) : "<< lion.stomach.size() << std::endl;  
    std::cout << "After pop apple1 : " << pop_apple.point << std::endl; //current point
    std::cout << "lion point : "<< lion.point << std::endl; //current point
    std::cout << " " << std::endl;
    
    //lion fight test
    std::cout << "#####lion fight test##### "<< std::endl; //current point
    temp_lion_point = lion.point;
    std::cout << "Before lion point : "<< lion.point << std::endl; //current point
    std::cout << "Before human point : "<< human.point << std::endl; //current point
    lion.fight(human); //human will be killed at this moment
    std::cout << "Is Human alive? : "<< human.live << std::endl; 
    std::cout << "After human point : "<< human.point << std::endl; //current point
    std::cout << "After lion point : "<< lion.point << std::endl; //current point
    std::cout << " " << std::endl;


    //lion shout test
    std::cout << "#####lion shout test#####  " << std::endl; //current point
    std::cout << "Before lion point : "<< lion.point << std::endl; //current point
    std::cout << "Lion stomach size? (before) : "<< lion.stomach.size() << std::endl;   
    lion.shout();
    std::cout << "Lion stomach size? (after) : "<< lion.stomach.size() << std::endl;  
    std::cout << "After lion point : "<< lion.point << std::endl; //current point
    std::cout << " " << std::endl;   
    
    //rabbit eat test
    std::cout << "#####rabbit eat test#####  "<< std::endl; //current point
    std::cout << "Before rabbit point : "<< rabbit.point << std::endl; //current point
    rabbit.eat(apple1);
    rabbit.eat(apple2);
    std::cout << "After rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << " " << std::endl; 
    
    //rabbit pop test
    std::cout << "#####rabbit pop test#####  "<< std::endl; //current point
    std::cout << "Before pop apple2 : " << apple2.point << std::endl; //current point
    std::cout << "Rabbit stomach size? (before) : "<< rabbit.stomach.size() << std::endl;   
    pop_apple = rabbit.pop(); //already declared. So no need to Food pop_apple
    std::cout << "Rabbit stomach size? (after) : "<< rabbit.stomach.size() << std::endl;   
    std::cout << "After pop apple2 : " << pop_apple.point << std::endl; //current point
    std::cout << "rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << " " << std::endl;

    //rabbit fight test
    std::cout << "#####rabbit fight test#####  "<< std::endl; //current point
    std::cout << "Before rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << "Before lion point : "<< lion.point << std::endl; //current point
    rabbit.fight(lion);
    std::cout << "Is lion alive? : "<< lion.live << std::endl;
    std::cout << "After rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << "After lion point : "<< lion.point << std::endl; //current point
    std::cout << " " << std::endl;

    
    //rabbit run test
    std::cout << "#####rabbit run test#####  "<< std::endl; //current point
    rabbit.eat(blueberry1);
    rabbit.eat(blueberry2);
    std::cout << "Before rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << "Rabbit stomach size? (before) : "<< rabbit.stomach.size() << std::endl;   
    rabbit.run();
    std::cout << "After rabbit point : "<< rabbit.point << std::endl; //current point
    std::cout << "Rabbit stomach size? (after) : "<< rabbit.stomach.size() << std::endl;
    std::cout << " " << std::endl;
    
    //human eat test
    std::cout << "#####human eat test#####  "<< std::endl; //current point
    std::cout << "Before human2 point : "<< human2.point << std::endl; //current point
    human2.eat(apple1);
    human2.eat(apple2);
    std::cout << "After human2 point : "<< human2.point << std::endl; //current point
    std::cout << " " << std::endl; 

    //human pop test
           
    std::cout << "#####human pop test#####  "<< std::endl; //current point
    std::cout << "Before pop apple2 : " << apple2.point << std::endl; //current point
    std::cout << "Human2 stomach size? (before) : "<< human2.stomach.size() << std::endl;   
    pop_apple = human2.pop();//already declared. So no need to Food pop_apple
    std::cout << "Human2 stomach size? (after) : "<< human2.stomach.size() << std::endl;   
    std::cout << "After pop apple2 : " << pop_apple.point << std::endl; //current point
    std::cout << "Human2 point : "<< human2.point << std::endl; //current point
    std::cout << " " << std::endl;


    //human fight test  
    std::cout << "#####Human fight test#####  "<< std::endl; //current point
    std::cout << "Before Human2 point : "<< human2.point << std::endl; //current point
    std::cout << "Before rabbit2 point : "<< rabbit2.point << std::endl; //current point
    std::cout << "Human2 stomach size? (before) : "<< human2.stomach.size() << std::endl;   
    human2.fight(rabbit2);
    std::cout << "Human2 stomach size? (after) : "<< human2.stomach.size() << std::endl;  
    std::cout << "Is rabbit2 alive? : "<< rabbit2.live << std::endl;
    std::cout << "After rabbit2 point : "<< rabbit2.point << std::endl; //current point
    std::cout << "After human2 point : "<< human2.point << std::endl; //current point
    std::cout << " " << std::endl;
   
    //human sleep test
    human2.eat(apple1);
    human2.eat(apple2);
    human2.eat(blueberry1);


    std::cout << "#####Human sleep test#####  "<< std::endl; //current point
    std::cout << "Before Human2 point : "<< human2.point << std::endl; //current point
    human2.sleep();
    std::cout << "After Human2 point : "<< human2.point << std::endl; //current point
    human2.eat(blueberry2);
    std::cout << "After eat blueberry2 Human point : "<< human2.point << std::endl; //current point
    std::cout << " " << std::endl;
    std::cout << "Check everything is OK..." << std::endl;

    
    return 0;
}

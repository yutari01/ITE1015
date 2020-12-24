#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <vector>
#include <algorithm>
#include "food.h"
#include <iostream>

class Animal {
public:
    int point;
    std::vector<Food> stomach;
    bool live= true;
    Animal(int point) : point(point) {}
    
    virtual void eat(Food& food) {};
    virtual Food pop() {};  //IDK error...
    virtual void fight(Animal& animal) {};
};

class Lion : public Animal {
public:
    Lion(int point)
    : Animal(point * 3) {} //point*3
    
    void eat(Food &food) 
    {
        if(live) //lion is alive
        { 
            this->point += food.point;
            this->stomach.push_back(food);
            
            if(this->point <= 0) //cal
            {  
                this->live = false; 
                point = 0;
            }
        }
    }

    Food pop() {
        if(live && (!stomach.empty()))  //live and not empty
        { 
             
            int count = 0 ; 
            for(int i=0; i<stomach.size(); i++) { //finding min point food
                if(stomach[i].point <= stomach[count].point)
                    count = i;
            }
            
            Food min_food = stomach[count]; //Just one time to define.
            min_food.point -= 10; //food's point get -10 and pop
            stomach.erase(stomach.begin()+count); //pop

            if(this->point <= 0) { //if point under 0
                live = false;
                point = 0;
            }
            
            return min_food;
        }

        else { //else
            
            Food empty{0};
            return empty;
        }

        
    }
    void fight(Animal& animal) {
        if(live && animal.live) { //lion live and animal live
            animal.point -= point/2; 
            
            if(animal.point <= 0) //at this moment animal will be survive or dead.
            {
                animal.live = false;
                animal.point = 0;
            }
            
            if(animal.live == false) //if animal is killed
            {
                point = point + 10; //get 10 point
            
            }
            else 
            { 
                point += 5; //get 5 point
            }
            

        }   
    }

    void shout() {
        if(live && (!stomach.empty())) { //live and not empty
            this->point -= 5; //lose 5 points
           
           int count = 0 ; // max point
            for(int i=0; i < stomach.size(); i++) { //finding max point food
                if(stomach[i].point >= stomach[count].point)
                    count = i;
            }
            
            if(this->point <= 0) //point is under 0
            { 
                this->live = false; //dead
                point = 0;
            }
            
            stomach.erase(stomach.begin()+count); //max point food will be erased



        }
        

    }
    
};

class Rabbit : public Animal{
public:
    Rabbit(int point)
    : Animal(point * 2) {}

    void eat(Food &food) {
        if(live) {
            this->point+= food.point;
            this->stomach.push_back(food);
            
            if(this->point <= 0) {
                this->live = false;
                point = 0;
            }
        }


    }

    Food pop() {
        if(live && !(stomach.empty())) {
            
            int count = 0 ; 

            for(int i=0; i<stomach.size(); i++) {
                if(stomach[i].point >= stomach[count].point)
                    count = i;
            } //find max point food
            
        
            Food max_food = stomach[count];
            max_food.point -= 10;
            stomach.erase(stomach.begin()+count);

            if(this->point <= 0) {
                this->live = false;
                point = 0;
            }
            
            return max_food;
        }

        else {
            Food empty{0};
            return empty;
        }
    }
    
    void fight(Animal& animal) {
        if(live && animal.live) {
            animal.point -= point/2;
            
            if(animal.point <= 0) {
                animal.live = false;
                animal.point = 0;
            }
            
            point = point - 5;
            
            if(this->point <= 0) {
                this->live = false;
                point = 0;
            }
            
            
            
        }
    }

    void run() {
        if(live && (!stomach.empty())) 
        {
            this->point -= 10;
            int index = 0 ;
            
            if(this->point <= 0) 
            {
                this->live = false;
                point = 0;
            }
            
            for(int i=0; i<stomach.size(); i++) {
                if(stomach[i].point <= stomach[index].point)
                    index = i;
            }
            
            stomach.erase(stomach.begin()+index);
            

        }

    }
};

class Human : public Animal {
public:
    Human(int point)
    : Animal(point) {}
    bool check = false;
    
    void eat(Food &food) {
        if(live && check) 
        {  
            this->point+= food.point*2;
            this->stomach.push_back(food);
            check = false;

            if(this->point <= 0) 
            {
                this->live = false;
                point = 0;
            }
        }

        else if(live) {
            this->point += food.point;
            this->stomach.push_back(food);

            if(this->point <= 0) {
                this->live = false;
                point = 0;
            }
        }


    }

    Food pop() {
        if(live && !(stomach.empty())) { //live and not empty
            
            Food pop_food = stomach.back();
            pop_food.point -= 10;
           
            stomach.pop_back();

            if(this->point <= 0) 
            {
                this->live = false;
                point = 0;
            }
            return pop_food;
        }

        else {

            Food empty{0};
            return empty;
            }
    }
    void fight(Animal& animal) {
       if(live && animal.live) {
            animal.point -= point/2; //fight opponent point decrease
            
            if(animal.point <= 0) //cal
            { 
                animal.live = false;
                animal.point = 0;
            }
            
            if(!(stomach.empty())) 
            {    
                stomach.erase(stomach.begin()); //first ate food erase
            }

            else //no food means death
            { 
                live = false;
                point = 0;

            }
            
            if(this->point <= 0) //cal
            { 
                this->live = false;
                point = 0;
            }
            
            
            
        }
    }

    void sleep() 
    {
        if(live) 
        { 
            this->point -= stomach.size(); //lose point amout of size
            check = true;

            if(this->point <= 0) //cal
            {
                this->live = false;
                point = 0;
            }
        }
    }
};



#endif

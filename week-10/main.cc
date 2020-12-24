#include <iostream>
#include <string>
#include "shape.h"
#include <vector>


void add(Canvas& canvas, std::vector<std::string>& namae)
{
    std::string shape;
    std::cin >> shape;
    if (shape == "point")
    {
        float xpos,ypos;
        std::cin >> xpos >> ypos;
        Point* pt = new Point({xpos,ypos});
        canvas.add(pt);
        namae.push_back("Point");

    }
    else if (shape == "rectangle")
    {
        float xpos,ypos,widgh,height;
        std::cin >> xpos >> ypos >> widgh >> height;
        Rectangle* rt = new Rectangle({xpos,ypos},{widgh,height});
        canvas.add(rt);
        namae.push_back("Rectangle");
    }
    else if (shape == "circle")
    {
        float xpos,ypos,size;
        std::cin >> xpos >> ypos >> size;
        Circle* rt = new Circle({xpos,ypos},size);
        canvas.add(rt);
        namae.push_back("Circle");
    }
    else //triangle
    {
        float xpos,ypos,widgh,height;
        std::cin >> xpos >> ypos >> widgh >> height;
        Triangle* ta = new Triangle({xpos,ypos},{widgh,height});
        canvas.add(ta);
        namae.push_back("Triangle");
    }

}

void set(Canvas& canvas, std::vector<std::string>& namae)
{
    size_t id;
    std::string route = "0";

    std::cin >> id;
    std::cin >> route;

    
    if (route == "fill")
    {
        std::string yn;
        std::cin >> yn;
        if (yn == "true")
        {
            canvas.at_fillable(id)->set_fill(true);
        }
        else if (yn == "false")
        {
            canvas.at_fillable(id)->set_fill(false);
        }
        else
        {
            std::cout << "Check your fill command is correct." << std::endl;
        }
    }
    else if (route == "visible")
    {
        std::string yn;
        std::cin >> yn;
        if (yn == "true")
        {
            canvas.at_drawable(id)->set_visible(true);
        }
        else //false
        {
            canvas.at_drawable(id)->set_visible(false);
        }
    }

    else if (route == "size")
    {
        if ( namae[id] == "Circle")
        {

            int num;
            std::cin >> num;
            canvas.at_fillable(id)->set_size({num, num});

        }
        else //triangle, Rectangle
        {
            int widgh, height;
            std::cin >> widgh >> height;
            canvas.at_fillable(id)->set_size({widgh,height});

        }
        
    }
    else //offset
    {
        int xpos,ypos;
		std::cin >> xpos >> ypos;
		canvas.at_drawable(id)->set_offset({xpos,ypos});
    }



}

int main() 
{
    std::vector<std::string> namae; 

    size_t widgh, height;
    std::cin >> widgh >> height; 

    std::string EOL = "exit";  //for program end
    std::string check = "0";


    Canvas canvas{height, widgh};

    while(check != EOL)
    {
        std::cin >> check; //input (add,set,draw,clear,exit)
        if (check == EOL) //if user inputs "exit", program will close.
        {
            break;
        }
        else if (check == "add")
        {
            add(canvas, namae);
        }
        else if (check == "set")
        {
            set(canvas, namae);
        }
        else if (check == "draw")
        {
            canvas.draw();
        }
        else //clear
        {
            canvas.clear();
            namae.clear();
        }
    }
    return 0;
}
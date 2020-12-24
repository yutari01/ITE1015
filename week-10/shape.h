#include <utility>
#include <vector>
#include <functional>
#include <iostream>
#include <cmath>

using Point_ = std::pair<float, float>;

class Drawable {
public:
    Drawable(Point_ offset = { 0, 0 }, bool visible = true)
        : offset(offset), visible(visible) {
    }

    virtual std::vector<Point_> draw() = 0;

    void set_offset(const Point_& offset) {
        this->offset = offset;
    }
    const Point_& get_offset() const {
        return offset;
    }

    void set_visible(bool visible = true) {
        this->visible = visible;
    }
    bool get_visible() const {
        return visible;
    }

private:
    bool visible;
    Point_ offset;
};

class Fillable {
public:
    Fillable(Point_ size, bool fill = true)
        : size(size), fill(fill) {
    }

    void set_fill(bool fill = true) {
        this->fill = fill;
    }
    bool get_fill() const {
        return fill;
    }

    void set_size(const Point_& size) {
        this->size = size;
    }
    const Point_& get_size() const {
        return size;
    }
private:
    bool fill;
    Point_ size;
};

class Point : public Drawable {
public:
    Point(Point_ offset = { 0, 0 }, bool visible = true)
        : Drawable(offset, visible) {
    }

    std::vector<Point_> draw() {
        if (get_visible())  //is visible true?
        {
            Point_ point = {get_offset().second, get_offset().first};
            return {point};
        }
        else //false?
        {
            return{};
        }
    }
};

class Rectangle : public Drawable, public Fillable {
public:
    Rectangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill) {
    }
    
    float start_xpos = get_offset().first;
    float start_ypos = get_offset().second;
    float end_xpos = start_xpos + get_size().first - 1;
    float end_ypos = start_ypos + get_size().second - 1; //coordinate

    std::vector<Point_> draw() {
		std::vector<Point_> dots;
        if (get_visible() == false)
        {
            return {};
        }

		for (int i = start_xpos; i <= end_xpos; i++)
        {
			for (int j = start_ypos; j <= end_ypos; j++)
            {
				if (get_fill() == false)
                {
					if (( start_xpos < i && i < end_xpos) && (start_ypos < j && j < end_ypos)) {
                        continue;
                    }
				}
				Point_ point = {j,i}; //get_fill() is true
				dots.push_back(point);
			}
		}
		return dots;

    }
};

class Circle : public Drawable, public Fillable {
public:
    Circle(Point_ offset, size_t size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable({ size, size }, fill) {
    }

    std::vector<Point_> draw() {

        std::vector<Point_> dots;

        if (get_visible() == false)
        {
            return {};
        }

        float most_high_y = get_offset().second - get_size().second;
        float most_low_y = get_offset().second + get_size().second;
        float most_left_x = get_offset().second - get_size().second;
        float most_right_x = get_offset().first + get_size().first;
        float rad = get_size().first;

        for (auto j = most_high_y + 1; j <= most_low_y - 1; j++)
        {
            for (auto i = most_left_x ; i <= most_right_x; i++)
            {

                float current_x2 = (i-get_offset().first) * (i-get_offset().first);
                float current_y2 = (j-get_offset().second) * (j-get_offset().second);
                float x_2y_2 = round(current_x2 + current_y2);
                float rad2 = rad*rad+1;


                if (get_fill() == true)
                {
                    //x^2 + y^2 <= r^2 solution
                    if (x_2y_2 <= rad2)
                    {
                        dots.push_back({j,i});
                    }
                }
                else{
                    if (x_2y_2 <= rad2)
                    {
                        dots.push_back({j,i});
                        dots.push_back({j,2*get_offset().first - i});
                        break;
                    }

                }
            }

        }
        dots.push_back({get_offset().second - rad, get_offset().first});
        dots.push_back({get_offset().second + rad, get_offset().first});
        return dots;
    }
};

class Triangle : public Drawable, public Fillable {
public:
    Triangle(Point_ offset, Point_ size, bool fill = true, bool visible = true)
        : Drawable(offset, visible), Fillable(size, fill) {
    }

    std::vector<Point_> draw() {

        if (get_visible() == false)
        {
            return {};
        }

        std::vector<Point_> dots;

        float top_pos_x = (get_offset().first);
        float top_pos_y = (get_offset().second - get_size().second);
        float left_pos_x = (get_offset().first - get_size().first/2);
        float left_pos_y = (get_offset().second);
        float right_pos_x = (get_offset().first + get_size().first/2);
        float right_pos_y = (get_offset().second);
        

        float left_side = (top_pos_x - left_pos_x)/(top_pos_y - left_pos_y);
        float right_side = (right_pos_x - top_pos_x)/(right_pos_y-top_pos_y); 


        Point_ point = {-3,-3};

        for (int j = top_pos_y; j <= left_pos_y; j++)
        {
            Point_ point = {-1004,-1004}; //to make size function

            for (int i = round(left_pos_x); i <= round(right_pos_x); i++)
            { 
                 if (i >= round((left_side*(j-top_pos_y) + top_pos_x)))
                 {
                     if (i <= round((right_side*(j-top_pos_y) + top_pos_x)))
                     {
                        if (get_fill() == false && j != left_pos_y && point.first != -1004)
                        {
                            point = {j,i};
                        }
                        else
                        {
                            point = {j,i};
                            dots.push_back(point);
                        }
                    }
                 }
            }
            if (get_fill() == false && j != left_pos_y) 
            {
                dots.push_back(point);
            }
        }
        return dots;
    }
};


class Canvas {
public:
    Canvas(size_t row, size_t col, char ch = '*')
        : row(row), col(col), ch(ch), matrix(row, std::vector<bool>(col, false)) {
    }
    ~Canvas() {}

    void resize(size_t row, size_t col) {
        row = row;
        col = col;
    }

    size_t add(Point* drawable) {
        drawable_components.push_back(drawable);
        fillable_components.push_back(nullptr);

        return drawable_components.size() - 1;
    }

    template <typename T>
    size_t add(T fillable) {
        drawable_components.push_back(fillable);
        fillable_components.push_back(fillable);

        return drawable_components.size() - 1;
    }

    void draw() {
        char sketch[row][col];

		for (int i = 1; i <= row; i++)
        {
			for (int j = 1; j <= col; j++)
            {
				sketch[i][j] = '.';
			}
		}

		for (int i = 0; i < drawable_components.size(); i++)
        {
			for (int j = 0; j < drawable_components[i]->draw().size(); j++)
            {
				Point_ spot = drawable_components[i]->draw()[j];
				if (1 <=spot.second && spot.second <= row)
                {  
                    if (1 <= spot.first && spot.first <= col){
                        sketch[(int)spot.second][(int)spot.first] = ch; //ch="*"
                    }
				}
			}
		}


        for(int i = 1; i <= col; i++)
        {
			for (int j = 1; j <= row; j++)
            {
				std::cout << sketch[j][i];
			}
			std::cout << std::endl;
		}








        
    }

    void drawable_apply(const std::function<void(Drawable*)>& f) {
        for (auto component : drawable_components) {
            f(component);
        }
    }
    void fillable_apply(const std::function<void(Fillable*)>& f) {
        for (auto component : fillable_components) {
            f(component);
        }
    }

    void clear() {
        drawable_components.clear();
        fillable_components.clear();
    }

    void set_ch(char ch) {
        ch = ch;
    }
    char get_ch() const {
        return ch;
    }

    Drawable* at_drawable(size_t index) {
        return drawable_components[index];
    }
    Fillable* at_fillable(size_t index) {
        return fillable_components[index];
    }

private:
    size_t row, col;
    char ch;
    std::vector<Drawable*> drawable_components;
    std::vector<Fillable*> fillable_components;

    std::vector<std::vector<bool>> matrix;
};

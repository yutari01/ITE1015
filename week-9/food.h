#ifndef __FOOD_H__
#define __FOOD_H__

class Food {
public:
    int point;

    Food(int point) : point(point) {}
};

class Cucumber : public Food {
public:
    Cucumber(int point)
    : Food(point * 5 + 7) {
    }
};

class Apple : public Food {
public:
    Apple(int point)
    : Food((point % 3) * 9 + 10) {
    }
};

class Blueberry : public Food {
public:
    Blueberry(int point)
    : Food(point / 3 + 9) {
    }
};

#endif

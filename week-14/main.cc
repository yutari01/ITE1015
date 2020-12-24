#include <iostream>
#include "screen.hpp"
#include "utility.hpp"

int main() {
    size_t height, width;
    std::cin >> height >> width;

    Screen screen{ height, width };

    char c = 0;
    bool flag = true; //If game is over then flag will be false

	screen.draw(std::cout);

    while (flag) {
        std::cin >> c;
        switch (c) {
            case Key::UP:
                screen.key_W();
                break;

            case Key::DOWN:
				screen.key_S();
                break;

            case Key::LEFT:
				screen.key_A();
                break;

            case Key::RIGHT:
				screen.key_D();
                break;

            default:
                flag = false;
                break;
        }

		if (flag == false){
			break;
		}

		screen.create();

		if (screen.is_full()){  //일단 꽉찼는데...
			if (!screen.nouse()){    //더이상 조작이 안된다면?
				flag = false;
				screen.draw(std::cout);
			}
			else {
                screen.draw(std::cout);
            }
		}
		else screen.draw(std::cout);
    }
	std::cout << screen.score() << std::endl;

	return 0;
}

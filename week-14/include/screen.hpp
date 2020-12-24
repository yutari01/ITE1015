#include <vector>
#include <ostream>

#include "utility.hpp"

class Screen {
    size_t height, width;
    std::vector<std::vector<size_t>> blocks;

public:
    Screen(size_t height, size_t width);

    // check block is full
    bool is_full();

    // Create 2 block at random location
    bool create();

    // Create 2 block at the specificed location
    bool create(size_t row, size_t col);

    // draw current blocks
    void draw(std::ostream& out);

	size_t score();
    void key_W();
    void key_A();
    void key_S();
    void key_D();
	bool nouse();
};

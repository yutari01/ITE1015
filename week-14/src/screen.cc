#include "screen.hpp"

Screen::Screen(size_t height, size_t width)
: height(height), width(width),
blocks(height, std::vector<size_t>(width, 0)) {
    create();
}

/**
 * check block is full
 *
 * This function returns whether the block can no longer be created. 
 * If it can be created, it returns false if it is not.
 *
 * @return false if possible to create else true
 */
bool Screen::is_full() {
    size_t count = 0;
    for (auto row : blocks) {
        for (auto val : row) {
            if (val) {
                count += 1;
            }
        }
    }

    return count == height * width;
}

/**
 * Create 2 block at random location
 *
 * This function creates 2 blocks at random locations. 
 * Internally, it calls Screen::create(row, col).
 *
 * @return false if failed else true
 */
bool Screen::create() {
    if (is_full()) {
        return false;
    }

    bool flag = false;
    size_t row, col;
    do {
        row = util::random(height * width);
        col = row / height;
        row %= height;

        flag = create(row, col);
    } while (!flag);
}

/**
 * Create 2 block at the specificed location
 *
 * This function takes row and col and creates 2 blocks at that location. 
 * This function does not check if the block is empty.
 * Returns false when an invalid row or col value is entered.
 *
 * @param row, col
 * @return false if range_error else true with mark blocks[row][col] = 2
 */
bool Screen::create(size_t row, size_t col) {
    if (row >= height || col >= width || blocks[row][col]) {
        return false;
    }

    blocks[row][col] = 2;
    return true;
}

/**
 * draw current blocks
 *
 * This function prints the current block 
 * to the output stream given as an argument.
 *
 * @param target output stream
 */
void Screen::draw(std::ostream &out) {
    for (const auto &row : blocks) {
        for (const auto &val : row) {
            out << val << ',';
        }
        out << std::endl;
    }
}

//printing score when game is over
size_t Screen::score(){
	size_t _score = 0;
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			_score += blocks[j][i];
		}
	}
	return _score;
}

//Check whether the game is over or not
bool Screen::nouse(){

	auto copy_block = blocks;
	key_W();
	key_A();
	key_S();
	key_D();
	if (copy_block == blocks) {
		blocks = copy_block;
	}
	else{
		blocks = copy_block;
		return true;
	}
	return false;
}

//logic for game
void Screen::key_W(){
	for (int i = 0; i < width; i++){
		int count = 0;
		for (int j = 0; j < height; j++){
			if (blocks[j][i] != 0){
				blocks[count][i] = blocks[j][i];
				if (count != j) blocks[j][i] = 0;
				if (count > 0 && blocks[count-1][i] == blocks[count][i]){
					blocks[count-1][i] = blocks[count-1][i] + blocks[count][i];
					blocks[count][i] = 0;
				}
				count += 1;
			}
		}
	}
}
void Screen::key_A(){
	for (int i = 0; i < height; i++){
		int count = 0;
		for (int j = 0; j < width; j++){
			if (blocks[i][j] != 0){
				blocks[i][count] = blocks[i][j];
				if (count != j) blocks[i][j] = 0;
				if (count > 0 && blocks[i][count-1] == blocks[i][count]){
					blocks[i][count-1] = blocks[i][count-1] + blocks[i][count];
					blocks[i][count] = 0;
				}
				count += 1;
			}
		}
	}
}

void Screen::key_S(){
	for (int i = 0; i < width; i++){
		int count = height-1;
		for (int j = height-1; j >= 0; j--){
			if (blocks[j][i] != 0){
				blocks[count][i] = blocks[j][i];
				if (count != j) blocks[j][i] = 0;
				if (count < height-1 && blocks[count+1][i] == blocks[count][i]){
					blocks[count+1][i] = blocks[count+1][i] + blocks[count][i];
					blocks[count][i] = 0;
				}
				count -= 1;
			}
		}
	}
}

void Screen::key_D(){
	for (int i = 0; i < height; i++){
		int count = width-1;
		for (int j = width-1; j >= 0; j--){
			if (blocks[i][j] != 0){
				blocks[i][count] = blocks[i][j];
				if (count != j) blocks[i][j] = 0;
				if (count < width-1 && blocks[i][count+1] == blocks[i][count]){
					blocks[i][count+1] = blocks[i][count+1] + blocks[i][count];
					blocks[i][count] = 0;
				}
				count -= 1;
			}
		}
	}
}




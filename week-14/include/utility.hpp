#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <random>
#include <iterator>

enum Key {
    UP = 'W',
    LEFT = 'A',
    RIGHT = 'D',
    DOWN = 'S',
};

namespace util {
    using LLI = long long int;
    static LLI index = 0;

    /**
     * select random from container
     *
     * @return random item in container
     */
    template <typename Iter>
    Iter random(Iter start, Iter end) {
        auto size = std::distance(start, end);
        std::advance(start, index % size);
        index += 1;
        return start;
    }

    /**
     * generate random LLI in 0-end range
     *
     * @return random index in 0-end range
     */
    template <typename T>
    LLI random(T end) {
        LLI start = index % end;
        index += 1;
        return start;
    }
}

#endif

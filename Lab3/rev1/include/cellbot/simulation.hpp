#pragma once

#include <cstddef>
#include <vector>

namespace Cellbot {

class Simulation {
  private:
    size_t width;
    size_t height;
    std::vector<bool> matrix;

  public:
    enum class Direction {
        forward, backward, left, right
    };

    size_t bot_x;
    size_t bot_y;

    Simulation(size_t width, size_t height, size_t bot_x, size_t bot_y);

    size_t get_width();
    size_t get_height();

    void set(size_t x, size_t y, bool wall);
    bool get(size_t x, size_t y) const;

    void move(Direction dir);
    size_t look(Direction dir);
};

}


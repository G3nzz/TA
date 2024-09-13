#include "simulation.hpp"

#include <stdexcept>
#include <iostream>

namespace Cellbot {

Simulation::Simulation(size_t width, size_t height, size_t bot_x = 0, size_t bot_y = 0)
        : width(width), height(height), bot_x(bot_x), bot_y(bot_y) {
    matrix.resize(width * height);
}

size_t Simulation::get_width() {
    return width;
}

size_t Simulation::get_height() {
    return height;
}

void Simulation::set(size_t x, size_t y, bool wall) {
    if (x >= width) {
        throw std::invalid_argument("x out of bounds");
    }

    if (y >= height) {
        throw std::invalid_argument("y out of bounds");
    }

    matrix[x + y * width] = wall;
}

bool Simulation::get(size_t x, size_t y) const {
    if (x >= width) {
        throw std::invalid_argument("x out of bounds");
    }

    if (y >= height) {
        throw std::invalid_argument("y out of bounds");
    }

    return matrix[x + y * width];
}

void Simulation::move(Direction dir) {
    bool error = false;

    switch (dir) {
        case Direction::forward:
            if (bot_y == 0) error = true;
            else bot_y--;
            break;
        case Direction::backward:
            if (bot_y >= height - 1) error = true;
            else bot_y++;
            break;
        case Direction::left:
            if (bot_x == 0) error = true;
            else bot_x--;
            break;
        case Direction::right:
            if (bot_x >= width - 1) error = true;
            else bot_x++;
            break;
    }

    error = error || get(bot_x, bot_y);

    if (error) {
        std::cout << "The cellbot has crashed!\n";
        exit(0);
    }
}

size_t Simulation::look(Direction dir) {
    size_t distance = 0, x = bot_x, y = bot_y;

    while (true) {
        switch (dir) {
            case Direction::forward:
                if (y == 0) return distance;
                else y--;
                break;
            case Direction::backward:
                if (y >= height - 1) return distance;
                else y++;
                break;
            case Direction::left:
                if (x == 0) return distance;
                else x--;
                break;
            case Direction::right:
                if (x >= width - 1) return distance;
                else x++;
                break;
        }

        if (get(x, y)) {
            return distance;
        }
        else {
            distance++;
        }
    }
}

}


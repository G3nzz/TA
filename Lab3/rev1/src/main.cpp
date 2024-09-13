#include <fstream>
#include <string>

#include "driver.hpp"
#include "ast.hpp"
#include "interpreter.hpp"
#include "simulation.hpp"

using namespace Cellbot;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "The program must be passed 2 arguments\n";
        exit(1);
    }

    std::ifstream labyrinth_file { argv[1] };

    if (!labyrinth_file) {
        std::cout << "cannot open " << argv[1] << "\n";
        exit(1);
    }

    std::vector<std::vector<bool>> labyrinth;
    size_t cur_x = 0,
           cur_y = 0,
           bot_x = 0,
           bot_y = 0,
           cell_count = 0;

    for (std::string line; std::getline(labyrinth_file, line);) {
        std::vector<bool> bool_line;
        bool_line.reserve(line.size());

        cur_x = 0;
        for (char c : line) {
            switch (c) {
                case '.':
                    bool_line.push_back(false);
                    break;
                case '#':
                    bool_line.push_back(true);
                    break;
                case '^':
                    bool_line.push_back(false);
                    bot_x = cur_x;
                    bot_y = cur_y;
                    break;
                case ' ':
                    continue;
                default:
                    std::cout << "Unexpected character in labyrinth file\n";
                    exit(1);
            }
            cur_x++;
            cell_count++;
        }
        if (bool_line.size() == 0) {
            continue;
        }
        else if (labyrinth.size() > 0 && bool_line.size() != labyrinth.back().size()) {
            std::cout << "Inconsisent labyrinth width\n";
            exit(1);
        }
        else {
            labyrinth.push_back(std::move(bool_line));
            cur_y++;
        }
    }

    if (cell_count == 0) {
        std::cout << "The labyrinth is too small\n";
        exit(1);
    }

    Simulation sim { labyrinth[0].size(), labyrinth.size(), bot_x, bot_y };

    for (size_t y = 0; y < labyrinth.size(); y++) {
        for (size_t x = 0; x < labyrinth[y].size(); x++) {
            sim.set(x, y, labyrinth[y][x]);
        }
    }

    Driver driver;
    driver.trace_parsing = false;
    driver.trace_scanning = false;

    driver.parse(argv[2]);

    Interpreter interpreter { sim };

    interpreter.evaluate(*driver.result);

    return 0;
}

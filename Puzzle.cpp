#include "Puzzle.h"
#include <cstdlib>
#include <ctime>

Puzzle::Puzzle(int num_rows, int num_columns)
    : num_rows(num_rows), num_columns(num_columns), array(num_rows, std::vector<Jewel>(num_columns, Jewel::NONE))
{
}

bool Puzzle::initialize(const std::string& jewel_list)
{
    if (jewel_list.size() != num_rows * num_columns) return false;

    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_columns; ++j)
        {
            array[i][j] = getJewelType(jewel_list[i * num_columns + j]);
        }
    }

    return true;
}

void Puzzle::randomize()
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < num_rows; ++i)
    {
        for (int j = 0; j < num_columns; ++j)
        {
            array[i][j] = static_cast<Jewel>(std::rand() % 7);
        }
    }
}

bool Puzzle::update()
{
    std::vector<std::pair<int, int>> matches = findMatches();
    if (matches.empty()) {
        return false;
    }

    removeMatches(matches);
    dropJewels();
    return true;
}

bool Puzzle::swapJewels(std::pair<int, int> prev_loc, std::pair<int, int> next_loc)
{
    if (!areAdjacent(prev_loc, next_loc)) {
        return false;
    }

    if (prev_loc.first < 0 || prev_loc.first >= num_rows ||
        prev_loc.second < 0 || prev_loc.second >= num_columns ||
        next_loc.first < 0 || next_loc.first >= num_rows ||
        next_loc.second < 0 || next_loc.second >= num_columns)
    {
        return false;
    }

    std::swap(array[prev_loc.first][prev_loc.second], array[next_loc.first][next_loc.second]);
    return true;
}

bool Puzzle::setJewel(std::pair<int, int> loc, Jewel jewel)
{
    if (loc.first < 0 || loc.first >= num_rows || loc.second < 0 || loc.second >= num_columns)
    {
        return false;
    }

    array[loc.first][loc.second] = jewel;
    return true;
}

Jewel Puzzle::getJewel(std::pair<int, int> loc) const
{
    if (loc.first < 0 || loc.first >= num_rows || loc.second < 0 || loc.second >= num_columns)
    {
        return Jewel::NONE;
    }

    return array[loc.first][loc.second];
}

Jewel Puzzle::getJewelType(char letter)
{
    switch (letter) {
        case ' ': return Jewel::NONE;
        case '@': return Jewel::RED;
        case '#': return Jewel::ORANGE;
        case '*': return Jewel::YELLOW;
        case '%': return Jewel::GREEN;
        case '$': return Jewel::BLUE;
        case '&': return Jewel::PURPLE;
        case '!': return Jewel::WHITE;
        default: return Jewel::NONE;
    }
}

char Puzzle::getJewelLetter(Jewel jewel)
{
    switch (jewel) {
        case Jewel::NONE: return ' ';
        case Jewel::RED: return '@';
        case Jewel::ORANGE: return '#';
        case Jewel::YELLOW: return '*';
        case Jewel::GREEN: return '%';
        case Jewel::BLUE: return '$';
        case Jewel::PURPLE: return '&';
        case Jewel::WHITE: return '!';
        default: return ' ';
    }
}

std::vector<std::pair<int, int>> Puzzle::findMatches() {
    std::vector<std::pair<int, int>> matches;

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_columns - 2; ++j) {
            if (array[i][j] != Jewel::NONE && array[i][j] == array[i][j + 1] && array[i][j] == array[i][j + 2]) {
                matches.push_back({i, j});
                matches.push_back({i, j + 1});
                matches.push_back({i, j + 2});
            }
        }
    }

    for (int j = 0; j < num_columns; ++j) {
        for (int i = 0; i < num_rows - 2; ++i) {
            if (array[i][j] != Jewel::NONE && array[i][j] == array[i + 1][j] && array[i][j] == array[i + 2][j]) {
                matches.push_back({i, j});
                matches.push_back({i + 1, j});
                matches.push_back({i + 2, j});
            }
        }
    }

    return matches;
}

void Puzzle::removeMatches(const std::vector<std::pair<int, int>>& matches) {
    for (const auto& loc : matches) {
        array[loc.first][loc.second] = Jewel::NONE;
    }
}

void Puzzle::dropJewels() {
    for (int j = 0; j < num_columns; ++j) {
        int empty_row = num_rows - 1;
        for (int i = num_rows - 1; i >= 0; --i) {
            if (array[i][j] != Jewel::NONE) {
                std::swap(array[i][j], array[empty_row][j]);
                empty_row--;
            }
        }

        for (int i = empty_row; i >= 0; --i) {
            array[i][j] = static_cast<Jewel>(std::rand() % 7);
        }
    }
}

bool Puzzle::areAdjacent(std::pair<int, int> loc1, std::pair<int, int> loc2) const {
    return (std::abs(loc1.first - loc2.first) == 1 && loc1.second == loc2.second) ||
           (std::abs(loc1.second - loc2.second) == 1 && loc1.first == loc2.first);
}

//
// Created by Steven on 9/20/2017.
//

#include <random>
#include <functional>
#include <algorithm>
#include "GameBoard.h"
#include "Circle.h"

using namespace cimg_library;

GameBoard::GameBoard(unsigned short width, unsigned short height) :
        board(width, std::vector<bool>(height, DEAD)),
        width(width), height(height) {}

unsigned int GameBoard::getGeneration() const {
    return generation;
}

void GameBoard::draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]) {
    unsigned int wCount = width, hCount = height;
    auto displayW = (unsigned int) canvas.width(), displayH = (unsigned int) canvas.height();
    double paddingW = (double) displayW / (wCount + 1),
            paddingH = (double) displayH / (hCount + 1);
    double radius = ((paddingH > paddingW) ? paddingW : paddingH) / 2;

    for (size_t x = 0; x < board.size(); x++){
        for (size_t y = 0; y < board[x].size(); y++) {
            if (board[x][y]) {
                Circle circle(
                        Point((x * paddingW) + paddingW , (y * paddingH) + paddingH),
                        radius);
                circle.draw(canvas, color);
            }
        }
    }
}

void GameBoard::reset() {
    clear();
    initPattern(initialPattern, Point(width / 2, height / 2));
}

void GameBoard::clear() {
    for (unsigned int x = 0; x < board.size(); x++){
        for (unsigned int y = 0; y < board[x].size(); y++) {
            board[x][y] = false;
        }
    }
}

std::vector<bool>* GameBoard::operator[](unsigned int index) {
    return &board[ index];
}

bool GameBoard::operator()(unsigned int x, unsigned int y) {
    return board[x][y];
}

void GameBoard::operator()(unsigned int x, unsigned int y, bool value) {
    board[x][y] = value;
}

void GameBoard::next() {
    Grid nextBoard(board);
    // TODO split work to threads
    bool currentCell;
    for (unsigned int x = 0; x < board.size(); x++){
        for (unsigned int y = 0; y < board[x].size(); y++) {
            int liveNeighbors = countLiveNeighbors(x, y);
            currentCell = board[x][y];
            if (currentCell == DEAD && liveNeighbors == 3){
                // A dead cell with exactly three live neighbors becomes a live cell (birth).
                nextBoard[x][y] = LIVE;
            } else if (currentCell == LIVE && (liveNeighbors == 2 || liveNeighbors == 3)) {
                // A live cell with two or three live neighbors stays alive (survival).
            } else {
                // In all other cases, a cell dies or remains dead (overcrowding or loneliness).
                if (currentCell == LIVE) {
                    nextBoard[x][y] = DEAD;
                }
            }
        }
    }

    board = nextBoard;
    generation++;
}

int GameBoard::countLiveNeighbors(unsigned int x, unsigned int y) {
    unsigned short counter = 0;
    std::vector<std::pair<unsigned int, unsigned int>> neighbors {
            {x-1, y+1}, {x, y+1}, {x+1, y+1},
            {x-1, y},             {x+1, y},
            {x-1, y-1}, {x, y-1}, {x+1, y-1}
    };

    for (std::pair<unsigned int, unsigned int> v : neighbors) {
        if (is_onBoard(v.first, v.second))
            counter += board[v.first][v.second]? 1 : 0;
    }

    return counter;
}

inline bool GameBoard::is_onBoard(unsigned int x, unsigned int y) {
    return ((x >= 0 && x < width) && (y >= 0 && y < height));
}

void GameBoard::initFull() {
    for (unsigned int x = 0; x < board.size(); x++){
        for (unsigned int y = 0; y < board[x].size(); y++) {
            board[x][y] = LIVE;
        }
    }
}

void GameBoard::initRandom() {
    auto gen = std::bind(std::uniform_int_distribution<>(0,1),std::default_random_engine());
    for (unsigned int x = 0; x < board.size(); x++){
        for (unsigned int y = 0; y < board[x].size(); y++) {
            board[x][y] = gen();
        }
    }
}

void GameBoard::initPattern(Grid pattern, Point location, bool normalize) {
    initialPattern = pattern;
    if (normalize)
        normalizePattern(pattern);
    insertPattern(pattern, location);
}

void GameBoard::insertPattern(Grid pattern, Point location) {
    unsigned int patternWidth, patternHeight;
    getPatternSize(pattern, patternWidth, patternHeight);

    location.shift((0 - (int)patternWidth) / 2, (0 - (int)patternHeight) / 2);

    for (unsigned int x = 0; x < pattern.size(); x++){
        for (unsigned int y = 0; y < pattern[x].size(); y++) {
            if (is_onBoard((unsigned int) (location.getX() + x), (unsigned int) (location.getY() + y)))
                board[location.getX() + x][location.getY() + y] = pattern[x][y];
            else
                throw std::out_of_range("Patter is not on the board");
        }
    }
}

void GameBoard::normalizePattern(Grid& pattern) {
    unsigned int patternWidth, patternHeight;
    getPatternSize(pattern, patternWidth, patternHeight);

    Grid newPattern = std::vector<std::vector<bool>>(patternHeight, std::vector<bool>(patternWidth, DEAD));

    // Rotate by 90 degrees
    unsigned int newColumn, newRow = 0;
    for (unsigned int oldColumn = patternHeight - 1; (int)oldColumn >= 0; oldColumn--) {
        newColumn = 0;
        for (unsigned int oldRow = 0; oldRow < patternWidth; oldRow++) {
            newPattern[newRow][newColumn] = pattern[oldRow][oldColumn];
            newColumn++;
        }
        newRow++;
    }

    std::reverse(newPattern.begin(), newPattern.end());

    pattern = newPattern;
}

void GameBoard::getPatternSize(const Grid pattern, unsigned int &patternWidth, unsigned int &patternHeight) {
    patternWidth = pattern.size();
    patternHeight = 0;

    for (const auto &row : pattern){
        unsigned int rowWidth = row.size();
        if (rowWidth > patternHeight){
            patternHeight = row.size();
        }
    }
}

unsigned short GameBoard::getWidth() const {
    return width;
}

unsigned short GameBoard::getHeight() const {
    return height;
}

#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


TEST_CASE("Check functions post and read") {
     Board board;
    CHECK(board.read(100, 200, Direction::Horizontal, 3) == "___");
    CHECK(board.read(100, 200, Direction::Vertical, 5) == "_____");
    board.post(100, 200, Direction::Horizontal, "Hey");
    CHECK((board.read(100, 200, Direction::Horizontal, 3)) == "Hey");
    board.post(100, 200, Direction::Vertical, "Hello");
    CHECK(board.read(100, 200, Direction::Vertical, 5) == "Hello");
    board.post(100, 201, Direction::Horizontal, "oy there");
    CHECK(board.read(100, 200, Direction::Horizontal, 10) == "Hoy there_");
    board.post(100, 204, Direction::Vertical, "Shani");
    CHECK(board.read(99, 204, Direction::Vertical, 6) == "_Shani");
    CHECK(board.read(100, 199, Direction::Horizontal, 10) == "_Hoy Shere");
    board.post(10, 15, Direction::Horizontal, "Test");
    CHECK(board.read(10, 15, Direction::Horizontal, 3) == "Tes"); 
    board.post(20, 18, Direction::Vertical, "cpp");
    CHECK(board.read(21, 18, Direction::Vertical, 4) == "pp__");
    board.post(100, 200, Direction::Horizontal, "abcd");
    CHECK(board.read(99, 200, Direction::Vertical, 3) == "_ae");
    CHECK(board.read(99, 201, Direction::Vertical, 3) == "_b_"); 
    CHECK(board.read(99, 202, Direction::Vertical, 3) == "_c_"); 
    CHECK(board.read(99, 203, Direction::Vertical, 3) == "_d_");
    board.post(99, 202, Direction::Vertical, "xyz");
    CHECK(board.read(100, 200, Direction::Horizontal, 6) == "abydSh");
    board.post(300, 400, Direction::Vertical, " 12b %53abc#");
    CHECK(board.read(299, 400, Direction::Vertical, 3) == "_ 1");
    CHECK(board.read(299, 400, Direction::Vertical, 10) == "_ 12b %53a");
    CHECK(board.read(301, 400, Direction::Vertical, 12) == "12b %53abc#_");
    CHECK(board.read(303, 400, Direction::Vertical, 14) == "b %53abc#_____");
    CHECK(board.read(306, 399, Direction::Horizontal, 3) == "_5_");
    CHECK(board.read(309, 399, Direction::Horizontal, 3) == "_b_");
    CHECK(board.read(305, 399, Direction::Horizontal, 3) == "_%_");
}

TEST_CASE("Check bad cases") {
    Board board;
    CHECK_NOTHROW(board.post(100, 198, Direction::Horizontal, "abcd"));
    CHECK_NOTHROW(board.read(100, 200, Direction::Vertical, 10));
    board.post(30, 45, Direction::Horizontal, "Hello Shani");
    CHECK(board.read(30, 45, Direction::Horizontal, 10) == "Hello Shan");
    board.post(30, 45, Direction::Horizontal, "");
    CHECK(board.read(30, 45, Direction::Horizontal, 10) == "Hello Shan");
    board.post(30, 45, Direction::Vertical, "Hello Shani");
    CHECK(board.read(30, 45, Direction::Vertical, 10) == "Hello Shan");
    board.post(30, 45, Direction::Vertical, "");
    CHECK(board.read(30, 45, Direction::Vertical, 10) == "Hello Shan");
}
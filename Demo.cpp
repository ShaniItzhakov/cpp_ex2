/**
 * Demo program for message-board exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	ariel::Board board;
	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "abcd");
	cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical, /*length=*/3) << endl;  
		// prints "_b_" (starts at row 99 which is empty; then at row 100 there is "b"; then row 101 is empty again).
	board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
	cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal, /*length=*/6) << endl;  
		// prints "abyd__" (First letters are ab; then y from the "xyz"; then d; then two empty cells).

	board.post(103, 205, Direction::Horizontal, "Hey");
    cout << board.read(103, 205, Direction::Horizontal, 3) << endl;
    board.post(103, 206, Direction::Horizontal, "oy there");
    cout << board.read(103, 205, Direction::Horizontal, 10) << endl;
	board.post(103, 209, Direction::Vertical, "Shani");
    cout << board.read(103, 209, Direction::Vertical, 5) << endl;

	board.show(); // shows the board in a reasonable way. For example:
	//	 98: _________________
 	//	 99: ___x_____________
	//	100: _abyd____________
	//	101: ___z_____________
	//	102: _________________
	//	103: ______Hoy Shere__
	//	104: __________h______
	//	105: __________a______
	//	106: __________n______
	//	107: __________i______
	//	108: _________________
}
#include <string>
#include <map>
#include <limits.h>
#include <iomanip>
using namespace std;

#include "Board.hpp"
using namespace ariel;

const int BASE_TEN = 10;

// // Define a Location which is a pair that holds row and column
// typedef pair<unsigned int, unsigned int> Location; // pair<row, column>
// // Ordered map that stores the character that exists in each Location
// map<Location, char> messageBoard;

/**
 * Function that posts the given message to the message board according to the given location(row, column), direction.
 */
void Board::post(unsigned int row, unsigned int column, Direction direction, string message) {
    // Loop over the message string
    for (unsigned int i = 0; i < message.length(); i++) {
        // Insert char from the given string in the correct location of the message board
        messageBoard[make_pair(row, column)] = message.at(i);
        // If the direction given is Horizontal, then increment the column by 1, else increment the row by 1
        (direction == Direction::Horizontal) ? column++ : row++;
    }
}

/**
 * Function that reads from the message board according to the given location(row, column), direction and length.
 * Returns the message that was read.
 */
string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length) {
    string message;
    // Loop over the given length
    for (unsigned int i = 0; i < length; i++) {
        // Get the char from the message board according to the row and column
        char c = messageBoard[make_pair(row, column)];
        // If the char is empty, then insert into c the value '_'
        if (c == 0) {
            c = '_';
        }
        // Add the char to the returned message
        message += c;
        // If the direction given is Horizontal, then increment the column by 1, else increment the row by 1
        direction == Direction::Horizontal ? column++ : row++;
    }
    return message;
}

/**
 * Private function to calculate the number of digits in the number received.
 * The show function uses it to straighten the columns after each row number.
 */
int num_digits(unsigned int number) {
    int num_digits = 0;
    while (number != 0) {
        number /= BASE_TEN;
        num_digits++;
    }
    return num_digits;
}

/**
 * Function that shows the message board.
 */
void Board::show() {
    // Init the min, max of the row and column
    unsigned int minRow = UINT_MAX;
    unsigned int maxRow = 0;
    unsigned int minColumn = UINT_MAX;
    unsigned int maxColumn = 0;

    // Loop over the message board map which is sorted by the correct order
    for (auto it = messageBoard.cbegin(); it != messageBoard.cend(); it++) {
        // Saves the key from the map
        Location location = (*it).first;
        // Saves the min, max row and column
        minRow = location.first < minRow ? location.first : minRow;
        maxRow = location.first > maxRow ? location.first : maxRow;
        minColumn = location.second < minColumn ? location.second : minColumn;
        maxColumn = location.second > maxColumn ? location.second : maxColumn;
    }
    // Handle if minRow is 0
    unsigned int firstRow = minRow == 0 ? minRow : minRow-1;
    // Handle if minColumn is 0
    unsigned int firstColumn = minColumn ==  0 ? minColumn : minColumn-1;
    // Init the length to the difference between the max column and min column (+3 to the sides and for index 0)
    unsigned int length = maxColumn - minColumn + 3;

    // Loop over the rows from firstRow to maxRow+1
    for (unsigned int i = firstRow; i <= maxRow+1; i++) {
        // Using setw function to straighten the row numbers and print the row number
        cout << setw(num_digits(maxRow)) << i << ": ";
        // Using read function to get the row data and print it
        cout << read(i, firstColumn, Direction::Horizontal, length);
        cout << endl;
    }
}
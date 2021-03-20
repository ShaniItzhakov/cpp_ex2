#include <iostream>
#include <string>
#include <map>
#include "Direction.hpp"
using namespace std;

namespace ariel {
    class Board {
    public:
        void post(unsigned int row, unsigned int column, Direction direction, string message);
        string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);
        void show();
    private:
        // Define a Location which is a pair that holds row and column
        typedef pair<unsigned int, unsigned int> Location; // pair<row, column>
        // Ordered map that stores the character that exists in each Location
        map<Location, char> messageBoard;
    }; 
}
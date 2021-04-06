#include <string>
#include <vector>
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    const Direction Horizontal = Direction::Horizontal;
    const Direction Vertical = Direction::Vertical;

    class Board {
   
        unsigned int row;
        unsigned int column;
        vector<vector<char>> board;
        const string emptyWord = "";
        
    public:
        Board() {setRow() = 0; setColumn() = 0;}
        unsigned int & setRow() { return this->row;}
        unsigned int & setColumn(){ return this->column;}
        const uint & getRow() const {return this->row; }
        const uint getRow(uint index) const {return this->board[index].size();}
        const uint & getColumn() const {return this->column;}
        void resizeBoard(uint row , uint column,Direction,const string &);
        static string getWord(uint index , uint length , string word);
        void post(unsigned int,unsigned int,Direction,string);
        std::string read(unsigned int,unsigned int,Direction,unsigned int);
        void show();
        ~Board();
    };

}
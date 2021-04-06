#include <string>
#include <iostream>
#include "Direction.hpp"
#include "Board.hpp"
#include <vector>
using namespace std;
using ariel::Board;

namespace ariel {

        /* This method inserts a word into the bulletin board based on a given index direction and string */
        void Board::post(uint row, uint column, Direction direction, string message) {
         
         if(direction == Horizontal) {
                resizeBoard(row + 1, column + message.length(),direction,message);
                for (uint i = 0; i < message.length(); i++) {
                        this->board[row][column ++] = message[i];
                }
         }

         else {
                resizeBoard(row + message.length(), column + 1,direction,message);
                for (uint i = 0; i < message.length(); i++) {
                        this->board[row ++][column] = message[i];
                }
              } 
       }

        /*This method expands the bulletin board based on the input,
          and checks whether the input size is larger than the original size , and expands accordingly */
        void Board::resizeBoard(uint row , uint column, Direction direction,const string & message) {
                setRow() = max(row , getRow());
                setColumn() = max(column , getColumn());
                this->board.resize(getRow(),vector<char>());

                if (direction == Horizontal) {
                //resize the row that will contain the word
                this->board[row - 1].resize(column,'_');
                }
                else {
                        row = row - message.length();
                        for (uint i = 0; i < message.length(); i ++) {
                                if (this->board[row + i].size() < column) {
                                        this->board[row + i].resize(column,'_');
                                }
                        }
                }
        }

        /*This method allows to read a word from the bulletin board based on a given index direction and string */
        string Board::read(uint row, uint column, Direction direction, uint length){
                string word; uint index = 0;

                 /* this term check if the input index's bigger than the original size of the board */
                if(row >= getRow() || column >= getColumn()) {return getWord(index,length,word);}

               /* this term check if the input length is equal to zero , then return the empty word "_" */
                if (length == 0) { return emptyWord; }

                if (direction == Horizontal) {                        
                        for (uint i = 0; i < length && column + i < getColumn(); i++) {
                                if (this->board[row].size() <= column + i) {return getWord(index,length,word);}
                                word += this->board[row][column + i];
                                index ++;
                                }
                        }
                else {
                        for (uint i = 0; i < length && row + i < getRow() ; i++) {
                                if (this->board[row + i].size() < column) {
                                word += "_";
                                }
                                else {
                                word += this->board[row + i][column];
                                }
                                index++;       
                        }
                }
                                return getWord(index,length,word);
        }

        /** This method will return the word thats read from the function read
         @note if the length of reading is greater than word length ,
               this method will continue concatenating by empty symbol "_" 
               else , index is equal to length. **/

        string Board::getWord(uint index , uint length , string word) {
                for (uint i = index; i < length; i++) {
                        word += "_";
                }
                return word;
        }

        /* This method print the bulletin board */
        void Board::show(){
                for (uint i = 0; i < getRow(); i ++) {
                        if (this->board[i].empty()) {
                                for (uint j = 0; j < getColumn(); j ++) {
                                        cout << "_" << " ";
                                }
                                cout << "\n";
                        }
                        else {
                                for (uint j = 0; j < getColumn(); j ++) {
                                        if(this->board[i][j] == 0) {cout << "_" << " ";}
                                        else {cout << this->board[i][j] << " ";}
                                }
                                cout << "\n";
                        }
                }
        }
        /* Destructor */
        Board::~Board(){}


}
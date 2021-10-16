/*
 Developed by Yuval Ofek
 This is part of the Othello Project

 ~Content~
Implementation of the Board class
 */

#include <iostream>
#include <string>

#include "board.h"
#include "color_consts.h"
using namespace std;

template <int boardsize, int board_cell>
void Board<boardsize, board_cell>::print_header(){
    cout << "  ";
    for (int k=1; k < boardsize+1; k++){
      cout << k<<" ";
    }
    cout << endl;
  }

template <int boardsize, int board_cell>
Board<boardsize, board_cell>::Board(){
    for(int i = 0; i<boardsize; i++){
      for(int j = 0; j<boardsize; j++){
        Board<boardsize, board_cell>::board[i][j] = EMPTY;
      }
    }
  }

template <int boardsize, int board_cell>
void Board<boardsize, board_cell>::print(){
    //cout << "  Game Board " << endl;
    bool color = true;
    string out;

    Board::print_header();
    for (int i = 0; i < boardsize; i++)
    {
       cout << i+1 << ((i<9)?" ":"");
       for (int j = 0; j < boardsize; j++)

       {
         if (Board<boardsize, board_cell>::board[i][j] == BLACK){
           // Black on position
              cout <<"\u26AA";
         }else if (Board<boardsize, board_cell>::board[i][j] == WHITE){
            // White on position
            cout << "\u26AB";
         } else{
            //alternate black and white if nothing is there -> like a chess board
            if (color){
              out ="\u2588";
            }  else {
              out = "\u2591";
            }
            cout << out<<out;
          }
          color = !color;
       }
       cout << " " << i+1 << endl;
       color = !color;
       //cout << endl;
    }
    Board::print_header();
  }

template <int boardsize, int board_cell>
bool Board<boardsize, board_cell>::check_bounds(int px, int py){
    return (px<boardsize && px>=0 && py< boardsize && py>=0);
  }

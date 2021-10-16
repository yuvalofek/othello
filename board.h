/*
 Developed by Yuval Ofek
 This is part of the Othello Project

 Made by: Yuval Ofek

 ~Content~
 Board class declaration
 Board of templated size where we can print the board and check if an input is
 on the board
*/
#ifndef BOARD_H
#define BOARD_H

#include <bitset>

template <int boardsize, int board_cell>
class Board {
protected:
  std::bitset<board_cell> board [boardsize][boardsize];
  // print a header for the print function (numbers 1 through boardsize)
  void print_header();
public:
  // empty board
  Board();
  // visualize board, currently uses only 2 game pieces and background
  void print();
  // checks if px,py is on board
  bool check_bounds(int px, int py);
};

#endif

/*
 Developed by Yuval Ofek

 This is part of the Othello Project

 ~Content~
 Othello class declaration:
 Playing an othello game
*/

#ifndef OTHELLO_H
#define OTHELLO_H

#include "othelloboard.cpp"

template <int size>
class Othello{
  OthelloBoard<size> board;
  /*
  Allocate room for the chosen position, so we won't have to call new and delete
  all the time
  */
  int chosen_position[2];
  // Select a random position on the board
  void random_position();
  // Request a position from the player
  void prompt_position(bool player);

public:
  // Play othello
  Othello();
};
#endif

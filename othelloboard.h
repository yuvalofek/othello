/*
 Developed by Yuval Ofek


 ~Content~
 OthelloBoard class declaration, derived from board:
 Specific board for Othello. Implements piece placement, automatic flips, and
 win conditions
*/

#ifndef OTHELLOBOARD_H
#define OTHELLOBOARD_H

#include <bitset>
#include "board.cpp"


template <int size>
class OthelloBoard: public Board<size, 2> {
  int piece_counts[2] = {0, 0};
  // used to return the other color given the input color (black-> white)
  std::bitset<2> get_other_color(bitset<2> color);
  /*
  Return number of other color game pieces are in a given direction

  @bitset<2> color is the color of the piece
  @intparam px & @intparam py represent position (x,y)
  @intparam i & @intparam j both in {-1,0,1} represent direction

  return int steps - number of other color pieces in a given direction
  */
  int steps_in_direction(bitset<2> color, int px, int py, int i, int j);
  /*
  Checks all immediate neighbors of input position for flips given a piece of
  input color is placed at the position. Flips these if flip is true.

  @bitset<2>param color is the piece color to be placed at position
  @intparam[2] position is the position to check
  @boolparam flip dictates whether to flip pieces (flips on true)
  */
  bool check_flip(bitset<2> color, int position[2], bool flip);
  // scan through the board and update the piece counts of each side
  void update_counts();
public:
  // initialize a board and then add 4 pieces in center for othello
  OthelloBoard();
  // Counts number of pieces on board and says the one with most pieces won
  void print_win();
  /*
  Consistency checks a piece to be placed on the board. Checks if place is
  occupied, if position is out of bounds, if the place gives the placed color
  flips, and if all pass places the piece.

  @bitset<2>param color is the piece color to be placed at position
  @intparam[2] position is the position to place the piece
  @boolparam verbose is whether or not to print out errors in case of failure

  returns int 0 if pass or -1 if placing failed
  */
  int place_piece(bitset<2> color, int position[2], bool verbose = true);
  // Scans through board and sees if the given color has moves available;
  bool moves_available(bitset<2> color);
  // checks if the board is full. If true print winner
  bool check_full();
};

#endif

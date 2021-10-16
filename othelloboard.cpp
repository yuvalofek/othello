/*
 Developed by Yuval Ofek
 This is part of the Othello Project

 ~Content~
 Implementation of OthelloBoard class
 */
#include <iostream>
#include <string>
#include <limits>

#include "color_consts.h"
#include "othelloboard.h"

using namespace std;

template <int size>
bitset<2> OthelloBoard<size>::get_other_color(bitset<2> color){
  return (color == BLACK) ? WHITE : BLACK;
}

template <int size>
int OthelloBoard<size>::steps_in_direction(bitset<2> color, int px, int py, int i, int j){
  bitset<2> other_color = get_other_color(color);
  int steps = 0;
  //  if the neighbor is another color, keep going in that direction until no longer other color
  while (Board<size,2>::board[px+i][py+j] == other_color &&
         Board<size, 2>::check_bounds(px+i, py+j)){
    steps++;
    px += i;
    py +=j;
    if (!Board<size,2>::check_bounds(px+i, py+j)){
      return 0;
    }
  }
  // Return number of steps in current direction to reach non-other color cell
  steps++;
  return steps;
}

template <int size>
bool OthelloBoard<size>::check_flip(bitset<2> color, int position[2], bool flip){
  // See if neighbors are different color
  bitset<2> other_color = get_other_color(color);
  int steps;
  bool has_flips = false;
  // look at neighboring blocks
  for (int i = -1; i<=1; i++){
    for (int j = -1; j<=1; j++){
      // skip the center (0,0)
      if (i == 0 && j == 0){
        continue;
      }
      // check given direction for flips
      steps = steps_in_direction(color, position[0]-1, position[1]-1, i, j);
      if (steps > 1){
        // if we had a neighbor and the color after is our color, flip blocks in between if we are flipping
        if (Board<size, 2>::board[position[0]-1+i*(steps)][position[1]-1+j*(steps)]==color){
          if (flip){
            for (int k = 1; k<steps; k++)
              Board<size, 2>::board[position[0]-1+i*k][position[1]-1+j*k] = color;
          } else {
            return true;
          }
          has_flips = true;
        }
      }
    }
  }
  return has_flips;
}

template <int size>
void OthelloBoard<size>::update_counts(){
  OthelloBoard<size>::piece_counts[0] = 0;
  OthelloBoard<size>::piece_counts[1] =  0;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (OthelloBoard<size>::board[i][j] == BLACK){
          OthelloBoard<size>::piece_counts[0]+=1;
      } else if (OthelloBoard<size>::board[i][j] == WHITE){
         OthelloBoard<size>::piece_counts[1]+=1;
      }
    }
  }
}

template <int size>
OthelloBoard<size>::OthelloBoard() : Board<size, 2>(){
  // prestart blocks
  OthelloBoard<size>::board[size/2-1][size/2-1] = BLACK;
  OthelloBoard<size>::board[size/2][size/2-1] = WHITE;
  OthelloBoard<size>::board[size/2-1][size/2] = WHITE;
  OthelloBoard<size>::board[size/2][size/2] = BLACK;
}

template <int size>
void OthelloBoard<size>::print_win(){
  string winner = OthelloBoard<size>::piece_counts[0] > OthelloBoard<size>::piece_counts[1] ? "Black" : "White";
  cout << winner << " wins!" << endl;
}

template <int size>
int OthelloBoard<size>::place_piece(bitset<2> color, int position[2], bool verbose){

  // check if position is on board
  if (!Board<size, 2>::check_bounds(position[0]-1, position[1]-1)){
    if (verbose)
      cout << "Position not on board!"<< endl;
    return -1;
  }
  // check if position is occupied
  bool isWhite = Board<size, 2>::board[position[0]-1][position[1]-1] == WHITE;
  bool isBlack = Board<size, 2>::board[position[0]-1][position[1]-1] == BLACK;
  if (isWhite || isBlack){
    if (verbose)
      cout << "This place is already taken!" << endl;
    return -1;
  }
  // check if there are any  flips and flip them
  bitset<2> other_color = get_other_color(color);
  if (!check_flip(color, position, true)){
    if (verbose)
      cout << "Invalid move, no flips!" <<endl;
    return -1;
  }
  // add to board
  cout << "Adding piece at "<<position[0]<<", "<<position[1]<<endl;
  Board<size, 2>::board[position[0]-1][position[1]-1] = color;
  // flip things that need to be flipped
  return 0;
}

template <int size>
bool OthelloBoard<size>::moves_available(bitset<2> color){
  /* Check if input color has available moves */
  // for every empty cell
  for (int i = 1; i < size+1; i++)
  {
     for (int j = 1; j < size+1; j++){
       int position[2] = {i,j};
       if (Board<size,2>::board[i][j] == EMPTY){
         // if flip found we are good
         if (check_flip(color, position, false))
          return true;
       }
     }
   }
   return false;
}

template <int size>
bool OthelloBoard<size>::check_full(){
  bool winner = false;
  update_counts();
  // board is full
  if (piece_counts[1] + piece_counts[0] == 64){
    print_win();
    return true;
  }
  return winner;
}

/*
 Developed by Yuval Ofek
 This is part of the Othello Project

 ~Content~
 Implementation of the Othello Class
 */

#include <iostream>
#include <string>

#include "color_consts.h"
#include "othello.h"

using namespace std;



template <typename T>
int get_val(){
  T input;
  while(true){
    if (cin >> input)
    {
      break;
    } else {
      cout << "Input not recognized, try again"<<endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
  return input;
}


template <int size>
void Othello<size>::random_position(){
    chosen_position[0] = 1+rand() % size;
    chosen_position[1] = 1+rand() % size;
  }

template <int size>
void Othello<size>::prompt_position(bool player){
    board.print();
    string color = (player)? "White": "Black";
    cout << color << " please select position:" <<endl;
    chosen_position[0] = get_val<int>();
    chosen_position[1] = get_val<int>();
  }

template <int size>
Othello<size>::Othello(){
  bool current_color = true;

  // Number of players
  cout << "How many players? (1/2) ";
  const bool number_players = (get_val<int>() == 1);

  // whether to start first or not
  cout << "Do you want to start? (y/n) ";
  const bool player_color = (get_val<char>() == 'y');

  // while the game is not complete...
  while (!board.check_full()){
    // if current color has no moves, switch players
    if (!board.moves_available(bitset<2>((int)current_color))){
      cout << "No moves available"<<endl;
      current_color = !current_color;
      // if other color also has no moves, the game ended
      if (!board.moves_available(bitset<2>((int)current_color))){
        board.print_win();
        break;
      }
    }

    // Position selection logic...
    // If  player turn, prompt and get position & place piece
    if (current_color == player_color){
      do{
      prompt_position(current_color);
      }
      while (board.place_piece(bitset<2>((int)current_color),
              chosen_position) != 0);
    } else {
      // if 2 players - prompt for position
      if (!number_players){
        do{
        prompt_position(current_color);
        }
        while (board.place_piece(bitset<2>((int)current_color),
               chosen_position, !number_players) != 0);

      }  else {
        do{
        random_position();
        }
        while (board.place_piece(bitset<2>((int)current_color),
               chosen_position, !number_players) != 0);
        board.print();
      }
    }
    // flip to other player
    current_color = !current_color;
  }
}

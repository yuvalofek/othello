# Othello
I created a C++ Othello game from scratch!

## Why?
I haven't used C++ in years so I wanted to review my skills with the language, and doing a toy project seemed like a great choice!

## What I did:
I practiced C++ using a toy Othello game. The program allows the user to choose number of players and if to start first, and starts playing. The flips and winner are determined automatically. To enter move, type y-position ENTER x-position.

### Things I did I didn't like:
1. I was a bit lazy and didn't properly do handle the imports (I left them as import \*.cpp instead of the \*.h)
2. Didn't have consistent formatting
3. Used templates when I didn't need them (I wanted to get the hang of using them, so I put them everywhere)
4. Colors could be stored better
5. Used an array to store position
6. The abstraction levels could be cleaned up more
7. using a lot of cout
8. I used namespace std::
9. No makefile


### How I would fix this:
1. Rework the dependencies
2. Use a formatter
3. Remove the templates and simply use class members
4. Use enum 
5. A pair<int, int> might make better sense
6. Have a board member in othello, as opposed to inheritance
7. Combine my outputs into a single string and only print at the end
8. Remove the namespace
9. Use a makefile

## Compile
```cpp
g++ test.cpp
```

### Initial board
```
  1 2 3 4 5 6 7 8
1 ██░░██░░██░░██░░ 1
2 ░░██░░██░░██░░██ 2
3 ██░░██░░██░░██░░ 3
4 ░░██░░⚪⚫██░░██ 4
5 ██░░██⚫⚪░░██░░ 5
6 ░░██░░██░░██░░██ 6
7 ██░░██░░██░░██░░ 7
8 ░░██░░██░░██░░██ 8
  1 2 3 4 5 6 7 8

```

# Othello
I created a C++ Othello game from scratch!

## Why?
I haven't used C++ in years so I wanted to review my skills with the language, and doing a toy project seemed like a great choice!

## What I did:
I practiced C++ using a toy Othello game. The program allows the user to choose number of players and if to start first, and starts playing. The flips and winner are determined automatically. 

### Things I did I didn't like:
* I was a bit lazy and didn't properly do handle the imports (I left them as import \*.cpp instead of the \*.h)

### How I would fix this:
* I want to make a makefile and clean up the dependencies more

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

#include<iostream>
#include "../lib/game.cpp"
using namespace std;

int main(void) {
  Game *game = new Game();
  game->run();
  return 0;
}
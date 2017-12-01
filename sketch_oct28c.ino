#include <Arduboy2.h>
Arduboy2 ard;
Sprites sprites;
int POINTS = 0;
bool Audio = false;
#include "Global.h"
#include "Game.h"





void setup() {
  ard.begin();
  ard.clear();
  ard.setTextWrap(true);
  Level = 0;
}



void loop() {
  if(!ard.nextFrame())
    return;

  ard.pollButtons();
  ard.clear();

  switch(gameState)
  {
    case GameState::TextTitle: TitleText(); break;
    case GameState::MainMenu: UpdateMainMenu(); break;
    case GameState::Game: UpdateGame(); break;
    case GameState::LoadMap: NextLevelLoad(); break;
    case GameState::MapEnding: MapEnding(); break;
    case GameState::Dead: Death(); break;
  }

  ard.display();
}
#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Config.h"
//#include "GameplaySubsystem.h"
//#include "GraphicsSubsystem.h"
//#include "HudSubsystem.h"
#include "InputSubsystem.h"
#include "Scene.h"
#include "Signal.h"
//#include "SoundSubsystem.h"

class TextureCache;

class MainLoop : public Scene
{
public:
  MainLoop(const config::Config& conf,
           sf::RenderWindow* window,
           TextureCache* textureCache);

  void run() override;

  Signal<>& onQuit();

private:
  sf::RenderWindow* _window;

  //GraphicsSubsystem _graphicsSubsystem;
  InputSubsystem _inputSubsystem;
  //GameplaySubsystem _gameplaySubsystem;
  //HudSubsystem _hudSubsystem;

  Signal<> _previous;
  Signal<> _quit;
};

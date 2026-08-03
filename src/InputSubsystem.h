#pragma once

#include <SFML/Graphics.hpp>

#include "Signal.h"

class InputSubsystem
{
public:
  InputSubsystem(sf::RenderWindow* window);

  void run();

  Signal<>& onStartFire();
  Signal<>& onStopFire();
  Signal<double>& onHorizontal();
  Signal<double>& onVertical();
  Signal<>& onQuit();

private:
  Signal<> _startFire;
  Signal<> _stopFire;
  Signal<double> _horizontal;
  Signal<double> _vertical;
  Signal<> _quit;

  const std::map<sf::Keyboard::Key, Signal<double>*> _directionMap;
  sf::RenderWindow* _window;
};

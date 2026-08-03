#include "InputSubsystem.h"

#include <fmt/core.h>

InputSubsystem::InputSubsystem(sf::RenderWindow* window):
  _window(window)
{
}

void InputSubsystem::run()
{
  sf::Event event;
  while (_window->pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
    {
      _quit.emit();
    }
  }
  _horizontal.fire(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100.0);
  _vertical.fire(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100.0);
}

Signal<>& InputSubsystem::onStartFire()
{
  return _startFire;
}

Signal<>& InputSubsystem::onStopFire()
{
  return _stopFire;
}

Signal<double>& InputSubsystem::onHorizontal()
{
  return _horizontal;
}

Signal<double>& InputSubsystem::onVertical()
{
  return _vertical;
}

Signal<>& InputSubsystem::onQuit()
{
  return _quit;
}

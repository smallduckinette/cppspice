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
    if(event.type == sf::Event::Closed ||
       event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape)
    {
      _quit.emit();
    }
  }

  double horizontalPosition = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) / 100.0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
  {
    horizontalPosition -= 1.0;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
  {
    horizontalPosition += 1.0;
  }

  double verticalPosition = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) / 100.0;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
  {
    verticalPosition -= 1.0;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
  {
    verticalPosition += 1.0;
  }

  _horizontal.fire(std::clamp(horizontalPosition, -1.0, 1.0));
  _vertical.fire(std::clamp(verticalPosition, -1.0, 1.0));
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

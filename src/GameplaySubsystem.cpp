#include "GameplaySubsystem.h"

#include <iostream>

GameplaySubsystem::GameplaySubsystem():
  _playerX(100),
  _playerY(100),
  _playerSpeedX(0),
  _playerSpeedY(0)
{
}

void GameplaySubsystem::horizontalMove(double move)
{
  _playerSpeedX = move * 20;
}

void GameplaySubsystem::verticalMove(double move)
{
  _playerSpeedY = move * 20;
}

Signal<double, double>& GameplaySubsystem::onPlayerMove()
{
  return _playerMove;
}

void GameplaySubsystem::run()
{
  auto now = std::chrono::steady_clock::now();
  auto timeDiff = std::chrono::duration<double>(now - _last).count();
  _last = now;

  _playerX += _playerSpeedX * timeDiff;
  _playerY += _playerSpeedY * timeDiff;

  _playerMove.fire(_playerX, _playerY);

  std::cout << _playerX << " - " << _playerY << std::endl;
}

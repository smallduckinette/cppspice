#pragma once

#include <chrono>

#include "Signal.h"

class GameplaySubsystem
{
public:
  GameplaySubsystem();

  void horizontalMove(double move);
  void verticalMove(double move);

  Signal<double, double>& onPlayerMove();

  void run();

private:
  double _playerX;
  double _playerY;

  double _playerSpeedX;
  double _playerSpeedY;

  std::chrono::steady_clock::time_point _last;

  Signal<double, double> _playerMove;
};

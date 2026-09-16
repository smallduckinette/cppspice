#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Config.h"

class TextureCache;
class Visual;

class GraphicsSubsystem
{
public:
  GraphicsSubsystem(sf::RenderWindow* window, TextureCache* textureCache);
  ~GraphicsSubsystem();

  void load(const config::Config& conf);

  void setPosition(EntityID entityID, double x, double y);

  void run() const;

private:
  Visual* makeVisual(const config::Entity& entity);

  sf::RenderWindow* _window;
  TextureCache* _textureCache;

  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};

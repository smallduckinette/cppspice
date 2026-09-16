#pragma once

#include <functional>

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "Constants.h"

class Visual
{
public:
  Visual(const config::Entity& entity, std::function<sf::Texture*(TextureID textureID)> getTexture);

  void draw(sf::RenderWindow* window);

  void place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale);

  sf::Texture* _texture;
  sf::Sprite _sprite;
};

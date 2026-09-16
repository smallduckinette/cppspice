#include "Visual.h"

#include <ranges>
#include <variant>
#include <cmath>

#include <iostream>

#include <fmt/core.h>

Visual::Visual(const config::Entity& entity, std::function<sf::Texture*(TextureID textureID)> getTexture):
  _texture(getTexture(entity._textureID))
{
  _sprite.setTexture(*_texture);
}

void Visual::draw(sf::RenderWindow* window)
{
  window->draw(_sprite);
}

void Visual::place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale)
{
  float width = window->getSize().x * scale;
  float x = window->getSize().x * centerXpc - width / 2;
  float y = window->getSize().y * topYpc;
  float spriteScale = scale * window->getSize().x / _texture->getSize().x;

  std::cout << x << " " << y << std::endl;

  _sprite.setPosition(sf::Vector2f(x, y));
  _sprite.setScale(sf::Vector2f(spriteScale, spriteScale));
}

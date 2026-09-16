#include "GraphicsSubsystem.h"

#include <ranges>

#include <iostream>

#include "TextureCache.h"
#include "Visual.h"

GraphicsSubsystem::GraphicsSubsystem(sf::RenderWindow* window, TextureCache* textureCache):
  _window(window),
  _textureCache(textureCache)
{
}

GraphicsSubsystem::~GraphicsSubsystem() = default;

void GraphicsSubsystem::setPosition(EntityID entityID, double x, double y)
{
  auto visual = _visuals.find(entityID);
  if (visual != _visuals.end())
  {
    visual->second->place(_window, x, y, 1);
  }
}

void GraphicsSubsystem::run() const
{
  std::ranges::for_each(_visuals, [&](const auto& visual) { visual.second->draw(_window); });
}

void GraphicsSubsystem::load(const config::Config& conf)
{
  // Player
  auto visual = makeVisual(conf._player);
}

Visual* GraphicsSubsystem::makeVisual(const config::Entity& entity)
{
  return _visuals.emplace(entity._entityID, std::make_unique<Visual>(entity, [&](TextureID textureID) { return _textureCache->getTexture(textureID); })).first->second.get();
}

#pragma once

#include <filesystem>
#include <vector>
#include <map>

#include "Constants.h"

namespace config
{
  struct Texture
  {
    TextureID _textureID;
    std::filesystem::path _filename;
  };

  using Animation = std::variant<std::monostate, float>;

  struct Entity
  {
    EntityID _entityID;
    TextureID _textureID;
  };

  struct Config
  {
    std::vector<Texture> _textures;
    Entity _player;
  };

  Config makeConfig();
}

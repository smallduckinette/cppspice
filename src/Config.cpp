#include "Config.h"


config::Config config::makeConfig()
{
  StrongIdGenerator<TextureID> textureIdGenerator;
  StrongIdGenerator<EntityID> entityIdGenerator;

  auto playerTexture = textureIdGenerator.generate();

  auto playerEntity = entityIdGenerator.generate();

  return Config{{
      Texture{playerTexture, "resources/spaceship.png"}
    },
                {
                  Entity{playerEntity, playerTexture}
                }
  };
}

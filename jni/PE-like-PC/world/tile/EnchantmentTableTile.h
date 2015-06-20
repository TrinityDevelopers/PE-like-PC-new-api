#pragma once

#include "mcpe/world/level/tile/Tile.h"

class EnchantmentTableTile : public Tile {
public:	
	EnchantmentTableTile(int);
	TextureUVCoordinateSet const& getTexture(signed char, int);
	
public:
	TextureUVCoordinateSet secondary_tex;
	TextureUVCoordinateSet terciary_tex;
};

#pragma once

#include "mcpe/world/level/tile/Tile.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/util/Random.h"

class BrewingStandTile: public Tile {
public:	
	BrewingStandTile(int);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual void addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool);
	
private:
	Random* random = new Random();
	TextureUVCoordinateSet secondary_tex;
};

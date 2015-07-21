#pragma once

#include "mcpe/world/level/tile/EntityTile.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/util/Random.h"
#include "mcpe/world/level/tileentity/BrewingStandTileEntity.h"

class BrewingStandTile: public EntityTile {
public:	
	BrewingStandTile(int);

	virtual const TextureUVCoordinateSet& getTexture(signed char, int);
	virtual int getResource(int, Random*);
	virtual void addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool);
	virtual TileEntity* newTileEntity(const TilePos &);
	
private:
	Random* random = new Random();
	TextureUVCoordinateSet secondary_tex;
};

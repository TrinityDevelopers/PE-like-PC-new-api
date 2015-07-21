#include "BrewingStandTile.h"

BrewingStandTile::BrewingStandTile(int id) : EntityTile(id, &Material::metal) {
	tex = getTextureUVCoordinateSet("brewing_stand", 0);
	secondary_tex = getTextureUVCoordinateSet("brewing_stand_base", 0);
	
	renderType = 25;
	renderPass = Tile::glass->renderPass;
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}

const TextureUVCoordinateSet& BrewingStandTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : secondary_tex;
}

int BrewingStandTile::getResource(int data, Random* rand) {
	return Item::brewing_stand->id;
}

void BrewingStandTile::addAABBs(TileSource* region, int x, int y, int z, AABB const* posAABB, std::vector<AABB, std::allocator<AABB>>& pool) {
	addAABB(AABB(0.4375F, 0.0F, 0.4375F, 0.5625F, 0.875F, 0.5625F).move(x, y, z), posAABB, pool);
	addAABB(AABB(0.0F, 0.0F, 0.0F, 1.0F, 0.125F, 1.0F).move(x, y, z), posAABB, pool);
}

TileEntity* BrewingStandTile::newTileEntity(const TilePos& tp) {
	return new BrewingStandTileEntity();
}
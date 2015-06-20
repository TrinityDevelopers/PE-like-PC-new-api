#include "EnchantmentTableTile.h"

EnchantmentTableTile::EnchantmentTableTile(int id) : Tile(id, &Material::stone) {
	tex = getTextureUVCoordinateSet("enchanting_table_bottom", 0);
	secondary_tex = getTextureUVCoordinateSet("enchanting_table_top", 0);
	terciary_tex = getTextureUVCoordinateSet("enchanting_table_side", 0);
	
	setShape(0.0F, 0.0F, 0.0F, 1.0F, 0.75F, 1.0F);
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}

TextureUVCoordinateSet const& EnchantmentTableTile::getTexture(signed char side, int data) {
	return side == 0 ? tex : side == 1 ? secondary_tex : terciary_tex;
}

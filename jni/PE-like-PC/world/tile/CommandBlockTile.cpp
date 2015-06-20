#include "CommandBlockTile.h"

CommandBlockTile::CommandBlockTile(int id) : Tile(id, &Material::metal) {
	tex = getTextureUVCoordinateSet("command_block", 0);
	
	Tile::solid[id] = false;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}

/*#include "RedstoneLight_OnTile.h"

//Variables
int RedstoneLightOnTile::_id = 124;
RedstoneLightOnTile * RedstoneLightOnTile::tileRedstoneLightOn = NULL;

RedstoneLightOnTile:: RedstoneLightOnTile(int id, bool isLit) : Tile(id, &Material::glass) {	
	init();
	setNameId("redstoneLight");
	setCategory(2);
	setSoundType(Tile::SOUND_GLASS);
	Tile::solid[id] = true;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}*/

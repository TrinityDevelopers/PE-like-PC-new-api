/*#include "NoteBlockTile.h"

//Variables
int NoteBlockTile::_id = 25;
NoteBlockTile *NoteBlockTile::tileNoteBlock = NULL;

NoteBlockTile::NoteBlockTile(int id) : Tile(id, &Material::wood) {
	tex = getTextureUVCoordinateSet("jukebox_side", 0); //Same texture in jukebox and NoteBlock
	
	init();
	setNameId("musicBlock");
	setCategory(2);
	setSoundType(Tile::SOUND_WOOD);
	Tile::solid[id] = true;
	Tile::lightBlock[id] = 0;
	new TileItem(id - 256);
}*/

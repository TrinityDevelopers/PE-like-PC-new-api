#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <string>
#include "Substrate.h"

#include "mcpe/Common.h"
#include "mcpe/SharedConstants.h"
#include "mcpe/client/gui/screen/StartMenuScreen.h"
#include "mcpe/client/gui/Color.h"
#include "mcpe/world/level/tile/Tile.h"
#include "mcpe/world/level/tile/LiquidTileDynamic.h"
#include "mcpe/world/material/Material.h"
#include "mcpe/world/item/Item.h"
#include "mcpe/world/item/TilePlanterItem.h"
#include "mcpe/client/render/tile/TileTessellator.h"
#include "mcpe/locale/I18n.h"

#include "PE-like-PC/world/tile/BrewingStandTile.h"
#include "PE-like-PC/world/tile/EnchantmentTableTile.h"
#include "PE-like-PC/world/tile/CommandBlockTile.h"
#include "PE-like-PC/world/tile/RedstoneLightTile.h"
#include "PE-like-PC/world/tile/NoteBlockTile.h"
#include "PE-like-PC/world/tile/SoulSandTile.h"

const std::string PELikePCVERSION = "1.0 DEV";

static std::string (*_Common$getGameVersionString)();
static std::string Common$getGameVersionString() {
	return _Common$getGameVersionString() + " + §a§lPE Like PC v" + PELikePCVERSION;
}

static std::string (*_I18n$get)(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
static std::string I18n$get(std::string const& key, std::vector<std::string, std::allocator<std::string>> const& a) {
	if(key == "menu.play") return "Singleplayer";
	
	return _I18n$get(key, a);
}

static void (*_TileTessellator$tessellateInWorld)(TileTessellator*, Tile*, const TilePos&, bool);
static void TileTessellator$tessellateInWorld(TileTessellator* self, Tile* tile, const TilePos& pos, bool b) {
	switch(tile->renderType) {
		case 25:
			self->tessellateBrewingStandTileInWorld((BrewingStandTile*)tile, pos.x, pos.y, pos.z, self->region);
			break;
		default:
			_TileTessellator$tessellateInWorld(self, tile, pos, b);
			break;
	}
	
}

static void (*_Tile$initTiles)();
static void Tile$initTiles() {
	_Tile$initTiles();
	
	Tile::enchanting_table = (Tile*)((new EnchantmentTableTile(116))->init()->setDestroyTime(5.0F)->setExplodeable(2000.0F)->setNameId("enchantmentTable")->setCategory(2)->setSoundType(Tile::SOUND_STONE));
	Tile::command_block = (Tile*)((new CommandBlockTile(137))->init()->setDestroyTime(-1.0F)->setExplodeable(6000000.0F)->setNameId("commandBlock")->setCategory(2)->setSoundType(Tile::SOUND_METAL));
	Tile::brewing_stand = (Tile*)((new BrewingStandTile(117))->init()->setDestroyTime(0.5F)->setLightEmission(0.125F)->setNameId("brewingStand")->setSoundType(Tile::SOUND_METAL));

}

static void (*_Item$initItems)();
static void Item$initItems() {
	Item::brewing_stand = (Item*)((new TilePlanterItem(379, Tile::brewing_stand))->setNameID("brewingStand")->setCategory(2)->setIcon("brewing_stand", 0));
	
	_Item$initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems() {
	_Item$initCreativeItems();
	
	Item::addCreativeItem(Item::brewing_stand, 0);
	Item::addCreativeItem(Tile::enchanting_table, 0);
	Item::addCreativeItem(Tile::command_block, 0);
	//Item::addCreativeItem(Tile::soul_sand, 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &Common::getGameVersionString, (void*) &Common$getGameVersionString, (void**) &_Common$getGameVersionString);
	MSHookFunction((void*) &TileTessellator::tessellateInWorld, (void*) &TileTessellator$tessellateInWorld, (void**) &_TileTessellator$tessellateInWorld);
	MSHookFunction((void*) &Tile::initTiles, (void*) &Tile$initTiles, (void**) &_Tile$initTiles);
	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	MSHookFunction((void*) &I18n::get, (void*) &I18n$get, (void**) &_I18n$get);

	return JNI_VERSION_1_2;
}

#pragma once
#include <string>
#include <functional>

#include "../Tessellator.h"
#include "mcpe/world/level/TilePos.h"
#include "mcpe/world/level/tile/Tile.h"
#include "mcpe/world/level/TileSource.h"
#include "../texture/TextureUVCoordinateSet.h"
#include "mcpe/world/phys/AABB.h"
#include "mcpe/world/phys/Vec3.h"
#include "mcpe/CommonTypes.h"
#include "PE-like-PC/world/tile/BrewingStandTile.h"

class TileTessellator {
public:
    // fields
    bool forceOpaque;
    bool otherb;
    TileSource* region;
    TextureUVCoordinateSet forcedUV;
    bool useForcedUV;
    char filler[84];
    int rotBottom;
    int rotTop;
    int rotEast;
    int rotWest;
    int rotNorth;
    int rotSouth;
    char filler1[512];
    Tessellator* tessellator_inst;
    AABB bounds;

    bool tessellateInWorld(Tile*, TilePos const&, bool);
    bool tessellateBlockInWorld(Tile*, TilePos const&);
	bool tessellateBrewingStandTileInWorld(BrewingStandTile*, int, int, int, TileSource*);
    void renderFaceUp(Tile*, const Vec3&, const TextureUVCoordinateSet&);
    void tex1(unsigned int);
    DataID getData(TilePos const&) const;
    unsigned int getLightColor(TilePos const&);

    void setRenderBounds(float, float, float, float, float, float);
};

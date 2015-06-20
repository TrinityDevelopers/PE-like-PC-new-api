#include "TileTessellator.h"

#include <math.h>

void TileTessellator::setRenderBounds(float x0, float y0, float z0, float x1, float y1, float z1) {
	this->bounds = AABB({x0, y0, z0}, {x1, y1, z1});
}

bool TileTessellator::tessellateBrewingStandTileInWorld(BrewingStandTile* tile, int x, int y, int z, TileSource* region) {
    Tessellator* tess = this->tessellator_inst;
 
    // render the center blaze rod
	forcedUV = tile->getTextureUVCoordinateSet("brewing_stand", 0);
    useForcedUV = true;
    setRenderBounds(0.4375, 0.0, 0.4375, 0.5625, 0.875, 0.5625);
    tessellateBlockInWorld(tile, {x, y, z});
 
    // render the 3 blocks on the bottom 
	forcedUV = tile->getTextureUVCoordinateSet("brewing_stand_base", 0);
    
    setRenderBounds(0.5625, 0.0, 0.3125, 0.9375, 0.125, 0.6875);
    tessellateBlockInWorld(tile, {x, y, z});
    setRenderBounds(0.125, 0.0, 0.0625, 0.5, 0.125, 0.4375);
    tessellateBlockInWorld(tile, {x, y, z});
    setRenderBounds(0.125, 0.0, 0.5625, 0.5, 0.125, 0.9375);
    tessellateBlockInWorld(tile, {x, y, z});
    useForcedUV = false;
      
    // render the arms that hold the potions
    TextureUVCoordinateSet stand_uv = tile->getTextureUVCoordinateSet("brewing_stand", 0);
 
    float v0 = stand_uv.minV;
    float v1 = stand_uv.maxV;
    int data = region->getData(x, y, z);
 
    for (int i = 0; i < 3; ++i) {
        float helper = i * PI * 2.0 / 3.0 + (PI / 2);
        float u0 = stand_uv.getInterpolatedU(8.0F);
        float u1 = stand_uv.maxU;
 
        if ((data & 1 << i) != 0) {
           u1 = stand_uv.minU;
        }
 
        float x0 = x + 0.5;
        float x1 = x + 0.5 + sin(helper) * 8.0F / 16.0F;
        float z0 = z + 0.5;
        float z1 = z + 0.5 + cos(helper) * 8.0F / 16.0F;
        tess->vertexUV(x0, (y + 1), z0, u0, v0);
        tess->vertexUV(x0, (y + 0), z0, u0, v1);
        tess->vertexUV(x1, (y + 0), z1, u1, v1);
        tess->vertexUV(x1, (y + 1), z1, u1, v0);
        tess->vertexUV(x1, (y + 1), z1, u1, v0);
        tess->vertexUV(x1, (y + 0), z1, u1, v1);
        tess->vertexUV(x0, (y + 0), z0, u0, v1);
        tess->vertexUV(x0, (y + 1), z0, u0, v0);
    }
    return true;
}

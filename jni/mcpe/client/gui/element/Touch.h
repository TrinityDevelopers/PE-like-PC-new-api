#pragma once
#include "Screen.h"

class Touch {
public:
class TButton {
public:
TButton(int, int, int, int, int, std::string const&,MinecraftClient *,bool);
void renderBg(MinecraftClient *, int, int);
void init(MinecraftClient *);
};
};
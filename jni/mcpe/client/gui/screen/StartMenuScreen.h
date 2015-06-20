#pragma once

#include "Screen.h"

namespace Touch {
	class StartMenuScreen : public Screen {
	public:
		int currentSplash;
		virtual void chooseRandomSplash();
		virtual void render(int, int, float);
	};
};

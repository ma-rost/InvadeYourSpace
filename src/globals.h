#pragma once
#include "point.h"

namespace glb
{
	
	constexpr Point<int> screen_size = { 900, 900 };
	static constexpr Point <float> DRAW_RESTRICTIONS{ 20, screen_size.x - 30 };
}

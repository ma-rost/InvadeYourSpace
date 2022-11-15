#pragma once
#include <iostream>
#include <string>

#include "point.h"

namespace glb
{
	constexpr Point<int> SCREEN_SIZE = { 900, 900 };
	constexpr Point <float> DRAW_RESTRICTIONS{ 20, SCREEN_SIZE.x - 30 };

	const std::string TITLE = "Invade Your Space";

	constexpr float RESIZE_FACTOR{ 3.5 };

	
}

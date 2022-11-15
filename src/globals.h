#pragma once
#include <string>

#include "point.h"

namespace glb
{
	constexpr Point<int> screen_size = { 900, 900 };
	static constexpr Point <float> draw_restrictions{ 20, screen_size.x - 30 };

	const std::string title = "Invade Your Space";
}

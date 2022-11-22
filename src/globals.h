#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "point.h"
class Destructible;

namespace glb
{
	constexpr Point<int> SCREEN_SIZE = { 900, 900 };
	constexpr Rect <float> DRAW_RESTRICTIONS{ 20, 95 ,20 + SCREEN_SIZE.x - 40,  SCREEN_SIZE.y - 60 - 95 };

	constexpr float GAME_LOSE_HEIGHT{ SCREEN_SIZE.x - 180 };
	constexpr float RESIZE_FACTOR{ 3.5 };

	const std::string TITLE = "Invade Your Space";

	std::string getMemoryAddress(const Destructible& object);
	std::string eraseFromFront(std::string& in, int amount);
}

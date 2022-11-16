#pragma once
#include <iostream>
#include <sstream>
#include <string>

#include "point.h"
class Destructible;

namespace glb
{
	constexpr Point<int> SCREEN_SIZE = { 900, 900 };
	constexpr Point <float> DRAW_RESTRICTIONS{ 20, SCREEN_SIZE.x - 30 };

	const std::string TITLE = "Invade Your Space";

	constexpr float RESIZE_FACTOR{ 3.5 };

	std::string getMemoryAddress(const Destructible& object);
	std::string eraseFromFront(std::string& in, int amount);
}

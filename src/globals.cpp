#include "globals.h"

std::string glb::getMemoryAddress(const Destructible& object)
{
	std::ostringstream oss;
	oss << &object;
	return oss.str();
}

std::string glb::eraseFromFront(std::string& in, const int amount)
{
	const int toRemove = static_cast<int>(in.size()) - amount;
	in.erase(in.begin(), in.end() - toRemove);
	return in;
}
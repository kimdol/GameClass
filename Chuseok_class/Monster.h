#pragma once
struct Monster
{
	std::string name{};
	int hp{};

	Monster* nxt{};
	Monster* prev{};
};

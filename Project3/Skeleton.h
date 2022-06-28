#pragma once
#include <SFML/Graphics.hpp>
class Skeleton
{
private:
	sf::Texture texture;
public:
	sf::Sprite sprite;
	void Initialize();
	void Load();
	void Update();
	void Draw();

};

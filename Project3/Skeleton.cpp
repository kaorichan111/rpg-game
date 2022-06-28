#include "Skeleton.h"
#include <iostream>

void Skeleton::Initialize()
{
}

void Skeleton::Load()
{
    if (texture.loadFromFile("Assets/player/texture/BODY_skeleton.png"))
    {
        int XIndex = 3, YIndex = 2;
        sprite.setPosition(sf::Vector2f(500, 400));
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(1.5f, 1.5f));
        std::cout << "Load success !";
        std::cout << std::endl;
    }
}

void Skeleton::Update()
{
}

void Skeleton::Draw()
{
}

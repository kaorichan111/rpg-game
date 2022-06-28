#include "Player.h"
#include <iostream>
#include <vector>

void Player::Initialize()
{
}

void Player::Load()
{
    if (texture.loadFromFile("Assets/player/texture/BODY_skeleton.png"))
    {
        int XIndex = 5, YIndex = 2;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(1.5f, 1.5f));
        std::cout << "Load success !";
        std::cout << std::endl;
    }



}

void Player::Update()
{
    sf::Vector2f position = sprite.getPosition();


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        sprite.setPosition(position + sf::Vector2f(0.1, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        sprite.setPosition(position + sf::Vector2f(-0.1, 0));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        sprite.setPosition(position + sf::Vector2f(0, -0.1));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        sprite.setPosition(position + sf::Vector2f(0, 0.1));
    }
}

void Player::Draw()
{
}

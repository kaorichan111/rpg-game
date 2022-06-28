#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
#include "Player.h"
#include "Skeleton.h"
#include <vector>
using namespace std;

sf::Vector2f normaLizeVector(sf::Vector2f X)
{
    float f = sqrt(X.x * X.x + X.y * X.y);
    sf::Vector2f normal(X.x / f, X.y / f);
    return normal;
}

int main()
{
    //-------------------------INITIALIZEAL------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");

    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();
    vector<sf::RectangleShape> bullets;
    bullets.reserve(10);
    //-------------------------INITIALIZEL------------------------------

    //-------------------------LOAD-------------------------------------

    player.Load();
    skeleton.Load();





    //-------------------------LOAD-------------------------------------


    //main game loop
    while (window.isOpen())
    {

        //-----------------------UPDATE----------------------------------

        player.Update();
        skeleton.Update();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = player.sprite.getPosition();


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(25.0f, 25.0f)));
            bullets[bullets.size() - 1].setPosition(player.sprite.getPosition());
        }

        float bulletSpeed = 0.01f;
        for (int i = 0; i < bullets.size(); i++)
        {
            sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normaLizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * 0.1f);
        }


        //-----------------------UPDATE---------------------------------

        //------------------------DRAW-----------------------------------

        window.clear(sf::Color::Black);

        window.draw(player.sprite);
        window.draw(skeleton.sprite);
        for (int i = 0; i < bullets.size(); i++)
        {
        window.draw(bullets[i]);
        }
        window.display();

        //------------------------DRAW-----------------------------------

    }

    return 0;
}
#include <SFML/Graphics.hpp>
#include<iostream>
#include<random>
#include<string.h>
#include<string>
#include <chrono>
#include <thread>
using namespace std;
int main()
{
    //-------------------------INITIALIZEL------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    //-------------------------INITIALIZEL------------------------------

    //-------------------------LOAD-------------------------------------
    sf::Texture playerTexture;
    sf::Sprite playerSprite;
        if (playerTexture.loadFromFile("Assets/player/texture/BODY_skeleton.png"))
        {
           int XIndex = 5, YIndex =2;
           playerSprite.setTexture(playerTexture);
           playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
           playerSprite.scale(sf::Vector2f(1.5f, 1.5f));
           std::cout << "Load success !";
           std::cout << std::endl;
        }
    
     
     
    
    //-------------------------LOAD-------------------------------------


    //main game loop
    while (window.isOpen())
    {
        
       //-----------------------UPDATE----------------------------------


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2f position = playerSprite.getPosition();
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            playerSprite.setPosition(position + sf::Vector2f(0.1, 0));
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            playerSprite.setPosition(position + sf::Vector2f(-0.1, 0));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, -0.1));
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            playerSprite.setPosition(position + sf::Vector2f(0, 0.1));
        }

        //-----------------------UPDATE---------------------------------

       //------------------------DRAW-----------------------------------

            window.clear(sf::Color::Black);
       
            window.draw(playerSprite);
            window.display();        
    }

    return 0;
}
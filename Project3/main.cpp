#include <SFML/Graphics.hpp>
#include<iostream>
#include<random>
int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Event event;
    sf::CircleShape shape(50.0f);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::White);
    sf::RectangleShape rectangle(sf::Vector2f(100, 50));
    rectangle.setFillColor(sf::Color::Blue);
    rectangle.setPosition(sf::Vector2f(100, 100));
    rectangle.setOrigin(sf::Vector2f(50, 25));

    while (window.isOpen())
    {
        int x = rand() % 800;
        int y = rand() % 600;
        int z = rand() % 91;
        float rotate = z + 0;
        rectangle.setPosition(sf::Vector2f(x, y));
        rectangle.setRotation(rotate);
        shape.setPosition(sf::Vector2f(x, y));


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}
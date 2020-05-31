#include "pch.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "ttt");

    sf::Event event;

    int i{ 0 }, a{ 1 };
    int r{ 10 };

    window.setFramerateLimit(240);

    while (window.isOpen())
    {
        window.clear(sf::Color(0, 255, 255));

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::CircleShape circle(r);
        circle.setFillColor(sf::Color::Black);
        circle.setOrigin(r, r);
        circle.setPosition(100, float(i+1));
        window.draw(circle);
        if (i > (300 - r) || i < (0)) a=-a;
        i = a*(i+1);

        window.display();
    }
}

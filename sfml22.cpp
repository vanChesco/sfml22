#include "pch.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "ttt");

    sf::Event event;

    int y{ 0 }, x{ 0 }, a{ 1 }, b{ 1 };
    int r{ 10 };

    window.setFramerateLimit(240);

    while (window.isOpen())
    {
        window.clear(sf::Color(100, 0, 0));

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
        circle.setPosition(float(x+1), float(y+1));
        window.draw(circle);
        if (y > (300 - r) || y < (0)) a=-a;
        y = (y+a);

        if (x > 400 || x < 0) b = -b;
        x = x + b;

        window.display();
    }
}

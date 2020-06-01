#include "pch.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 300), "ttt");

    sf::Event event;

    int y{ 0 }, x{ 0 }, a{ 1 }, b{ 1 };
    int r{ 10 }, R{ 0 }, G{ 0 }, B{ 0 };

    window.setFramerateLimit(250);

    while (window.isOpen())
    {
        window.clear(sf::Color(R, G, B));

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

        if (R > 255) R = -R++;
        else R++;

        if (G > 255) G = -G - 2;
        else G=G+2;

        if (B > 255) B = -G - 3;
        else B = B + 3;

        window.display();
    }
}

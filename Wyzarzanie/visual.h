#pragma once

#include <SFML/Graphics.hpp>
#include "opener.h"

void wind()
{
    Data* proc = new Data("data.txt");

    sf::RenderWindow window(sf::VideoMode(800, 600), "Nodes");

    auto minX = proc->get_minX() - 100;
    auto maxX = proc->get_maxX() + 100;
    auto minY = proc->get_minY() - 100;
    auto maxY = proc->get_maxY() + 100;

    sf::View view(
        sf::FloatRect(
            minX,
            minY,
            maxX - minX,
            maxY - minY
        )
    );

    window.setView(view);

    std::vector<Node> nodes = proc->get_nodes();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (auto& n : nodes)
        {
            sf::CircleShape dot(4.f);
            dot.setPosition(n.X, n.Y);
            dot.setFillColor(sf::Color::Yellow);

            if (n.next == nullptr)
                continue;

            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(n.X, n.Y), sf::Color::Yellow),
                sf::Vertex(sf::Vector2f(n.next->X, n.next->Y), sf::Color::Yellow)
            };

            window.draw(line, 2, sf::Lines);
            window.draw(dot);
        }

        window.display();
    }

    delete proc;
    return;
}

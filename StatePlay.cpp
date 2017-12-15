#include "StatePlay.h"

StatePlay::StatePlay()
{
    rect.setFillColor(sf::Color::Magenta);
    rect.setSize({800.f, 20.f});
    rect.setOrigin(rect.getSize().x / 2, rect.getSize().y /2);
    rect.setPosition({400,590});
}

void StatePlay::update()
{
    pollEvent();
}

void StatePlay::render()
{
    std::cout << "Calling render method\n";
    Window::instance().getWindow()->clear();
    Window::instance().getWindow()->draw(sprite_background);
    Window::instance().getWindow()->draw(rect);
    Window::instance().getWindow()->draw(player.getCannon());
    Window::instance().getWindow()->display();
}

void StatePlay::pollEvent()
{
    sf::Event event;
    while (Window::instance().getWindow()->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Window::instance().getWindow()->close();
    }
}

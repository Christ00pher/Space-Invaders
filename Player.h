#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Points.h"
#include <iostream>

/*
TODO
[X]Fix shooting bug when changing direction (delay)

*/

enum Direction
{
    NONE,
    LEFT,
    RIGHT
};

class Player
{
public:
    Player();
    ~Player();
    sf::RectangleShape getSprite();
    void update(float dt);
    void handleInput(sf::Event);
    bool shoot();
    void checkKeyboardKeys();
    Points* getPoints();
    void damage();
    void destroy();
    bool isAlive();
    void move(float dt);
    Direction direction;
private:
    bool alive;
    int lives;
    sf::RectangleShape rect;
    bool canShoot;
    bool substract;
    float reloadTime;
    float timer; //timer to control shooting speed
    const float movingSpeed; //constant, helps the 'speed' variable to set it's proper value
    float speed; //changed whether the direction changes
    Points points;
};

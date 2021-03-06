#pragma once
#include "State.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "CollisionSystem.h"
#include "Ufo.h"
#include "Explosion.h"
#include "Button.h"
#include <fstream>
#include <iostream>
#include "Caption.h"

struct Level
{
    int amount; //amount of enemies
    float speed; //speed of enemies
    int id; //level
};

struct fileRecord
{
    long score;
    std::string nick;
};

class StatePlay : public State
{
public:
    StatePlay();
    ~StatePlay() {};
    virtual void update(float);
    virtual void render();
    virtual int handleInput(); //returns nr of state if change is needed
    int pollEvent();
    void spawnEnemies(struct Level);
    virtual void prepare();
    void saveToFile();
private:
    Player player;
    CollisionSystem cs;
    std::vector<Bullet*> playerBullets;
    std::vector<Bullet*> enemyBullets;
    std::vector<Enemy*> enemies;
    std::vector<Explosion*> explosions;
    Ufo* ufo;
    float movingCooldown;
    bool substract;
    int i;
    int currentLevel;
    int enemyAmount;
    bool pause;
    sf::Text gameOverText;
    sf::Text tryAgainText;
    sf::Font font;
    Level level[10];
    float ufoCooldown;
    std::fstream file;
    fileRecord records[10];
    Caption nickCaption;
    Caption message;
    bool enterName;
    float levelCaptionTimer;
    Caption levelCaption;
    bool printLevel;
    float levelPause;
    sf::RectangleShape bonus;
};

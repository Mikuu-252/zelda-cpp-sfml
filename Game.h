#ifndef PO23_SR17_252241_GAME_H
#define PO23_SR17_252241_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include "WorldMap.h"
#include "Items/Sword.h"
#include "Ui.h"


class Game {
    int screenWidth;
    int screenHeight;
    int fps = 144;
    sf::RenderWindow &mainWindow;

    //Game objects
    Player player;
    Ui ui;
    WorldMap worldMap;
    Level activeLevel;

    Sword basicSword = Sword("sword1", true, true, false, "basicSword",-100,-100,0 , 1, true);
    Sword upgradeSword = Sword("sword2", false, true,true, "upgradeSword",-100,-100, 15, 3 , false);


    //Func
    void createObjects();

    //Update
    void updateObjects();
    void updateSwords();
    void pickUpItems();
    void dmgController();
    void changeLevel();

    //Draw
    void drawObjects();
    void drawSwords();


    //Collisions
    bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
    bool checkBorderCollision(int x, int y);
    bool anyWallCollisionPlayer();
    bool anyWallCollisionEnemy(int idx);
    bool checkLevelChange();

public:
    Game(sf::RenderWindow &window);
    void gameLoop();
};


#endif //PO23_SR17_252241_GAME_H

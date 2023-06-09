#ifndef PO23_SR17_252241_GAME_H
#define PO23_SR17_252241_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"
#include "WorldMap.h"
#include "Items/Sword.h"
#include "Ui.h"


class Game {
    int screenWidth = 384;
    int screenHeight = 320;
    int fps = 240;
    enum class GameState{Pause, Play, Menu};
    GameState gameState;
    sf::RenderWindow &mainWindow;


    //Game objects
    Player player;
    Ui ui;
    WorldMap worldMap;
    Level activeLevel;


    Sword basicSword = Sword("sword1", true, true, 'S', 1, true);
    Sword upgradeSword = Sword("sword2", true, true, 'S', 3 , false);


    //Func
    void createObjects();


    void updateObjects();
    void updateSwords(int x, int y);
    void pickUpItems(int x, int y);

    void drawObjects();
    void drawSwords();

    void changeLevel();

    //Collisions
    bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);
    bool checkBorderCollision(int x, int y);
    bool anyWallCollision();
    bool checkLevelChange();


public:
    Game(sf::RenderWindow& window);
    void gameLoop();
};


#endif //PO23_SR17_252241_GAME_H

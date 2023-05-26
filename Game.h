#ifndef PO23_SR17_252241_GAME_H
#define PO23_SR17_252241_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Wall.h"

struct Level{
    std::vector<Wall> walls;

};

class Game {
    int screenWidth = 384;
    int screenHeight = 320;
    int fps = 60;
    enum class GameState{Pause, Play, Menu};
    GameState gameState;
    sf::RenderWindow mainWindow;


    //Game objects
    Player player;
    std::vector<Level> levels;
    int activeLevel = 0;

    //Level func
    void prepareLevel1();
    void prepareLevel2();


    //Func
    void createObjects();

    void updateObjects();
    void drawObjects();

    bool checkCollision(const sf::Sprite& sprite1, const sf::Sprite& sprite2);

public:
    Game();
    void gameLoop();
};


#endif //PO23_SR17_252241_GAME_H

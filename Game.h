#ifndef PO23_SR17_252241_GAME_H
#define PO23_SR17_252241_GAME_H


#include <SFML/Graphics.hpp>
#include "Player.h"


class Game {
    int screenWidth = 720;
    int screenHeight = 480;
    int fps = 60;
    enum class GameState{Pause, Play, Menu};
    GameState gameState;
    sf::RenderWindow mainWindow;

    //Game objects
    Player player;

public:
    Game();
    void gameLoop();
    void createObjects();
    void updateObjects();
    void drawObjects();
};


#endif //PO23_SR17_252241_GAME_H

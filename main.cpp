#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Game.h"

int main() {
    int screenWidth = 384;
    int screenHeight = 320;
    srand (time(nullptr));

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "The copy of Zelda");
    Game game(window);
    game.gameLoop();

    return 0;
}

#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
    int screenWidth = 384;
    int screenHeight = 320;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "The copy of Zelda");
    Game game(window);
    game.gameLoop();

    return 0;
}

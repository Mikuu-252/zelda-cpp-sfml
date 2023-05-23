#include "Game.h"
#include "Player.h"


Game::Game() {
    mainWindow.create(sf::VideoMode(screenWidth, screenHeight), "The copy of Zelda");

}

void Game::gameLoop() {
    sf::Clock clock;
    sf::Time timePerFrame = sf::seconds(1.f / 60.f);

    createObjects();

    while (mainWindow.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        sf::Event event;
        while (mainWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                mainWindow.close();
            }
        }

        updateObjects();

        mainWindow.clear();
        drawObjects();
        mainWindow.display();

        if (elapsedTime < timePerFrame) {
            sf::sleep(timePerFrame - elapsedTime);
        }

    }
}

void Game::createObjects() {
    Player player;
}

void Game::updateObjects() {
    player.update();
}

void Game::drawObjects() {
    player.draw(mainWindow);
}



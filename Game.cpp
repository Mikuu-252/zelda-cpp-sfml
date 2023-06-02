#include <iostream>
#include "Game.h"
#include "Player.h"


Game::Game() {
    mainWindow.create(sf::VideoMode(screenWidth, screenHeight), "The copy of Zelda");
    mainWindow.setFramerateLimit(fps);
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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {
                worldMap.debugLevel();
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

//Create
void Game::createObjects() {

}




//Update
void Game::updateObjects() {

    //Change level
    if(checkLevelChange())
    {
        changeLevel();
    }

    //Wall colision
    if(anyWallCollision() || checkBorderCollision()) {
        player.negativeUpdate();
    } else {
        //Player move
        player.update();
    }



}

//Draw
void Game::drawObjects() {

    for (Wall wall: worldMap.getLevel().walls) {
        wall.draw(mainWindow);
    }

    for (Floor floor: worldMap.getLevel().floors) {
        floor.draw(mainWindow);
    }
    player.draw(mainWindow);
}


bool Game::checkCollision(const sf::Sprite &sprite1, const sf::Sprite &sprite2) {
    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();

    return bounds1.intersects(bounds2);
}

bool Game::anyWallCollision() {
    bool anyWallCollision = false;

    for (Wall wall: worldMap.getLevel().walls) {
        if(Game::checkCollision(player.getSprite(), wall.getSprite())){
            anyWallCollision = true;
        }
    }

    return anyWallCollision;
}

bool Game::checkBorderCollision() {
    if(player.getSprite().getPosition().x < 16 || player.getSprite().getPosition().y < 16 || player.getSprite().getPosition().x > screenWidth-16 || player.getSprite().getPosition().y > screenHeight-16) {
        return true;
    }
    return false;
}

void Game::changeLevel() {
    int lastMove = player.getLastMove();

    player.changeLevelPos();
    if (lastMove == 1) {
        worldMap.changeActiveLevel(0,-1,0);
    }
    if (lastMove == 2) {
        worldMap.changeActiveLevel(0,1,0);

    }
    if (lastMove == 3) {
        worldMap.changeActiveLevel(-1,0,0);

    }
    if (lastMove == 4) {
        worldMap.changeActiveLevel(1,0,0);
    }

}

bool Game::checkLevelChange() {
    int x = player.getSprite().getPosition().x;
    int y = player.getSprite().getPosition().y;


    if (y == 96) {
        return true;
    } else if (y == screenHeight - 32) {
        return true;
    }

    if ( x == 32) {
        return true;
    } else if (x == screenWidth - 32) {
        return true;
    }

    return false;



}






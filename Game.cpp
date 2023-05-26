#include <iostream>
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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F12)) {
                activeLevel += 1;
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
    //Level1
    prepareLevel1();
    prepareLevel2();
}

void Game::prepareLevel1() {
    Level level;
    for (int x = 0; x < 1; ++x) {
        level.walls.push_back(Wall(x,3,32,"wall2"));
        //walls.push_back(Wall(x,9,32,"wall"));
    }
    levels.push_back(level);

}

void Game::prepareLevel2() {
    Level level;
    for (int x = 0; x < 12; ++x) {
        level.walls.push_back(Wall(x,3,32,"wall"));
        //level.walls.push_back(Wall(x,9,32,"wall"));
    }

    levels.push_back(level);
}


//Update
void Game::updateObjects() {

    //Wall colision
    bool anyWallCollision = false;
    for (Wall wall: levels[activeLevel].walls) {
        if(Game::checkCollision(player.getSprite(), wall.getSprite())){
            anyWallCollision = true;
        }
    }

    if(anyWallCollision) {
        player.negativeUpdate();
    } else {
        player.update();
    }

}

//Draw
void Game::drawObjects() {

    for (Wall wall: levels[activeLevel].walls) {
        wall.draw(mainWindow);
    }

    player.draw(mainWindow);
}


bool Game::checkCollision(const sf::Sprite &sprite1, const sf::Sprite &sprite2) {
    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();

    return bounds1.intersects(bounds2);
}






#include <iostream>
#include "Game.h"
#include "Player.h"
#include "Items/Ruppes.h"
#include "Items/HealHeart.h"


Game::Game(sf::RenderWindow &window) : mainWindow(window), ui(6, 5) {
    //mainWindow.create(sf::VideoMode(screenWidth, screenHeight), "The copy of Zelda");
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
                activeLevel = worldMap.getLevel();
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
    activeLevel = worldMap.getLevel();
}



//Update
void Game::updateObjects() {

    int x = player.getSprite().getPosition().x;
    int y = player.getSprite().getPosition().y;


    //Change level
    if(checkLevelChange())
    {
        changeLevel();
    }

    //Player move and Wall collision
    if(checkBorderCollision(x, y) || anyWallCollisionPlayer()) {
        player.negativeUpdate();
    } else {
        //Player move
        player.update();
    }

    //Enemy move and Wall collision
    for (size_t idx=0; idx<activeLevel.enemies.size(); idx++) {
        if(checkBorderCollision(activeLevel.enemies[idx]->getSprite().getPosition().x, activeLevel.enemies[idx]->getSprite().getPosition().y)
                || anyWallCollisionEnemy(idx)) {
            activeLevel.enemies[idx]->negativeUpdate();
            activeLevel.enemies[idx]->changeDirection();
        } else {
            //Enemy move
            activeLevel.enemies[idx]->update();
        }
    }

    //Teleport collision
    if(checkCollision(player.getSprite(),activeLevel.teleport.getSprite())) {
        if(activeLevel.teleport.getDirection() == 'D') {
            worldMap.changeActiveLevel(0,0,-1);
        } else {
            worldMap.changeActiveLevel(0,0,1);
        }
        player.setPosition(activeLevel.teleport.getTpX(), activeLevel.teleport.getTpY());
        activeLevel = worldMap.getLevel();
    }

    //Pick items
    pickUpItems(x, y);

    //Use item
    updateSwords();

    //Sword collision
    dmgController();

    //Update ui
    ui.update(player.getMaxHp(), player.getHp(), player.getMoney());

}

//Draw
void Game::drawObjects() {


    activeLevel.teleport.draw(mainWindow);

    for (size_t idx=0; idx<activeLevel.floors.size(); idx++) {
        activeLevel.floors[idx]->draw(mainWindow);
    }

    for (size_t idx=0; idx<activeLevel.walls.size(); idx++) {
        activeLevel.walls[idx]->draw(mainWindow);
    }


    drawSwords();

    for (size_t idx=0; idx<activeLevel.pickUps.size(); idx++) {
        activeLevel.pickUps[idx]->draw(mainWindow);
    }

    for (size_t idx=0; idx<activeLevel.enemies.size(); idx++) {
        activeLevel.enemies[idx]->draw(mainWindow);
    }

    player.draw(mainWindow);
    ui.draw(mainWindow);
}


bool Game::checkCollision(const sf::Sprite &sprite1, const sf::Sprite &sprite2) {
    sf::FloatRect bounds1 = sprite1.getGlobalBounds();
    sf::FloatRect bounds2 = sprite2.getGlobalBounds();

    return bounds1.intersects(bounds2);
}

bool Game::anyWallCollisionPlayer() {
    bool anyWallCollision = false;


    sf::Sprite playerSprite = player.getSprite();

    for (size_t idx=0; idx<activeLevel.walls.size(); idx++) {
        if(Game::checkCollision(playerSprite , activeLevel.walls[idx]->getSprite())){
            anyWallCollision = true;
            break;
        }
    }

    return anyWallCollision;
}

bool Game::anyWallCollisionEnemy(int idx) {
    bool anyWallCollision = false;


    sf::Sprite enemySprite = activeLevel.enemies[idx]->getSprite();

    for (size_t idx=0; idx<activeLevel.walls.size(); idx++) {
        if(Game::checkCollision(enemySprite , activeLevel.walls[idx]->getSprite())){
            anyWallCollision = true;
            break;
        }
    }

    return anyWallCollision;
}

bool Game::checkBorderCollision(int x, int y) {

    if(x < 16 || y < 64 || x > screenWidth-30 || y > screenHeight-30) {
        return true;
    }
    return false;
}

void Game::changeLevel() {
    int lastMove = player.getLastMove();

    player.changeLevelPos();

    if (lastMove == 1) {
        worldMap.changeActiveLevel(0,-1,0);
    } else if (lastMove == 2) {
        worldMap.changeActiveLevel(0,1,0);

    } else if (lastMove == 3) {
        worldMap.changeActiveLevel(-1,0,0);

    } else {
        worldMap.changeActiveLevel(1,0,0);
    }

    for (size_t idx=0; idx<activeLevel.enemies.size(); idx++) {
        activeLevel.enemies[idx]->resetPosition();
    }

    activeLevel = worldMap.getLevel();
}

bool Game::checkLevelChange() {
    int x = player.getSprite().getPosition().x;
    int y = player.getSprite().getPosition().y;


    if (y == 70) {
        return true;
    } else if (y == screenHeight - 32) {
        return true;
    } else if ( x == 32) {
        return true;
    } else if (x == screenWidth - 32) {
        return true;
    }

    return false;

}

void Game::updateSwords() {

    if (basicSword.getIsActive()) {
        basicSword.hide();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            basicSword.show(player.getSprite().getPosition().x, player.getSprite().getPosition().y, player.getLastMove());
        }
    }

    if (upgradeSword.getIsActive()) {
        upgradeSword.hide();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            upgradeSword.show(player.getSprite().getPosition().x, player.getSprite().getPosition().y, player.getLastMove());
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
        upgradeSword.setIsActive(true);
        basicSword.setIsActive(false);
    }
}

void Game::drawSwords() {
    if(basicSword.getIsActive()) {
        basicSword.draw(mainWindow);
    }

    if(upgradeSword.getIsActive()) {
        upgradeSword.draw(mainWindow);
    }
}

void Game::pickUpItems(int x, int y) {
    std::vector<size_t> indicesToRemove;

    for (size_t idx=0; idx<activeLevel.pickUps.size(); idx++) {
        //Shop
        if(activeLevel.pickUps[idx]->isPurchasable()) {
            if (checkCollision(activeLevel.pickUps[idx]->getSprite(), player.getSprite())) {
                if (activeLevel.pickUps[idx]->getValue() <= player.getMoney()) {
                    activeLevel.pickUps[idx]->setPurchasable(false);
                    activeLevel.pickUps[idx]->setPickable(true);
                    player.setMoney(player.getMoney() - activeLevel.pickUps[idx]->getValue());
                }
            }
        }

        //PickUp
        if(activeLevel.pickUps[idx]->isPickable()) {
            if(checkCollision(activeLevel.pickUps[idx]->getSprite(), player.getSprite())) {
                if (activeLevel.pickUps[idx]->getTag() == "Rupees") {
                    player.setMoney(player.getMoney() + activeLevel.pickUps[idx]->pickUp());
                    indicesToRemove.push_back(idx);
                } else if (activeLevel.pickUps[idx]->getTag() == "Heal") {
                    if(!(player.getHp() >= player.getMaxHp())) {
                        player.setHp(player.getHp() + activeLevel.pickUps[idx]->pickUp());
                        indicesToRemove.push_back(idx);
                    }
                } else if (activeLevel.pickUps[idx]->getTag() == "MaxHeart") {
                    player.setMaxHp(player.getMaxHp() + activeLevel.pickUps[idx]->pickUp());
                    indicesToRemove.push_back(idx);
                }
            }
        }
    }

    for (auto it = indicesToRemove.rbegin(); it != indicesToRemove.rend(); ++it) {
        activeLevel.pickUps.erase(activeLevel.pickUps.begin() + *it);
        worldMap.getLevel().pickUps.erase(worldMap.getLevel().pickUps.begin() + *it);
    }
}

void Game::dmgController() {
    for (size_t idx=0; idx<activeLevel.enemies.size(); idx++) {
        //Basic sword
        if(checkCollision(basicSword.getSprite(), activeLevel.enemies[idx]->getSprite())) {
            if(activeLevel.enemies[idx]->getImmortalFrames() ==  activeLevel.enemies[idx]->getMaxImmortalFrames()) {
                activeLevel.enemies[idx]->setImmortalFrames(0);
            } else if(activeLevel.enemies[idx]->getImmortalFrames() == 0) {
                activeLevel.enemies[idx]->takeDmg(basicSword.getDamage());
                activeLevel.enemies[idx]->setImmortalFrames(1);
            } else {
                activeLevel.enemies[idx]->setImmortalFrames(activeLevel.enemies[idx]->getImmortalFrames() + 1);
            }
        }
        //Upgraded sword
        if(checkCollision(upgradeSword.getSprite(), activeLevel.enemies[idx]->getSprite())) {
            if (activeLevel.enemies[idx]->getImmortalFrames() == activeLevel.enemies[idx]->getMaxImmortalFrames()) {
                activeLevel.enemies[idx]->setImmortalFrames(0);
            } else if (activeLevel.enemies[idx]->getImmortalFrames() == 0) {
                activeLevel.enemies[idx]->takeDmg(upgradeSword.getDamage());
                activeLevel.enemies[idx]->setImmortalFrames(1);
            } else {
                activeLevel.enemies[idx]->setImmortalFrames(activeLevel.enemies[idx]->getImmortalFrames() + 1);
            }
        }

        // Player dmg
        if(checkCollision(player.getSprite(), activeLevel.enemies[idx]->getSprite())) {
            if(player.getImmortalFrames() ==  player.getMaxImmortalFrames()) {
                player.setImmortalFrames(0);
            } else if(player.getImmortalFrames() == 0) {
                player.takeDmg(activeLevel.enemies[idx]->getDmg());
                player.setImmortalFrames(1);
            } else {
                player.setImmortalFrames(player.getImmortalFrames() + 1);
            }
        }

        //Enemy die
        if(activeLevel.enemies[idx]->getHp() <= 0) {
            //Heal enemy
            worldMap.getLevel().enemies[idx]->setHp(activeLevel.enemies[idx]->getMaxHp());


            //Drop
            int x = activeLevel.enemies[idx]->getSprite().getPosition().x;
            int y = activeLevel.enemies[idx]->getSprite().getPosition().y;

            int drop = rand() % 100 + 1;

            if(drop <= 30) {
                activeLevel.pickUps.push_back(std::make_shared<Ruppes>("g-rupees", true, false, false,"Rupees", 1, x, y));
                worldMap.getLevel().pickUps.push_back(std::make_shared<Ruppes>("g-rupees", true, false, false,"Rupees", 1, x, y));
            } else if (drop > 31 && drop <= 50) {
                activeLevel.pickUps.push_back(std::make_shared<HealHeart>("halfheal", true, false, false, "Heal", 1, x, y));
                worldMap.getLevel().pickUps.push_back(std::make_shared<Ruppes>("halfheal", true, false, false,"Heal", 1, x, y));
            } else if (drop > 51 && drop <= 65) {
                activeLevel.pickUps.push_back(std::make_shared<HealHeart>("heal", true, false, false, "Heal", 2, x, y));
                worldMap.getLevel().pickUps.push_back(std::make_shared<Ruppes>("heal", true, false, false,"Heal", 2, x, y));
            } else if(drop > 66 && drop <= 75) {
                activeLevel.pickUps.push_back(std::make_shared<Ruppes>("b-rupees", true, false, false,"Rupees", 3, x, y));
                worldMap.getLevel().pickUps.push_back(std::make_shared<Ruppes>("b-rupees", true, false, false,"Rupees", 3, x, y));
            } else if(drop > 76 && drop <= 85) {
                activeLevel.pickUps.push_back(std::make_shared<Ruppes>("r-rupees", true, false, false,"Rupees", 5, x, y));
                worldMap.getLevel().pickUps.push_back(std::make_shared<Ruppes>("r-rupees", true, false, false,"Rupees", 5, x, y));
            }

            //Reset Position
            activeLevel.enemies[idx]->resetPosition();
            //Erase enemy
            activeLevel.enemies.erase(activeLevel.enemies.begin() + idx);
        }

        //Player die
        if(player.getHp() <= 0) {
            player.reset();
            worldMap.resetLevel();
            activeLevel = worldMap.getLevel();
        }
    }
}






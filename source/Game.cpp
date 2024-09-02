#include "Game.h"

Game::Game():window(sf::VideoMode(800, 600), "SFML works!"), player(window), enemy(window, 1){
	initializeVar();
}

void Game::eventsLoop() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
void Game::update() {
    bool updated = false;

    for (unsigned int i = 0; i < plataforms.size(); ++i) {
        if (player.sprite.getGlobalBounds().intersects(plataforms[i].sprite.getGlobalBounds())) {
            player.update(plataforms[i]);

            updated = true;
            break;
        }
    }


    if (!updated) {
        player.update(Plataform());
    }

    bool enemyUpdates = false;

    for (unsigned int i = 0; i < plataforms.size(); ++i) {
        if (enemy.sprite.getGlobalBounds().intersects(plataforms[i].sprite.getGlobalBounds())) {
            enemy.update(plataforms[i]);

            updated = true;
            break;
        }
    }

    if (!enemyUpdates) {
        enemy.update(Plataform());
    }

}

void Game::draw() {
	window.clear();
	window.draw(player.sprite);
	for (unsigned int i = 0; i < plataforms.size(); ++i){

		if(i == 0){
			plataforms[i].setSprite("assets/floor.png");
		}else{
		plataforms[i].setSprite("assets/plataform.png");
		}

		window.draw(plataforms[i].sprite);

	}

	window.draw(enemy.sprite);
	window.display();
}


void Game::run() {
	while (window.isOpen()) {
		eventsLoop();
		update();
		draw();
	}
}

void Game::initializeVar() {
	window.setVerticalSyncEnabled(1);
	Plataform floor;
	floor.setSprite("assets/floor.png");
	floor.setPosition(0, window.getSize().y - floor.getHeight());
	plataforms.push_back(floor);

	enemy.setSprite("assets/koopa.png");
	enemy.setPosition(50, 110 - enemy.getHeight() * 0.5);

	player.setPosition(window.getSize().x * 0.5, window.getSize().y - floor.getHeight() - (player.getHeight() * 0.5));
	setPlataforms();



}

void Game::setPlataforms(){
	Plataform newPlaform;
	newPlaform.setPosition(-111, 435);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 111, 435);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x * 0.5 - newPlaform.getWidht() * 0.5, 230);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(-259, 300);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 259, 300);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(-74, 110);
	plataforms.push_back(newPlaform);

	newPlaform.setSprite("assets/plataform.png");
	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 74, 110);
	plataforms.push_back(newPlaform);

}

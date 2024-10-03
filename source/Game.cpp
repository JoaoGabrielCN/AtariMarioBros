#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML works!"), player(window){
	initializeVar();
}


void Game::eventsLoop() { // loop de eventos
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update() {
	bool playerUpdated = false;

	for (unsigned int i = 0; i < plataforms.size(); ++i) {
		if (player.sprite.getGlobalBounds().intersects(plataforms[i].sprite.getGlobalBounds())) {
			player.update(plataforms[i]);
			playerUpdated = true;
			break;
		}
	}

	if (!playerUpdated) {
		player.update(Plataform());
	}

	for (unsigned int i = 0; i < enemies.size(); ++i) {
		bool enemyUpdated = false;

		for (unsigned int j = 0; j < plataforms.size(); ++j) {
			if (enemies[i].sprite.getGlobalBounds().intersects(plataforms[j].sprite.getGlobalBounds())) {
				enemies[i].update(plataforms[j]);
				enemyUpdated = true;
				break;
			}
		}

		player.testCollisionEnemy(enemies[i]);

		for (unsigned int j = 0; j < plataforms.size(); ++j) {
			if (player.belowPlataform) {
				player.killEnemy(plataforms[j], enemies[i]);
			}
		}
		if (!enemyUpdated) {
			enemies[i].update(Plataform());
		}

		if (enemies[i].downed) {
			enemies[i].getUp();
		}

		for (unsigned int j = 0; j < enemies.size(); ++j) {
			if (i != j) {
				enemies[i].testEnemyCollsion(enemies[j]);

			}

		}

		pipes[0].testEnemyCollision(enemies[i], pipes[2]);
		pipes[1].testEnemyCollision(enemies[i], pipes[3]);
	}

}

void Game::draw() {

if(!pause()){
		window.clear();
		for(unsigned int i = 0; i < pipes.size(); i++){
			window.draw(pipes[i].sprite);
		}

		for (unsigned int i = 0; i < plataforms.size(); ++i) {
			window.draw(plataforms[i].sprite);
		}

		for (unsigned int i = 0; i < enemies.size(); ++i) {
			window.draw(enemies[i].sprite);
		}

		window.draw(player.sprite);

		window.display();

	}
}

void Game::setPipes() {
	Pipe newPipe(pipeTexture);

	newPipe.setPosition(0, window.getSize().y - plataforms[0].getHeight() - newPipe.getHeight()- 20);
	newPipe.setScale(1);
	pipes.push_back(newPipe);


	newPipe.setPosition(window.getSize().x, window.getSize().y - plataforms[0].getHeight() - newPipe.getHeight()- 20);
	newPipe.setScale(-1);
	pipes.push_back(newPipe);

	newPipe.setPosition(0, plataforms[6].getY() - newPipe.getHeight()- 20);
	newPipe.setScale(1);
	pipes.push_back(newPipe);

	newPipe.setPosition(window.getSize().x, plataforms[6].getY() - newPipe.getHeight()- 20);
	newPipe.setScale(-1);
	pipes.push_back(newPipe);
}

bool Game::pause() {
	if(!player.alive){
		return true;
	}

	int cont = 0;

	for (unsigned int i = 0; i < enemies.size(); ++i) {
		if(!enemies[i].alive){
			cont ++;
		}
	}

	if(cont == static_cast<int>(enemies.size())){
		return true;
	}

	return false;
}

void Game::run() {
	while (window.isOpen()) {
		eventsLoop();
		update();
		draw();
	}
}

void Game::initializeVar() {
	window.setVerticalSyncEnabled(true); // ativa VSync
	window.setFramerateLimit(200);


	enemyTexture.loadFromFile("assets/koopa.png");
	plataformsTexture.loadFromFile("assets/plataform.png");
	floorTexture.loadFromFile("assets/floor.png");
	pipeTexture.loadFromFile("assets/pipe.png");

	Plataform floor(floorTexture);

	floor.setPosition(0, window.getSize().y - floor.getHeight());
	plataforms.push_back(floor);

	player.setPosition(window.getSize().x * 0.5,window.getSize().y - floor.getHeight() - (player.getHeight() * 0.5));

	setPlataforms();
	setEnemies();
	setPipes();



}

void Game::setEnemies() { //cria os inimigos e os adiciona em um vector

	Enemy newEnemy(window, 1, enemyTexture);

	newEnemy.setPosition(50, 110 - newEnemy.getHeight() * 0.5);
	enemies.push_back(newEnemy);

	newEnemy.setPosition(700, 110 - newEnemy.getHeight() * 0.5);
	newEnemy.setDirection(-1);
	enemies.push_back(newEnemy);

	newEnemy.setPosition(window.getSize().x * 0.5, 230 - newEnemy.getHeight() * 0.5);
	newEnemy.setDirection(1);
	enemies.push_back(newEnemy);

}

void Game::setPlataforms() { // cria todas as plataformas e os adiciona em um vector
	Plataform newPlaform(plataformsTexture);


	newPlaform.setPosition(-111, 425);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 111, 425);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(window.getSize().x * 0.5 - newPlaform.getWidht() * 0.5, 220);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(-259, 310);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 259, 310);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(-74, 110);
	plataforms.push_back(newPlaform);

	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 74,110);
	plataforms.push_back(newPlaform);
}

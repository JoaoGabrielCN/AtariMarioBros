#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML works!"), player(window) {
	initializeVar();
}

void Game::run() {
	while (window.isOpen()) {
		eventsLoop();
		update();
		draw();
	}

}

void Game::eventsLoop() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		if(pause()) testRestartClick();
	}


}

void Game::update() {
	if (pause()) {
		return;
	}

	bool playerUpdated = false;

	for (unsigned int i = 0; i < plataforms.size(); ++i) {
		if (player.sprite.getGlobalBounds().intersects(plataforms[i].sprite.getGlobalBounds())) {
			player.update(plataforms[i]);
			playerUpdated = true;
			break;
		}
	}

	if (player.sprite.getGlobalBounds().intersects(powButton.sprite.getGlobalBounds())) {
		player.update(powButton);
		playerUpdated = true;

		if (player.belowPlataform) {
			for (unsigned int i = 0; i < enemies.size(); ++i) {
				enemies[i].downed = true;
				powButton.lifes--;
				powSound.play();
			}
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
				player.downEnemy(plataforms[j], enemies[i]);
			}
		}
		if (!enemyUpdated) {
			enemies[i].update(Plataform());
		}

		if (enemies[i].downed) {
			enemies[i].getUp();
		}
		for (unsigned int j = 0; j < enemies.size(); ++j) {
				enemies[i].testEnemyCollsion(enemies[j]);

		}

		pipes[0].pipeTravel(enemies[i], pipes[2]);
		pipes[1].pipeTravel(enemies[i], pipes[3]);
	}

	powButton.update();
}

void Game::draw() {
	window.clear();


	if (!pause()) {

		window.draw(backgroundSprite);
		for (unsigned int i = 0; i < pipes.size(); i++) {
			window.draw(pipes[i].sprite);
		}

		for (unsigned int i = 0; i < plataforms.size(); ++i) {
			window.draw(plataforms[i].sprite);
		}

		for (unsigned int i = 0; i < enemies.size(); ++i) {
			window.draw(enemies[i].sprite);
		}

		window.draw(player.sprite);
		window.draw(powButton.sprite);

		window.display();
	} else {

		if(!playSound){
		if(player.alive){
			resultMusic.openFromFile("assets/win.wav");
		}else{
			resultMusic.openFromFile("assets/loose.wav");
		}

			resultMusic.play();
			playSound = true;



		}
		result.setPosition(window.getSize().x / 2 - result.getGlobalBounds().width / 2, 310);
		theme.stop();
		window.clear();
		window.draw(gameOverText);
		window.draw(result);
		window.draw(restartButton);
		window.draw(restartButtonText);
		window.display();
	}
}

bool Game::pause() {



	if (!player.alive) {
		result.setString("Voce Perdeu!");
		result.setFillColor(sf::Color::Red);
		resultSound.setBuffer(bufferResult);
		return true;
	}

	int cont = 0;
	for (unsigned int i = 0; i < enemies.size(); ++i) {
		if (!enemies[i].alive) {
			cont++;
		}
	}

	if (cont == static_cast<int>(enemies.size())) {
		result.setString("Voce Ganhou!");
		result.setFillColor(sf::Color::Green);
		resultSound.setBuffer(bufferResult);
		return true;
	}

	return false;
}

void Game::initializeVar() {
	window.setVerticalSyncEnabled(true); // ativa VSync
	window.setFramerateLimit(200);

	playSound = false;

	setTextures();
	setSounds();
	setTexts();

	Plataform floor(floorTexture);
	floor.setPosition(0, window.getSize().y - floor.getHeight());
	plataforms.push_back(floor);

	powButton.setTexture(powTexture);
	powButton.setPosition(window.getSize().x * 0.5 - powButton.getWidht() * 0.5, 410);

	player.setPosition(window.getSize().x * 0.5, window.getSize().y - floor.getHeight() - (player.getHeight() * 0.5));

	setPlataforms();
	setEnemies();
	setPipes();
}

void Game::setEnemies() {
	Enemy newEnemy(window, 1, enemyTexture);

	newEnemy.setPosition(25, 110 - newEnemy.getHeight() * 0.5);
	enemies.push_back(newEnemy);

	newEnemy.setPosition(700, 110 - newEnemy.getHeight() * 0.5);
	newEnemy.setDirection(-1);
	enemies.push_back(newEnemy);

	newEnemy.setPosition(window.getSize().x * 0.5 + 150, 230 - newEnemy.getHeight() * 0.5);
	newEnemy.setDirection(1);
	enemies.push_back(newEnemy);


	newEnemy.setPosition(window.getSize().x * 0.5 - 50, 230 - newEnemy.getHeight() * 0.5);
	newEnemy.setDirection(-1);
	enemies.push_back(newEnemy);
}

void Game::setPlataforms() {
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

	newPlaform.setPosition(window.getSize().x - newPlaform.getWidht() + 74, 110);
	plataforms.push_back(newPlaform);
}

void Game::setPipes() {
	Pipe newPipe(pipeTexture);

	newPipe.setPosition(0, window.getSize().y - plataforms[0].getHeight() - newPipe.getHeight() - 20);
	newPipe.setScale(1);
	pipes.push_back(newPipe);

	newPipe.setPosition(window.getSize().x, window.getSize().y - plataforms[0].getHeight() - newPipe.getHeight() - 20);
	newPipe.setScale(-1);
	pipes.push_back(newPipe);

	newPipe.setPosition(0, plataforms[6].getY() - newPipe.getHeight() - 20);
	newPipe.setScale(1);
	pipes.push_back(newPipe);

	newPipe.setPosition(window.getSize().x, plataforms[6].getY() - newPipe.getHeight() - 20);
	newPipe.setScale(-1);
	pipes.push_back(newPipe);
}

void Game::setTextures() {
	enemyTexture.loadFromFile("assets/koopa_sprites.png");
	plataformsTexture.loadFromFile("assets/plataform.png");
	floorTexture.loadFromFile("assets/floor.png");
	pipeTexture.loadFromFile("assets/pipe_2.png");
	powTexture.loadFromFile("assets/pow.png");
	backgroundTexture.loadFromFile("assets/background.png");
	backgroundSprite.setTexture(backgroundTexture);
}

void Game::setSounds() {
	theme.openFromFile("assets/theme_song.wav");
	theme.setVolume(30);
	theme.setLoop(true);
	theme.play();



	bufferPow.loadFromFile("assets/pow_sound.wav");
	powSound.setBuffer(bufferPow);
}

void Game::testRestartClick() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		resetGame();
	}
}

void Game::resetGame() {
	    player.alive = true;
	    player.setPosition(window.getSize().x * 0.5, window.getSize().y - plataforms[0].getHeight() - player.getHeight() * 0.5);

	    enemies.clear();
	    plataforms.clear();
	    pipes.clear();

	   playSound = false;

	    Plataform floor(floorTexture);
	   	floor.setPosition(0, window.getSize().y - floor.getHeight());
	   	plataforms.push_back(floor);

	   	playSound = false;
	   	powButton.reset();
	    powButton.setTexture(powTexture);
	    powButton.setPosition(window.getSize().x * 0.5 - powButton.getWidht() * 0.5, 410);

	    setPlataforms();
	    setEnemies();
	    setPipes();

	    theme.play();

	    draw();
	}



void Game::setTexts(){

	font.loadFromFile("assets/font.ttf");
	gameOverText.setFont(font);
	gameOverText.setString("Fim de jogo");
	gameOverText.setCharacterSize(50);
	gameOverText.setFillColor(sf::Color::White);
	gameOverText.setPosition(window.getSize().x / 2 - gameOverText.getGlobalBounds().width / 2, 150);

	restartButtonText.setFont(font);
	restartButtonText.setString("Pressione Enter para reiniciar");
	restartButtonText.setCharacterSize(30);
	restartButtonText.setFillColor(sf::Color::White);
	restartButtonText.setPosition(window.getSize().x / 2 - restartButtonText.getGlobalBounds().width / 2, 480);

	result.setFont(font);
	result.setCharacterSize(50);


}

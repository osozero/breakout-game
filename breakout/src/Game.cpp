#include "Game.h"

Game::Game(GLuint _width, GLuint _height)
	:State(GAME_ACTIVE),Keys(),Width(_width),Height(_height)
{
}

Game::~Game()
{
}

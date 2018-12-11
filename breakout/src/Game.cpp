#include "Game.h"

Game::Game(GLuint _width, GLuint _height)
	:State(GAME_ACTIVE),Keys(),Width(_width),Height(_height)
{
}

Game::~Game()
{
}

void Game::Init()
{
}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Update(GLfloat)
{
}

void Game::Render()
{
}

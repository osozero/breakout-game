#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"

Game::Game(GLuint _width, GLuint _height)
	:State(GAME_ACTIVE),Keys(),Width(_width),Height(_height),Renderer(nullptr)
{
}

Game::~Game()
{
	delete this->Renderer;
	this->Renderer = nullptr;
}

void Game::Init()
{
	ResourceManager::LoadShader("shader/main.vert", "shader/main.frag",nullptr,"sprite");

	glm::mat4 proj = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);

	ResourceManager::GetShader("sprite").Use().SetInteger("image",0);
	ResourceManager::GetShader("sprite").SetMatrix4("projection", proj);

	this->Renderer = new SpriteRenderer(ResourceManager::GetShader("sprite"));

	ResourceManager::LoadTexture("resources/textures/basketball.png", GL_TRUE, "ball");

}

void Game::ProcessInput(GLfloat dt)
{
}

void Game::Update(GLfloat)
{
}

void Game::Render()
{
	this->Renderer->DrawSprite(ResourceManager::GetTexture("ball"),
		glm::vec2(200, 200), glm::vec2(300, 400), 45.0f, glm::vec3(0.0f, 1.0f, 0.0f));
}

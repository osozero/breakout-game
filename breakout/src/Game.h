#pragma once


#include "Debug.h"
#include <GLFW/glfw3.h>
#include "SpriteRenderer.h"

enum GameState
{
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};



class Game
{
public:
	GameState	State;
	GLboolean	Keys[1024];
	GLuint	Width, Height;
	SpriteRenderer *Renderer;
	Game()=delete;
	Game(GLuint _width, GLuint _height);
	~Game();

	void Init();

	void ProcessInput(GLfloat dt);
	void Update(GLfloat);
	void Render();
};


#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
	Game()=delete;
	Game(GLuint _width, GLuint _height);
	~Game();

	void Init();

	void ProcessInput(GLfloat dt);
	void Update(GLfloat);
	void Render();
};


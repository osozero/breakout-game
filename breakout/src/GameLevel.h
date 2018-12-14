#pragma once
#include <vector>
#include "GameObject.h"

class GameLevel
{
public:
	std::vector<GameObject> Bricks;

	GameLevel();
	~GameLevel();

	void Load(const GLchar *file, GLuint levelWidth, GLuint levelHeight);

	void Draw(SpriteRenderer &renderer);

	GLboolean IsCompleted();

private:
	void Init(std::vector<std::vector<GLuint>> tileData, GLuint levelWidth, GLuint levelHeight);

};


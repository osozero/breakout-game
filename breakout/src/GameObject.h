#pragma once
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/vec2.hpp>
#include "Texture.h"
#include "SpriteRenderer.h"

class GameObject
{
public:
	glm::vec2   Position, Size, Velocity;
	glm::vec3   Color;
	GLfloat     Rotation;
	GLboolean   IsSolid;
	GLboolean   Destroyed;

	Texture Sprite;

	virtual void Draw(SpriteRenderer &renderer);

	GameObject();

	GameObject(glm::vec2 pos, glm::vec2 size, Texture sprite, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

	~GameObject();
	
};


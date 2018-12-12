#pragma once

#include "Shader.h"
#include "Texture.h"
#include <glm/vec2.hpp>

class SpriteRenderer
{
public:
	SpriteRenderer(Shader &shader);
	~SpriteRenderer();

	void DrawSprite(Texture &texture, glm::vec2 position,
		glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f,
		glm::vec3 color = glm::vec3(1.0f));

private:
	Shader shader_;
	GLuint vao_;

	void initRendererData();


};


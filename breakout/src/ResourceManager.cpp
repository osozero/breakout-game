#include "ResourceManager.h"



ResourceManager::ResourceManager()
{
}


Shader ResourceManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile,
	std::string name)
{
}

Shader ResourceManager::GetShader(std::string name)
{
}

Texture ResourceManager::LoadTexture(const GLchar* file, GLboolean alpha, std::string name)
{
}

Texture ResourceManager::GetTexture(std::string name)
{
}

void ResourceManager::Clear()
{
}

Shader ResourceManager::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile,
	const GLchar* gShaderFile)
{
}

Texture ResourceManager::loadImageFromFile(const GLchar* file, GLboolean alpha)
{
}

ResourceManager::~ResourceManager()
{
}

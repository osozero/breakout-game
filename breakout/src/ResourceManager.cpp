#define STB_IMAGE_IMPLEMENTATION

#include "ResourceManager.h"
#include <fstream>
#include <sstream>
#include "stb_image/stb_image.h"


std::map<std::string, Shader> ResourceManager::Shaders;
std::map<std::string, Texture> ResourceManager::Textures;

ResourceManager::ResourceManager()
{
}


Shader ResourceManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile,
	std::string name)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);

	return Shaders[name];
}

Shader& ResourceManager::GetShader(std::string name)
{
	return Shaders[name];
}

Texture ResourceManager::LoadTexture(const GLchar* file, GLboolean alpha, std::string name)
{
	Textures[name] = loadImageFromFile(file, alpha);
	return Textures[name];
}

Texture& ResourceManager::GetTexture(std::string name)
{
	return Textures[name];
}

void ResourceManager::Clear()
{
	for(auto s:Shaders)
	{
		glDeleteShader(s.second.ID);
	}

	for(auto t:Textures)
	{
		glDeleteTextures(1, &t.second.ID);
	}
}

Shader ResourceManager::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile,
	const GLchar* gShaderFile)
{
	std::string vertexSource, fragmentSource, geometrySource;
	try
	{
		vertexSource = read_from_file(vShaderFile);
		fragmentSource = read_from_file(fShaderFile);
		
		if (gShaderFile != nullptr)
		{
			geometrySource = read_from_file(gShaderFile);
		}
		
	}catch (std::exception &e)
	{
		std::cout << "ERROR::SHADER::FILE: Failed to read shader files, error: " << e.what() << std::endl;
	}

	const auto vShaderCode = vertexSource.c_str();
	const auto fShaderCode = fragmentSource.c_str();
	const GLchar *gShaderCode = nullptr;
	
	if (gShaderFile != nullptr)
	{
		gShaderCode = geometrySource.c_str();
	}

	Shader shader;
	shader.Compile(vShaderCode, fShaderCode, gShaderCode);

	return shader;



}

Texture ResourceManager::loadImageFromFile(const GLchar* file, GLboolean alpha)
{
	Texture texture;

	if(alpha)
	{
		stbi_set_flip_vertically_on_load(true);
		texture.ImageFormat = GL_RGBA;
		texture.InternalFormat = GL_RGBA;
	}

	int width, height,nrChannels;

	 auto image = stbi_load(file, &width, &height, &nrChannels,GL_RGBA);

	if(image==nullptr)
	{
		std::cout << "Image could not be loaded from path: "
			<< file << std::endl;
		exit(-1);
	}

	texture.Generate(width, height, image);
	stbi_image_free(image);

	return texture;
}

std::string ResourceManager::read_from_file(const GLchar* file)
{
	std::ifstream ifstreamFile(file);
	std::stringstream sstr;

	sstr << ifstreamFile.rdbuf();
	return sstr.str();
}

ResourceManager::~ResourceManager()
{
}

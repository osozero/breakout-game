#include "Debug.h"
#include <GLFW/glfw3.h>
#include "Game.h"
#include "ResourceManager.h"


void keyCallback(GLFWwindow *window, int key, int keyCode, int action, int mode);

const GLuint SCREEN_WIDTH = 800;
const GLuint SCREEN_HEIGHT = 600;

Game Breakout(SCREEN_WIDTH, SCREEN_WIDTH);

int main()
{
	//GLFW init

	auto initResult = glfwInit();

	if(initResult!=GL_TRUE)
	{
		std::cout << "GLFW could not be initialized" << std::endl;
		exit(-1);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow *window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", nullptr, nullptr);

	if(window==nullptr)
	{
		std::cout << "Window could not be created" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	glfwMakeContextCurrent(window);

	auto glewInitResult = glewInit();

	if(glewInitResult!=GLEW_OK)
	{
		std::cout << "GLEW could not be initialized" << std::endl;
		glfwTerminate();
		exit(-1);
	}

	//eliminates first error because of glewInit()
	glGetError();

	glfwSetKeyCallback(window, keyCallback);

	GLCall(glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT));

	GLCall(glEnable(GL_BLEND));
	GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCall(glEnable(GL_CULL_FACE));

	Breakout.Init();

	GLfloat deltaTime = 0.0f;
	GLfloat lastFrame = 0.0f;

	Breakout.State = GAME_ACTIVE;

	while(!glfwWindowShouldClose(window))
	{
		const auto currentFrame = glfwGetTime();
		
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		glfwPollEvents();

		Breakout.ProcessInput(deltaTime);

		Breakout.Update(deltaTime);

		GLCall(glClearColor(0.0f, 0.0f, 0.0f, 1.0f));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		Breakout.Render();

		glfwSwapBuffers(window);
	}


	ResourceManager::Clear();

	glfwTerminate();

	return 0;
}

void keyCallback(GLFWwindow* window, int key, int keyCode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
			Breakout.Keys[key] = GL_TRUE;
		else if (action == GLFW_RELEASE)
			Breakout.Keys[key] = GL_FALSE;
	}
}

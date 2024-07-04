#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


Window::Window(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;

	InitializeGLFW();
	CreateWindow();
	InitializeGlad();
};

Window::Window(int width, int height, const char* title, int glMajorVersion, int glMinorVersion)
{
	m_width = width;
	m_height = height;
	m_title = title;
	int m_glMajorVersion = glMajorVersion;
	int m_glMinorVersion = glMinorVersion;

	
	InitializeGLFW();
	CreateWindow();
	InitializeGlad();
};

int Window::InitializeGlad() 
{
	//Config Gload
	int result = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	if (!result)
	{
		std::cout << "Glad Load Failed" << std::endl;
		return -1;
	}

	return 1;
};

int Window::InitializeGLFW() 
{
	//GLFW initiliaziation
	int result = glfwInit();

	if (result == GLFW_TRUE)
		std::cout << "GLFW is initialized" << std::endl;

	//OpenGL version
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, m_glMajorVersion);
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, m_glMinorVersion);
	glfwInitHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return -1;
};

int Window::CreateWindow() 
{
	const int width = m_width;
	const int height = m_height;
	const char* title = m_title;

	//Window Config
	m_window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (m_window == NULL)
	{
		std::cout << "GLFW WINDOW FAILED" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(m_window);
	

	return 1;
};

GLFWwindow* Window::GetWindow() const
{
	return m_window;
}
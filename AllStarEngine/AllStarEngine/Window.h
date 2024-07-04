
#ifndef _WINDOW_H_
#define _WINDOW_H_
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{

public:
	Window(int width, int height, const char* title);
	Window(int width, int height, const char* title, int glMajorVersion, int glMinorVersion);
	GLFWwindow* GetWindow() const;

private:
	int m_glMajorVersion = 3;
	int m_glMinorVersion = 3;

	GLFWwindow* m_window;
	int m_width;
	int m_height;
	const char* m_title;
	
	int InitializeGLFW();
	int CreateWindow();
	int InitializeGlad();
};

#endif 
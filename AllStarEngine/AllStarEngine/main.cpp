#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Window.h"
#include "Shader.h"
#include "Shape.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const char* vertexShaderSource = 
	"#version 330 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"void main()\n"
	"{\n"
	"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
	"}\0";

const char* fragmentShaderSource = 
	"#version 330 core\n"
	"out vec4 FragColor;\n"

	"void main()\n"
	"	{\n"
	"FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
	"}\0";


float vertices[] = {
	0.5f,  0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,  // bottom right
	-0.5f, -0.5f, 0.0f,  // bottom left
	-0.5f,  0.5f, 0.0f   // top left 
};

unsigned int indices[] =
{
	0, 1, 3,
	1, 2, 3
};

const int WIN_WIDTH = 1024;
const int WIN_HEIGHT = 680;
const char* title = "AllstarEngine";


int main() 
{
	Window* window = new Window(WIN_WIDTH, WIN_HEIGHT, title);

	Shader* shader = new Shader(vertexShaderSource, fragmentShaderSource);

	Shape* shape = new Shape(shader, GlDrawType::GLSTATIC_DRAW, vertices, indices, sizeof(vertices), sizeof(indices));

	framebuffer_size_callback(window->GetWindow(), WIN_WIDTH, WIN_HEIGHT);
	glfwSetFramebufferSizeCallback(window->GetWindow(), framebuffer_size_callback);

	//Loop Engine
	while (!glfwWindowShouldClose(window->GetWindow())) 
	{
		processInput(window->GetWindow());
		glClearColor(0.6f, 0.6f, 0.6f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		shader->UseShader();
		shape->Draw();
		glfwSwapBuffers(window->GetWindow());
		glfwPollEvents();		
	}

	shape->deleteRemainig();
	shader->deleteRemainig();
	glfwTerminate();
	return 0;
}


void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
};
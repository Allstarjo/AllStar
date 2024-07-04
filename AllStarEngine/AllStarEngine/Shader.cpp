#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) 
{
	createProgram();
	unsigned int vertexShaderIndex = configureVertexShader(vertexShaderSource);
	unsigned int fragmentShaderIndex = configureFragmentShader(fragmentShaderSource);
	configureShaderProgram(vertexShaderIndex, fragmentShaderIndex);

};

void Shader::UseShader()
{
	glUseProgram(m_shaderProgram);
};

unsigned int Shader::configureVertexShader(const char* vertexShaderSource) 
{
	//Vertex Shader Config
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);

	int success;
	char infoLog[512];

	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);


	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR SHADER" << infoLog << std::endl;
	}

	return vertexShader;
};


unsigned int Shader::configureFragmentShader(const char* fragmentShaderSource) 
{
	int success;
	char infoLog[512];

	//Fragment Shader Config
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	return fragmentShader;
};

void Shader::createProgram()
{
	m_shaderProgram = glCreateProgram();
}

void Shader::configureShaderProgram(unsigned int vertexShaderIndex, unsigned int fragmentShaderIndex) 
{
	//Config Program Shader

	glAttachShader(m_shaderProgram, vertexShaderIndex);
	glAttachShader(m_shaderProgram, fragmentShaderIndex);
	glLinkProgram(m_shaderProgram);

	int success;
	char infoLog[512];

	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR PROGRAM" << infoLog << std::endl;
	}

	glDeleteShader(vertexShaderIndex);
	glDeleteShader(fragmentShaderIndex);

};

void Shader::deleteRemainig()
{
	glDeleteProgram(m_shaderProgram);
}
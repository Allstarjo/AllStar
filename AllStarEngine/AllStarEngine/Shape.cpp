#include "Shape.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


Shape::Shape(Shader* shader, GlDrawType glDrawType, float vertices[], unsigned int indices[], int sizeofVertices, int sizeOfIndices)
{
	m_glDrawType = glDrawType;
	m_shader = CreateRectangle(m_shader, glDrawType, vertices, indices, sizeofVertices, sizeOfIndices);

};

Shader* Shape::CreateRectangle(Shader* shader, GlDrawType glDrawType,
	float vertices[], unsigned int indices[], int sizeofVertices, int sizeOfIndices)
{
	ConfigureVertex(vertices, indices, sizeofVertices, sizeOfIndices);
	return shader;
};


void Shape::Draw()
{
	
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

};

void Shape::ConfigureVertex(float vertices[],unsigned int indices[], int sizeofVertices, int sizeOfIndices)
{	

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeofVertices, vertices, m_glDrawType);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeOfIndices, indices, m_glDrawType);


	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


};

void Shape::deleteRemainig()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}
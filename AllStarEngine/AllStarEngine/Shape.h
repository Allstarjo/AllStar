#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "Shader.h"

enum GlDrawType
{
	GLSTATIC_DRAW = 0x88E4,
	GLDYNAMIC_DRAW = 0x88E8,
	GLSTREAM_DRAW = 0x88E0
};

class Shape
{
public:
	Shape(Shader* shader, GlDrawType glDrawType, float vertices[], unsigned int indices[], float sizeofVertices, float sizeOfIndices);
	Shader* CreateRectangle(Shader* shader, GlDrawType glDrawType, float vertice[],
		unsigned int indices[], float sizeofVertices, float sizeOfIndices);
	void Draw();
	void deleteRemainig();
	void ConfigureVertex(float vertices[], unsigned int indices[], float sizeofVertices, float sizeOfIndices);

private:
	unsigned int VAO, VBO, EBO;
	GlDrawType m_glDrawType;
	Shader* m_shader;
	
};

#endif


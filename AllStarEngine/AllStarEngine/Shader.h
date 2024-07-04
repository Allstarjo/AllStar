#ifndef _SHADER_H_
#define _SHADER_H_

class Shader
{
public:
	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
	void UseShader();
	void deleteRemainig();

private:
	int m_shaderProgram;

	unsigned int configureVertexShader(const char* vertexShaderSource);
	unsigned int configureFragmentShader(const char* fragmentShaderSource);
	void configureShaderProgram(unsigned int vertexShaderIndex, unsigned int fragmentShaderIndex);
	void createProgram();
	
};

#endif;

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <map>
#include "GL/glew.h"
#include "glm/glm.hpp"
using std::string;


class ShaderProgram
{
public:
	 ShaderProgram();
	~ShaderProgram();

	enum ShaderType
	{
		VERTEX,
		FRAGMENT,
		PROGRAM
	};

	// Only supports vertex and fragment
	bool loadShaders(const char* vsFilename, const char* fsFilename);
	void use();

	void setUniform(const GLchar* name, const glm::mat4& m);

	// We are going to speed up looking for uniforms by keeping their locations in a map
	GLint getUniformLocation(const GLchar * name);

private:

	string fileToString(const string& filename);
	void checkCompileErrors(GLuint shader, ShaderType type);

	
	GLuint mHandle;
	std::map<string, GLint> mUniformLocations;
};
#endif // SHADER_H
#include "ShaderProgram.h"
#include <fstream>
#include <iostream>
#include <sstream>

#include <glm/gtc/type_ptr.hpp>

//-----------------------------------------------------------------------------
// Constructor
//-----------------------------------------------------------------------------
ShaderProgram::ShaderProgram()
	: mHandle(0)
{}

//-----------------------------------------------------------------------------
// Destructor
//-----------------------------------------------------------------------------
ShaderProgram::~ShaderProgram()
{
	// Delete the program
	glDeleteProgram(mHandle);
}

//-----------------------------------------------------------------------------
// Loads vertex and fragment shaders
//-----------------------------------------------------------------------------
bool ShaderProgram::loadShaders(const char* vsFilename, const char* fsFilename)
{
	string vsString = fileToString(vsFilename);
	string fsString = fileToString(fsFilename);
	const GLchar* vsSourcePtr = vsString.c_str();
	const GLchar* fsSourcePtr = fsString.c_str();

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vsSourcePtr, NULL);
	glShaderSource(fs, 1, &fsSourcePtr, NULL);

	// Compiling the source code that have been stored on the shader object
	glCompileShader(vs);
	checkCompileErrors(vs, VERTEX);

	glCompileShader(fs);
	checkCompileErrors(fs, FRAGMENT);

	// Creating a program object for the shader to be attached to, return NON-ZERO value if succeeded
	mHandle = glCreateProgram();
	if (mHandle == 0)
	{
		std::cerr << "Unable to create shader program!" << std::endl;
		return false;
	}

	// Attaching the shader object to the program object
	glAttachShader(mHandle, vs);
	glAttachShader(mHandle, fs);

	// Linking them together
	glLinkProgram(mHandle);
	checkCompileErrors(mHandle, PROGRAM);

	// Once linked, we can free the memory used to store the shader source and unlinked object code
	glDeleteShader(vs);
	glDeleteShader(fs);

	// Removing all elemnts from the map container (which are destroyed), leaving the container with a size of 0.
	mUniformLocations.clear();

	return true;
}

//-----------------------------------------------------------------------------
// Opens and reads contents of ASCII file to a string.  Returns the string.
// Not good for very large files.
//-----------------------------------------------------------------------------
string ShaderProgram::fileToString(const string& filename)
{
	std::stringstream ss;
	std::ifstream file;

	// Enable ifstream object exceptions
    file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		file.open(filename, std::ios::in);

		if (!file.fail())
		{
			// Using a std::stringstream is easier than looping through each line of the file
			ss << file.rdbuf();
		}

		file.close();
	}
	catch (std::exception ex)
	{
		std::cerr << "Error reading shader file " << filename << std::endl;
	}

	return ss.str();
}

//-----------------------------------------------------------------------------
// Activate the shader program
//-----------------------------------------------------------------------------
void ShaderProgram::use()
{
	if (mHandle > 0)
		glUseProgram(mHandle);
}

//-----------------------------------------------------------------------------
// Checks for shader compiler errors
//-----------------------------------------------------------------------------
void  ShaderProgram::checkCompileErrors(GLuint shader, ShaderType type)
{
	int status = 0;

	if (type == PROGRAM)
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint length = 0;
			glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &length);

			// The length includes the NULL character
			string errorLog(length, ' ');	// Resize and fill with space character
			glGetProgramInfoLog(shader, length, &length, &errorLog[0]);
			std::cerr << "Error! Shader program failed to link. " << errorLog << std::endl;
		}
	}
	else
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

			// The length includes the NULL character
			string errorLog(length, ' ');  // Resize and fill with space character
			glGetShaderInfoLog(shader, length, &length, &errorLog[0]);
			std::cerr << "Error! Shader failed to compile. " << errorLog << std::endl;
		}
	}

}

//-----------------------------------------------------------------------------
// Sets a glm::mat4 shader uniform
//-----------------------------------------------------------------------------
void ShaderProgram::setUniform(const GLchar* name, const glm::mat4& m)
{
	GLint loc = getUniformLocation(name);

	// loc = location of uniform in shader
	// count = how many matrices (1 if not an array of mats)
	// transpose = False for opengl because column major
	// value = the matrix to set for the uniform
	glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(m));
}

//-----------------------------------------------------------------------------
// Returns the uniform identifier given it's string name.
// NOTE: Shader must be currently active first.
//-----------------------------------------------------------------------------
GLint ShaderProgram::getUniformLocation(const GLchar* name)
{
	std::map<string, GLint>::iterator it = mUniformLocations.find(name);

	// Only need to query the shader program IF it doesn't already exist.
	if (it == mUniformLocations.end())
	{
		// Find it and add it to the map
		mUniformLocations[name] = glGetUniformLocation(mHandle, name);
	}

	// Return it
	return mUniformLocations[name];
}
#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include "GL/glew.h"
#include <string>
using std::string;

class Texture2D
{
public:
	Texture2D();
	virtual ~Texture2D();

	bool loadTexture(const string& fileName, bool generateMipMaps = true);
	void bind(GLuint texUnit = 0);
	void unbind(GLuint texUnit = 0);
	GLuint mTexture;

private:
	Texture2D(const Texture2D& rhs) {}
	Texture2D& operator = (const Texture2D& rhs) {}

	
};
#endif //TEXTURE2D_H

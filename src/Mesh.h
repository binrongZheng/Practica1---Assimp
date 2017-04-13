#pragma once
//GLEW
#define GLEW_STATIC
//GLFW
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "myShader.h"
#include <GL\glew.h>
#include <gtc/matrix_transform.hpp>
#include <glm.hpp>
#include <assimp\types.h>

using namespace glm;
using namespace std;

struct Vertex {
	vec3 Position;
	vec3 Normal;
	vec2 TexCoords;
};
struct Texture {
	GLuint id;
	string type;
	aiString path;
};
class Mesh
{
private:
	GLuint VAO, VBO, EBO;
	void setupMesh();

public:
	vector<Vertex> vertices;
	vector<GLuint> indices;
	vector<Texture> textures;
	Mesh(vector<Vertex> vert, vector<GLuint> ind, vector<Texture> text);
	void Draw(Shader, GLint);
};
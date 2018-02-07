#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"
#include <fstream>
#include <iostream>

using namespace glm;

// ����� ��� ������ � ��������
class CShader
{
public:
	//	��������� ������
	GLuint	Vsh;
	//	����������� ������
	GLuint	Fsh;
	//	��������� ��������� (������)
	GLuint	Program;
public:
	//	��������� ������
	int Load(const char *VertexFileName, const char *FragmentFileName);

	//	�������������� ������ (������� �������)
	void Activate();
	//	��������� ������ (������������ ������� ��������� ���������)
	static	void Deactivate();

	//	��������� ������� �������-����������
	int	GetAttribLocation(const char *name);
	//	������ ������� �� 4-� ��������� � uniform-����������
	void SetUniformVec4(const char *name, const GLfloat *value);
	void SetUniform1f(const char * name, const GLfloat* value);
	void SetUnoform1i(const char* name, const GLint* value);
	void SetUniformMat4(const char *name, const GLfloat* value);
};

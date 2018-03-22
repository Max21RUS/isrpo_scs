#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"


//	����� ��� ������ � �������
class CModel
{
	// ������ VAO-������
	GLuint	VAO_Index;
	// ������ VBO-������ ������
	GLuint	VBO_ArrayIndex;
	// ������ VBO-������ ��������
	GLuint	VBO_EllementArrayIndex;
	// ���������� ������ ��� ���������� ��������� (���������� ��������)
	int		VertexCount;
public:
	//	�����������
	CModel(void);
	//	������� ����� ������� �������
	void CreateBox(float w, float d, float h);
	//	����� �������
	void Draw(void);
};

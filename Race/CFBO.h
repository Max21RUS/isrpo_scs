#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

using namespace std;

//	����� ��� ������ � ������� FBO
class CFBO
{
	// ������ ������ FBO
	GLuint	FBO_Index;
	// ���������� ������ ��� �����
	GLuint	�olor_tex;
	// ���������� ������ ��� �������
	GLuint	Depth_tex;
	// ������ � ������ ������ FBO
	int	Width;
	int	Height;
public:
	// ������������� ������ FBO (�������� ������ ������, �������� ����� � �������� �������)
	void	Init(int w, int h);
	// ����� ������ FBO � �������� �������� ��� ����������
	void	Start(void);
	// ������� � ������ ����� �� ��������� (��� ������ �� �����)
	void	Stop(void);
	// ����� ������ FBO � �������� ������� ������
	void	Blit(int border_x = 1590, int border_y = 890);
	// �������� �������� ������� � ����������� ����� 
	// ��� ������������� � ��������� Shadow Mapping
	void	BindDepthTexture(GLenum TexUnit = GL_TEXTURE3);
};
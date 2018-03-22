#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include "CShader.h"
#include "CCamera.h"
#include "CMaterial.h"
#include "PxPhysicsAPI.h"
#include "CSourceLight.h"
#include <iostream>

using namespace physx;
using namespace std;

class CSprite
{
	//id ������� DevIL
	ILuint ImageId;
	//������ �������	 ������������ �����������
	//������ ������ GL_RGBA, GL_UNSIGNED_BYTE
	GLubyte*	Data;
	//������, ������ �����������
	int			width, height, format, type;
	//����� OpenGL ��� �������� ������� ��������
	GLuint	bufferID;
public:
	//������� ���� (������ � ������)
	static int ScreenWidth;
	static int ScreenHeight;
	static void SetScreenParam(int w, int h);

	CSprite();
	// �������� �����������
	void	Load(const char* filename);
	//	����� �������
	void	DrawSprite();
};

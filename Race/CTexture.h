#pragma once
#include "GL/freeglut.h"
#include "CShader.h"
#include "IL/il.h"
#include "IL/ilu.h"
#include <string>

//	����� ��� ������ � ���������
class	CTexture
{
	//	������ ����������� �������
	GLuint TexIndex;
	int ActiveBlock;

public:
	// �����������
	CTexture(void);

	//	�������� �������� �� �������� �����
	void	SetActiveBlock(const int TexB);
	char*	GetNameTex();
	int		GetNumTex();
	void	Load(const char* filename);
	void	LoadKubMap(const char* PX, const char* PY, const char* PZ, \
						const char* NX, const char* NY, const char* NZ);

	//	���������� ��������
	void	Apply(void);
	void	ApplyCubeMap(void);
};
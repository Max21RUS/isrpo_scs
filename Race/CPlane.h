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

using namespace physx;

class CPlane
{
	// ��������� �� ������, ������������ ��� ������ ���� ��������
	static CCameraBase* Camera;
	static CCameraBase* CameraLight;
	static CSourceLight* Light;
	// ������������ ������
	static CShader* Shader;
	// ��������
	CMaterial* Material;
	
	// ������ VAO-������
	GLuint	VAO_Index;
	// ������ VBO-������ ������
	GLuint	VBO_ArrayIndex;
	// ������ VBO-������ ��������
	GLuint	VBO_EllementArrayIndex;
	// ���������� ������ ��� ���������� ��������� (���������� ��������)
	int		VertexCount;
	GLubyte*	DataHight;
	int			Hight;
	float       WidthCenter;
public:
	CPlane(void);
	//	������ ������������ ������
	static void	SetShader(CShader* shader);
	// ������ ��������
	void	SetMaterial(CMaterial* Mat);
	//	���������� ������������ ������
	static void	SetCamera(CCameraBase *camera);
	static void	SetCameraLight(CCameraBase *camera);
	static void	SetLight(CSourceLight* l);

	// ������� ��������� ������� ������� (width)
	// � �������� ���������� ����� � ����� � ������
	void	CreatePlane(PxScene* gS, PxCooking* gC, int w);
	//	������� ���������
	void	DrawPlane(void);
	void	SetDataHight(GLubyte* d);
	void	SetTexHight(int d);
	float   GetHeight(int x, int z);
};
#pragma once
#include "CShader.h"
#include "CCamera.h"
#include "glm\glm.hpp"
#include "glm\gtc\type_ptr.hpp"

using namespace glm;

//	������ ��� ������ � ���������� �����
class CSourceLight
{
	vec4 Ambient;
	vec4 Diffuse;
	vec4 Specular;
	vec4 Position;

	bool HaveAmbient;
	bool HaveDiffuse;
	bool HaveSpecular;
	bool HavePosition;

public:
	//	����������� �� ���������
	CSourceLight(void);

	// ������� ���������� ���������� �����
	void	SetDiffuse(vec4 value);
	void	SetAmbient(vec4 value);
	void	SetSpecular(vec4 value);
	void	SetPosition(vec4 value);

	// ��������� ���������� ���������� �����
	void	Apply(CShader* s, CCameraBase* c);
};
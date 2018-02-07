#pragma once
#include "CShader.h"
#include "CModel.h"
#include "CMaterial.h"
#include "CSourceLight.h"
#include "CCameraBase.h"

// ����� ��� ������������� �������
class CObject
{
private:
	// ��������� �� ������, ������������ ��� ������ ���� ��������
	static CCameraBase* Camera;
	static CCameraBase* CameraLight;
	// �������� �����
	CSourceLight* Light;
	// ������������ ������
	static CShader* Shader;
	// ��������
	CMaterial* Material;
	// ������� � ���� �������� ��� �������	
	GLfloat	Position[3];
	GLfloat	Angle;
	// ������� ������ (������������ �������) - ���� �� ��������� ������ ���
	GLfloat* ModelMatrix;
	// ������������ ������
	CModel* Model;
public:
	//	�����������
	CObject(void);

	//	������ ������������ ������
	static void	SetShader(CShader *shader);
	// ������ ��������
	void	SetMaterial(CMaterial* Mat);
	//	������ ������������ ������
	void	SetModel(CModel *model);
	//	���������� ������������ ������
	static void	SetCamera(CCameraBase *camera);
	static void	SetCameraLight(CCameraBase *camera);

	void SetLight(CSourceLight* l);
	void	SetPosition(float x, float y, float z);
	//	������ ���� �������� � �������� ������������ ��� OY
	void	SetAngle(float a);
	void	SetTransformMatrix(const float* m);
	//	������� ������
	void	Draw(void);

};
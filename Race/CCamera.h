#pragma once
#include "GL\freeglut.h"
#include <fstream>
#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"
#include "CCameraBase.h"

using namespace glm;

//	����� ��� ������ � �������
class CCamera : public CCameraBase
{
	//	����������� ��������
	double YawAngle;	//���� ��
	double PitchAngle;	// ���� ����

	// ������� ������
	vec3	forward;
	vec3	up;
	vec3	right;

	vec3	Position;
public:
	// ����������� �� ��������� - �������� ��������� ���������� ������ �� �����
	CCamera(void);
	// ���������� - ���������� ����� ���������� ������ 
	~CCamera(void);

	// �������� ������
	void	Left(int value);
	void	Right(int value);
	void	Up(int value);
	void	Down(int value);

	//	�������� ������� ������ (����������)
	float* GetViewMatrix(void);

	//	��������� ������� ������� �����������
	void	SetPosition(float x, float y, float z);
	void	GetPosition(float & x, float & y, float & z);

	//	��������� ������� ������
	vec3	GetForwardVector(void);
	//	��������� ������� ������
	vec3	GetRightVector(void);
};

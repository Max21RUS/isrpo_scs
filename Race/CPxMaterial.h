#pragma once
#include "PxPhysicsAPI.h"

using namespace physx;

class CPxMaterial
{
	// ������ gPhysics ��� ������ � ������� ������
	static PxPhysics*		gPhysics;
	// ������ ��� ������������� ��������� (������ ���������, ����������� ������ � �.�.)
	PxMaterial*		gMaterial;

	float friction;
	float slip;
	float elasticity;

public:
	CPxMaterial();
	// ����� ������ ������
	static void SetPhysicsModel(PxPhysics* Px);
	// �������� ���������
	void SetMaterial(float f, float s, float e);
	// ������ ��������
	PxMaterial* GetMaterial();
};
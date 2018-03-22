#pragma once
#include "PxPhysicsAPI.h"
#include "CPxMaterial.h"
#include <vector>

using namespace physx;

class CPxShape
{
	// ������ gPhysics ��� ������ � ������� ������
	static PxPhysics*		gPhysics;
	CPxMaterial*			gMaterial;
	std::vector<PxShape*>	gShape;

public:
	CPxShape();
	// ����� ������ ������
	static void SetPhysicsModel(PxPhysics* Px);
	// ����� ����������
	void SetMaterial(CPxMaterial* m);
	// �������� ����� ��������������
	void AddBoxShape(float x, float y, float z);
	// ������ ��������
	PxMaterial* GetMaterial();
	std::vector<PxShape*>* GetShape();
};


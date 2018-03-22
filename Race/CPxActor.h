#pragma once
#include "PxPhysicsAPI.h"
#include "CPxShape.h"
#include <iostream>
#include <vector>
#include "CObject.h"

using namespace physx;

class CPxActor
{
	// ������ gPhysics ��� ������ � ������� ������
	static PxPhysics*		gPhysics;
	// ������ ��� ������������� ����� �����
	static PxScene*			gScene;
	// ����� ��� ������������� ������������ �������
	PxRigidStatic*			StaticActor;
	// ����� ��� ������������� ������������� ������� 
	PxRigidDynamic*			DynamicActor;
	// ���������� ������
	CPxShape*				gShape;				
	// �����
	float					mass;
	// ������ ������
	CObject*				graf;
public:
	CPxActor();
	static void SetPhysicsModel(PxPhysics* Px);
	static void SetScene(PxScene* Sx);
	void SetShape(CPxShape* s);
	void CreatStaticPlane(unsigned char nx, unsigned char ny, unsigned char nz, unsigned char distance);
	void CreatDymaicKub(float x, float y, float z);
	PxActor* GetActor();
	void SetMass(float m);
	const float* GetTransformMatrix();
	void SetGraf(CObject* gr);
	void Simulating(float time);
};
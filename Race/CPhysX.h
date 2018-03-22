#pragma once
#include "PxPhysicsAPI.h"
#include "extensions/PxDefaultErrorCallback.h"
#include "extensions/PxDefaultAllocator.h"
#include <iostream>

using namespace physx;

class CPhysX
{
	// ���������� ��� ������������� ������:

	// ������ ��� ��������� ������ ������ PhysX (������������ ���������� �� ���������)
	PxDefaultAllocator		gAllocator;
	// ������ ��� ������ ��������� �� ������� ������ PhysX (������������ ���������� �� ���������)
	PxDefaultErrorCallback	gErrorCallback;
	// ������ ��� ������������� ������� �� ��������� ����������� 
	// (���������� �� ���������, ��������� �����������)
	PxDefaultCpuDispatcher*	gDispatcher;

	// ������ Foundation ��� ������������� ������ ������
	PxFoundation*			gFoundation;
	// ������ gPhysics ��� ������ � ������� ������
	PxPhysics*				gPhysics;
	// ������ ��� ������������� ����� �����
	PxScene*				gScene;
	//	������ ��� ��������� ������� ��������� (�������)
	PxCooking*				gCooking;
	
public:
	CPhysX();
	void Init();
	PxPhysics* GetPhysicsModule();
	PxScene* GetScene();
	PxCooking* GetCooking();
	void AddActor(PxActor* actor);
};
#pragma once
#include "CShader.h"

//	������ ��� ������ � ����������
class CMaterial
{
public:
	// ����������
	virtual void Apply(CShader* shader);
};
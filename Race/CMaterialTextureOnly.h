#pragma once
#include "CMaterial.h"
#include "CTexture.h"

class CMaterialTextureOnly : public CMaterial
{
public:
	CMaterialTextureOnly();

	// ��������� ��������
	void	SetTexture(CTexture* t);

	// ����������
	virtual void Apply(CShader* shader);

private:
	CTexture* Tex;
};
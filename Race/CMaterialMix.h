#pragma once
#include "CMaterial.h"
#include "CTexture.h"
#include "glm\glm.hpp"

class CMaterialMix : public CMaterial
{
public:
	CMaterialMix();

	// ������� ���������� ���������
	void	SetDiffuse(vec4 value);
	void	SetAmbient(vec4 value);

	// ��������� ��������
	void	SetTextures(CTexture* mask, CTexture* t1, CTexture* t2);

	// ����������
	virtual void Apply(CShader* shader);

private:
	CTexture* Tex_Mask;
	CTexture* Tex_1;
	CTexture* Tex_2;
	vec4 Ambient;
	vec4 Diffuse;
};
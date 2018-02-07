#pragma once
#include "CMaterial.h"
#include "CTexture.h"
#include "glm\glm.hpp"

class CMaterialDiffSpec : public CMaterial
{
public:
	CMaterialDiffSpec();

	// ������� ���������� ���������
	void	SetDiffuse(vec4 value);
	void	SetShiness(float value);

	// ��������� ��������
	void	SetTextures(CTexture* d, CTexture* s);

	// ����������
	virtual void Apply(CShader* shader);

private:
	CTexture* Tex_Diff;
	CTexture* Tex_Spec;
	vec4 Diffuse;
	float Shiness;
};
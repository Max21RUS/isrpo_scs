#include "CFBO.h"

// ������������� ������ FBO (�������� ������ ������, �������� ����� � �������� �������)
void	CFBO::Init(int w, int h)
{
	Width = w;
	Height = h;

	glGenFramebuffers(1, &FBO_Index);
	glBindFramebuffer(GL_FRAMEBUFFER, FBO_Index);

	// �������� ����������� ������� ��� �����
	glGenTextures(1, &�olor_tex);
	glBindTexture(GL_TEXTURE_2D, �olor_tex);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Width, Height, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
	glGenerateMipmap(GL_TEXTURE_2D);

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, �olor_tex, 0);

	// �������� ����������� ������� ��� �������
	glGenTextures(1, &Depth_tex);
	glBindTexture(GL_TEXTURE_2D, Depth_tex);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat BorderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, BorderColor);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, Width, Height, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	// glGenerateMipmap(GL_TEXTURE_2D); 

	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, Depth_tex, 0);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		cout << "FBO creating filed!" << endl;
		return;
	}
}

// ����� ������ FBO � �������� �������� ��� ����������
void	CFBO::Start(void)
{
	glBindFramebuffer(GL_FRAMEBUFFER, FBO_Index);
}

// ������� � ������ ����� �� ��������� (��� ������ �� �����)
void	CFBO::Stop(void)
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// ����� ������ FBO � �������� ������� ������
void	CFBO::Blit(int border_x, int border_y)
{
	glBindFramebuffer(GL_READ_FRAMEBUFFER, FBO_Index);
	glReadBuffer(GL_COLOR_ATTACHMENT0);

	glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
	glDrawBuffer(GL_BACK);

	glBlitFramebuffer(0, 0, Width, Height, border_x - Width, border_y - Height, border_x, border_y, GL_COLOR_BUFFER_BIT, GL_NEAREST);

	Stop();
}

// �������� �������� ������� � ����������� ����� 
// ��� ������������� � ��������� Shadow Mapping
void	CFBO::BindDepthTexture(GLenum TexUnit)
{
	// ��������� ���������� ����������� ������� 
	glActiveTexture(TexUnit);
	glBindTexture(GL_TEXTURE_2D, Depth_tex);
}
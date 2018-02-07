#include "GL\glew.h"
#include "CTexture.h"
#include <iostream>

using namespace std;

CTexture::CTexture()
{
	TexIndex = 0;
	ActiveBlock = -1;
}

void	CTexture::SetActiveBlock(const int TexB)
{
	ActiveBlock = TexB;
}

wchar_t* ConvertToUnicode(const char* str)
{
	char C_String[50];
	C_String[0] = '\0';
	strcat_s(C_String, "Textures/");
	strcat_s(C_String, str);
	wchar_t* Unicode_String = new wchar_t[50];
	wsprintf(Unicode_String, L"%S", C_String);

	return Unicode_String;
}

//	�������� �������� �� �������� �����
void	CTexture::Load(const char* filename)
{
	// ����� ����� ����� � �������� �������
	glActiveTexture(ActiveBlock);
	glGenTextures(1, &TexIndex);
	glBindTexture(GL_TEXTURE_2D, TexIndex);

	// ������������
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// �������� �����������
	ILuint ImgIndex;
	ilGenImages(1, &ImgIndex);
	ilBindImage(ImgIndex);

	if (ilLoadImage(ConvertToUnicode(filename)))
		cout << "Image success loaded" << endl;
	else
		cout << "Error of load image" << endl;

	//	��������� ���������� ����������� ��������
	int width = ilGetInteger(IL_IMAGE_WIDTH);
	int height = ilGetInteger(IL_IMAGE_HEIGHT);
	int type = ilGetInteger(IL_IMAGE_TYPE);
	int fmt = ilGetInteger(IL_IMAGE_FORMAT);
	GLubyte* Data = ilGetData();

	glTexImage2D(GL_TEXTURE_2D, 0, fmt, width, height, 0, fmt, type, Data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, 32);
	glGenerateMipmap(GL_TEXTURE_2D);

	ilDeleteImages(1, &ImgIndex);
}

void SetTheKubFace(GLenum face, const char* imgname)
{
	// �������� �����������
	ILuint ImgIndex;
	ilGenImages(1, &ImgIndex);
	ilBindImage(ImgIndex);

	if (ilLoadImage(ConvertToUnicode(imgname)))
		cout << "Image success loaded" << endl;
	else
		cout << "Error of load image" << endl;

	//	��������� ���������� ����������� ��������
	int width = ilGetInteger(IL_IMAGE_WIDTH);
	int height = ilGetInteger(IL_IMAGE_HEIGHT);
	int type = ilGetInteger(IL_IMAGE_TYPE);
	int fmt = ilGetInteger(IL_IMAGE_FORMAT);
	GLubyte* Data = ilGetData();

	glTexImage2D(face, 0, IL_RGB, width, height, 0, fmt, type, Data);

	ilDeleteImages(1, &ImgIndex);
}

// �������� ���������� ��������
void	CTexture::LoadKubMap(const char* PX, const char* PY, const char* PZ, \
								const char* NX, const char* NY, const char* NZ)
{
	// �������� ����������� �������
	glActiveTexture(ActiveBlock);
	glGenTextures(1, &TexIndex);
	glBindTexture(GL_TEXTURE_CUBE_MAP, TexIndex);

	// ������������
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// �������� �������
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_POSITIVE_X, PX);
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, PY);
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, PZ);
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, NX);
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, NY);
	SetTheKubFace(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, NZ);

	//��������� ���������� ��������� ��������
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAX_ANISOTROPY_EXT, 32);

	// ��������� ��������
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
}

//	���������� ��������
void	CTexture::Apply(void)
{
	// 	����� ��������� ����������� ����� 
	glActiveTexture(ActiveBlock);
	//	���������� ����������� �����
	glBindTexture(GL_TEXTURE_2D, TexIndex);
}

//	���������� ���������� ��������
void	CTexture::ApplyCubeMap(void)
{
	// 	����� ��������� ����������� ����� 
	glActiveTexture(ActiveBlock);
	//	���������� ����������� �����
	glBindTexture(GL_TEXTURE_CUBE_MAP, TexIndex);
}

char* CTexture::GetNameTex()
{
	int  block = ActiveBlock - GL_TEXTURE0;
	char* name = new char[5]{ 't', 'e', 'x', ' ', 0 };
	name[3] = block + '0';
	return name;
}

int CTexture::GetNumTex()
{
	return ActiveBlock - GL_TEXTURE0;
}
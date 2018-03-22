#include "CShader.h"

using namespace std;

// �������� ����� � �������� � ������
int Creat(const char* File, const GLuint id)
{
	ifstream Vfile(File, ios_base::binary);
	if (!Vfile.is_open())
	{
		cout << "Can not open file \"" << File << "\"" << endl;
		exit(EXIT_FAILURE);
	}

	// ������ �� �����
	char* code;
	int ByteCount;
	int success;

	Vfile.seekg(0, ios_base::end);
	ByteCount = Vfile.tellg();
	Vfile.seekg(0, ios_base::beg);
	code = new char[ByteCount + 1]();
	Vfile.read(code, ByteCount);
	Vfile.close();

	// �������� � ����
	glShaderSource(id, 1, &code, nullptr);
	glCompileShader(id);
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);

	// ��������
	delete code;

	if (!success)
	{
		GLint ShaderInfoLen;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &ShaderInfoLen);
		char* Info = new char[ShaderInfoLen];
		glGetShaderInfoLog(id, ShaderInfoLen, NULL, Info);

		cout << "Error from file: " << File << endl << "	" << Info << endl;
		return 0;
	}

	return 1;
}

//	��������� ������
int CShader::Load(const char *VertexFileName, const char *FragmentFileName)
{
	bool Success;

	// �������� ��������� ��������
	Vsh = glCreateShader(GL_VERTEX_SHADER);
	Fsh = glCreateShader(GL_FRAGMENT_SHADER);
	
	// �������� � ������
	Success = (Creat(VertexFileName, Vsh) && Creat(FragmentFileName, Fsh));
	if (!Success)
		return 0;
	
	// �������� ��������� ���������
	Program = glCreateProgram();
	glAttachShader(Program, Vsh);
	glAttachShader(Program, Fsh);
	glLinkProgram(Program);

	// ��������
	int Success2;
	glGetProgramiv(Program, GL_LINK_STATUS, &Success2);
	if (!Success2)
	{
		GLint ShaderInfoLen;
		glGetProgramiv(Program, GL_INFO_LOG_LENGTH, &ShaderInfoLen);
		char* Info = new char[ShaderInfoLen]();
		glGetShaderInfoLog(Program, ShaderInfoLen, NULL, Info);

		cout << "Error linking file: " << endl << "	" << Info << endl;
		return 0;
	}

	return 1;
}

//	�������������� ������ (������� �������)
void CShader::Activate()
{
	glUseProgram(Program);
}

//	��������� ������ (������������ ������� ��������� ���������)
void CShader::Deactivate()
{
	glUseProgram(0);
}

//	��������� ������� �������-����������
int	CShader::GetAttribLocation(const char *name)
{
	int index;
	index = glGetAttribLocation(Program, name);
	
	/*if (index == -1)
	{
		cout << "Error for get attributes [" << name << "]" << endl;
		exit(0);
	}*/

	return index;
}

//	������ ������� �� 4-� ��������� � uniform-����������
void CShader::SetUniformVec4(const char *name, const GLfloat* value)
{
	glUseProgram(Program);
	int index = glGetUniformLocation(Program, name);

	/*if (index == -1)
	{
		cout << "Error for set uniform vec4 [" << name << "]" << endl;
		exit(0);
	}*/

	glUniform4fv(index, 1, value);
}

//	������ ���������� � uniform-����������
void CShader::SetUniform1f(const char *name, const GLfloat* value)
{
	glUseProgram(Program);
	int index = glGetUniformLocation(Program, name);

	/*if (index == -1)
	{
		cout << "Error for set uniform 1f varieble [" << name << "]" << endl;
		exit(0);
	}*/

	glUniform1f(index, *value);
}

//	������ ���������� � uniform-����������
void CShader::SetUnoform1i(const char* name, const GLint* value)
{
	glUseProgram(Program);
	int index = glGetUniformLocation(Program, name);

	/*if (index == -1)
	{
		cout << "Error for set uniform 1i varieble [" << name << "]" << endl;
		exit(0);
	}*/

	glUniform1i(index, *value);
}

void CShader::SetUniformMat4(const char *name, const GLfloat* value)
{
	glUseProgram(Program);
	int index = glGetUniformLocation(Program, name);

	/*if (index == -1)
	{
		cout << "Error for set uniform mat4 varieble [" << name << "]" << endl;
		exit(0);
	}*/

	glUniformMatrix4fv(index, 1, GL_FALSE, value);
}
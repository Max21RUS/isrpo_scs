#include "CObject.h"

//	�����������
CObject::CObject(void)
{
	memset(Position, 0, 3 * sizeof(GLfloat));
	ModelMatrix = new GLfloat[16];
	memset(ModelMatrix, 0, 16 * sizeof(GLfloat));
	ModelMatrix[5] = 1;
	ModelMatrix[15] = 1;

	Angle = 0;
	Model = NULL;
	Light = NULL;
}

CCameraBase* CObject::Camera = NULL;
CShader*  CObject::Shader = NULL;
CCameraBase* CObject::CameraLight = NULL;

//	������ ������������ ������
void	CObject::SetShader(CShader *shader)
{
	Shader = shader;
}

//	������ ������������ ������
void	CObject::SetModel(CModel *model)
{
	Model = model;
}

//	���������� ������������ ������
void	CObject::SetCamera(CCameraBase *camera)
{
	Camera = camera;
}

void	CObject::SetCameraLight(CCameraBase *camera)
{
	CameraLight = camera;
}

//	������ ������� �������
void	CObject::SetPosition(float x, float y, float z)
{
	Position[0] = x;
	Position[1] = y;
	Position[2] = z;

	ModelMatrix[12] = Position[0];
	ModelMatrix[13] = Position[1];
	ModelMatrix[14] = Position[2];
}

//	������ ���� �������� � �������� ������������ ��� OY
void	CObject::SetAngle(float a)
{
	Angle = a;

	double radAngle = Angle * 0.01745;

	ModelMatrix[0] = (float)cos(radAngle);
	ModelMatrix[2] = (float)-sin(radAngle);
	ModelMatrix[8] = (float)sin(radAngle);
	ModelMatrix[10] = (float)cos(radAngle);
}

//	������� ������
void	CObject::Draw(void)
{
	if ((Shader == NULL) || (Model == NULL) || (Camera == NULL)) return;

	// ���������� ������
	Shader->Activate();

	// ��������� ������� ��������
	Shader->SetUniformMat4("uProjectionMatrix", Camera->GetProjectionMatrix());
	Shader->SetUniformMat4("uLightProjectionMatrix", CameraLight->GetProjectionMatrix());

	// ��������� ������� ���������� ������
	mat4	ViewMatrix = make_mat4(Camera->GetViewMatrix());
	mat4	ModelMatrix = make_mat4(this->ModelMatrix);
	mat4	ModelViewMatrix = ViewMatrix * ModelMatrix;
	
	Shader->SetUniformMat4("uModelViewMatrix", value_ptr(ModelViewMatrix));
	
	// ��������� ������� ���������� ������ light
	ViewMatrix = make_mat4(CameraLight->GetViewMatrix());
	ModelMatrix = make_mat4(this->ModelMatrix);
	ModelViewMatrix = ViewMatrix * ModelMatrix;

	Shader->SetUniformMat4("uLightModelViewMatrix", value_ptr(ModelViewMatrix));

	// ��������� ���������� ��������� �����
	if (Light != NULL)
		Light->Apply(Shader, Camera);

	// ��������� ���������� �������	
	if(Material != NULL)
		Material->Apply(Shader);

	// ����� �������
	Model->Draw();
}

void	CObject::SetMaterial(CMaterial* Mat)
{
	Material = Mat;
};

void	CObject::SetTransformMatrix(const float* m)
{
	std::copy(m, &m[15], ModelMatrix);
}

void CObject::SetLight(CSourceLight* l)
{
	Light = l;
}

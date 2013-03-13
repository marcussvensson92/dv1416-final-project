#ifndef LIGHTMANAGER_H
#define LIGHTMANAGER_H

#include "StdAfx.h"
#include "Vertex.h"
#include "Light.h"
#include "Buffer.h"
#include "Shader.h"
#include "Camera.h"
#include <algorithm>

using namespace Light;

enum LightType
{
	POINT_LIGHT,
};

class LightManager
{
public:
	enum State
	{
		Add,
		Remove,
		MoveXZ,
		MoveY
	};

	LightManager(void);
	~LightManager(void);

	void		init(HWND hWnd, ID3D11Device* device, Camera* camera);

	void		setState(State state) { m_state = state; }

	bool		AddLight(XMFLOAT3, LightType);
	void		RemoveLight(PointLight*);
	void		ClearLights();
	void		update(float);

	PointLight*	computeIntersection(const Ray& ray);

	std::vector<PointLight> getLights();

	void render(ID3D11DeviceContext* deviceContext, Shader* shader, const Camera& camera);
private:
	std::vector<PointLight>				m_Lights;
	ID3D11ShaderResourceView*			m_texture;

	State m_state;

	HWND m_hWnd;
	Camera* m_camera;
};

#endif
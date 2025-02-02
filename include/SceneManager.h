#pragma once
#include <memory>
#include "Scene.h"

class SceneManager
{
public:
	void setScene(std::shared_ptr<Scene> scene);

	void Update(float deltaTime);

	void Draw();

private:
	std::shared_ptr<Scene> currentScene;
};
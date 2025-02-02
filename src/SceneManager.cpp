#include "../../include/SceneManager.h"

void SceneManager::setScene(std::shared_ptr<Scene> scene)
{
	currentScene = scene;
}

void SceneManager::Update(float deltaTime)
{
	if (currentScene) currentScene->Update(deltaTime);
}

void SceneManager::Draw()
{
	if (currentScene) currentScene->Draw();
}
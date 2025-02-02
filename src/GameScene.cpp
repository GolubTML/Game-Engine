#include "../../include/GameScene.h"

GameScene::GameScene(GLFWwindow* window, std::vector<std::vector<Block>> world, Texture* blockTexture, Player player) : window(window), camera(Vector2(0.f, 0.f), 800.f, 600.f), player(player), world(world), blockTexture(blockTexture)
{
}

void GameScene::Update(float deltaTime)
{
	player.Update(window, camera, world, deltaTime);
}

void GameScene::Draw()
{
    glPushMatrix();
    camera.applyTransform();

    player.Draw(player.getTexture());
    map.Draw(blockTexture);

    glPopMatrix();
}
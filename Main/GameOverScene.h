#pragma once
#include "Config.h"
#include "GameEntity.h"

class Image;
class GameOverScene : public GameEntity
{
private:
	Image* gameOver = nullptr;
	Image* backGround = nullptr;

	int test_1 = 0, test_2 = 0;
	int elapsedcount = 0;

public:
	virtual ~GameOverScene() = default;

	virtual HRESULT Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};


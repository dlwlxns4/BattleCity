#pragma once
#include "GameEntity.h"
#include "Config.h"
#include "BoomImage.h"
#include <vector>

class Image;
class EnemyManager;
class AmmoManager;
class Tank;
class TankFactory;
class ItemManager;
class Item;
class Stage1Scene : public GameEntity
{
private:
	TILE_INFO tileInfo[TILE_COUNT_Y * TILE_COUNT_X];
	Image* sampleImage;
	
	//GameBoard °ü·Ã
	Image *spawnMonsterImage;
	int remainSpawnMonster;
	int remainMonster;

	BOOM_IMAGE_INFO boomImg[2];

	Image *lifeImage;
	Image *stageImage;
	Image* stageLevel;
	Image* backGround;

	Image* slate;
	int slate1;
	int slate2;

	Tank* tank = nullptr;
	vector<TankFactory*> vecTankFactorial = {};
	vector<TankFactory*>::iterator itVecTankFactory = {};
	AmmoManager* playerTankAmmoManager = nullptr;
	AmmoManager* enemyTankAmmoManager = nullptr;

	float elapsedCount = 0.0f;
	float spawmElapsedCount = 5.0f;
	int spawnCount = 0;
	int maxSpawnCount = 3;
	int currSpawnEnemy = 0;
	int maxSpawnEnemy = 6;
	POINTFLOAT spawnEnemyPos[3] = {};
	EnemyManager* enemyMgr = nullptr;
	vector<Tank*>::iterator itEnemyTanks = {};

	RECT backGroundRect;

	bool check = false;
	ItemManager* itemManager;

	//Item* item;

	//GameOver
	Image* gameOver;
	int gameOverPosY;
	int stateElapsedCount;
	
public:
	void Load(int index);
	virtual HRESULT Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
	void SpawnEnemy(TankType type);

	inline void SubCurrSpawnEnemy() { this->currSpawnEnemy--; }
	inline TileType GetTileType(int i) { return this->tileInfo[i].tileType; }
	void CreateItem();
	void UseItem(int type);
	
	void CloseSlate();
	void RotateGameOverScene();
	void ShowHitCollider();
};


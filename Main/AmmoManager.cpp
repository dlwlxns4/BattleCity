#include "AmmoManager.h"
#include "Ammo.h"
#include "GameObject.h"
#include "Tank.h"

HRESULT AmmoManager::Init(TILE_INFO* tileInfo, Tank* playerTank, EnemyManager* enemyMgr)
{
	vecAmmos.resize(ammoMaxCount);

	this->tileInfo = tileInfo;
	this->playerTank = playerTank;
	this->enemyMgr = enemyMgr;

	for (itAmmos = vecAmmos.begin();
		itAmmos != vecAmmos.end(); itAmmos++)
	{
		(*itAmmos) = new Ammo;
		(*itAmmos)->Init(this->tileInfo, nullptr, this->enemyMgr, this->playerTank);
	}

	return S_OK;
}

void AmmoManager::Update()
{
	for (itAmmos = vecAmmos.begin();
		itAmmos != vecAmmos.end(); itAmmos++)
	{
		(*itAmmos)->Update();
	}
}

void AmmoManager::Render(HDC hdc)
{
	for (itAmmos = vecAmmos.begin();
		itAmmos != vecAmmos.end(); itAmmos++)
	{
		(*itAmmos)->Render(hdc);
	}
}

void AmmoManager::Release()
{
	for (itAmmos = vecAmmos.begin();
		itAmmos != vecAmmos.end(); itAmmos++)
	{
		SAFE_RELEASE((*itAmmos));
	}
	vecAmmos.clear();
}

void AmmoManager::Fire(Tank* tank, AmmoManager* playerAmmoManager, AmmoManager* enemyAmmoManager)
{
	for (itAmmos = vecAmmos.begin();
		itAmmos != vecAmmos.end(); itAmmos++)
	{
		if ((*itAmmos)->GetIsFire())	continue;

		(*itAmmos)->SetOwnerTank(tank);
		(*itAmmos)->SetPlayerAmmoManager(playerAmmoManager);
		(*itAmmos)->SetEnemyAmmoManager(enemyAmmoManager);

		switch (tank->moveDir)
		{
		case Left:
			tank->BarrelPos = { tank->GetPos().x - tank->GetBodySize() / 2 + 3, tank->GetPos().y - tank->GetBodySize() / 4 };
			(*itAmmos)->SetMoveDir("Left");
			break;
		case Right:
			tank->BarrelPos = { tank->GetPos().x,  tank->GetPos().y - tank->GetBodySize() / 4 };
			(*itAmmos)->SetMoveDir("Right");
			break;
		case Up:
			tank->BarrelPos = { tank->GetPos().x - tank->GetBodySize() / 4,  tank->GetPos().y - tank->GetBodySize() / 2 };
			(*itAmmos)->SetMoveDir("Up");
			break;
		case Down:
			tank->BarrelPos = { tank->GetPos().x - tank->GetBodySize() / 4,  tank->GetPos().y };
			(*itAmmos)->SetMoveDir("Down");
			break;
		default:
			break;
		}

		//ammoPack[i].SetIsAlive(true);
		(*itAmmos)->SetPos(tank->BarrelPos);	// 미사일 위치 변경
		(*itAmmos)->SetIsFire(true);	// 미사일 상태 변경

		break;
	}
}

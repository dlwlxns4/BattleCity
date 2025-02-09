#pragma once
#include "Config.h"
#include "GameEntity.h"

#define elapsedTest 20		//점수 반영 속도 (적으면 빠름)

class Image;
class ScoreScene : public GameEntity
{
private:
	//Image* hiScoreText;	//하이스코어 갱신될시 사용
	Image* noneHiScore = nullptr;
	Image* hiScore = nullptr;
	Image* totalScore = nullptr;
	Image* player = nullptr;
	Image* playerScore = nullptr;
	Image* stage = nullptr;
	Image* number = nullptr;
	Image* enemyTank = nullptr;
	Image* arrow = nullptr;
	Image* pts = nullptr;
	Image* backGround = nullptr;

	int elapsedcount = 0;
	int hightScore = 0;
	int player1Score = 0;

	int KNE = 0, KSE = 0, KRE = 0, KBE = 0;				//종류별 죽인 탱크수
	int CNE = 0, CSE = 0, CRE = 0, CBE = 0;				//죽인 탱크를 1씩 카운트하기위한 변수
	int SNE = 0, SSE = 0, SRE = 0, SBE = 0;				//스코어 점수
	int bSNE = 0, bSSE = 0, bSRE = 0, bSBE = 0;			//순서대로 점수계산을 위한 불타입

	int TK = 0;								//토탈 킬수
	int bTotalScore = 0;					// 점수계산 끝나고 토탈점수 
	int round = 0;							// 현재 라운드
	bool gameOver = 0;						// 게임오버 알림



public:
	virtual ~ScoreScene() = default;

	virtual HRESULT Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void ScoreCalculate();
};


#pragma once
#ifndef _TurntableSystem_
#define _TurntableSystem_
#include "cocos2d.h"
USING_NS_CC;
class TurntableSystem :public cocos2d::CCSprite
{
public:
	TurntableSystem(CCLayer* layer);
	~TurntableSystem(void);
	int runnum;
	int startnumber;
	CCArray* boxgezi;
	void runTurntableGet(float time);

	void runAct(float time);

	int getReward(int id);

	void changeBox(int boxid,bool change);

	void runPlay(CCObject* pSender);
};

#endif
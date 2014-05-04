#include "TurntableSystem.h"
#include "../ZhuanPanSystem/Zp_ImgPath.h"
#include "../ZhuanPanSystem/Zp_BoxData.h"
#include "../ZhuanPanSystem/Gzi.h"
#include "../VisibleRect.h"
#include "../GameData/GlobalInfo.h"
int fnum =0;
TurntableSystem::TurntableSystem(CCLayer* layer)
{
	CCSprite* allbd = CCSprite::create(IMG_ZP_BD.c_str());
	allbd->setPosition(VisibleRect::center());

	int allbd_w =  allbd->getContentSize().width;
	int allbd_h =  allbd->getContentSize().height;

	CCSprite* cbd = CCSprite::create(IMG_ZP_CENTERBD.c_str());
	cbd->setPosition(ccp(allbd_w/2,allbd_h/2));
	

	//格子s
	CCSprite* gezi_bd = CCSprite::create(IMG_ZP_KUANGBD.c_str());
	int gezi_w =  gezi_bd->getContentSize().width;
	int gezi_h =  gezi_bd->getContentSize().height;

	//创建一个矩阵格子阵
	boxgezi = CCArray::create();
	int bid = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j <=5; j++)
		{

			Zp_BoxData* thisbox = new Zp_BoxData();
			thisbox->set_boxid(bid);
			thisbox->set_boxReward(getReward(bid%6));
			if(bid==4)
			{
				thisbox->set_xuanzhong(true);
			}
			else
			{
				thisbox->set_xuanzhong(false);
			}
			thisbox->set_tag(bid);
			switch (i)
			{
			case 0:
				thisbox->set_point(ccp(55+gezi_w*j,allbd_h-30));
				boxgezi->addObject(thisbox);
				break;
			case 1:
				if(j<=2)
				{
					thisbox->set_point(ccp(55+gezi_w*5,allbd_h-30-gezi_h-gezi_h*j));
					boxgezi->addObject(thisbox);
				}
				break;
			case 2:
				thisbox->set_point(ccp(55+gezi_w*5-gezi_w*j,30));
				boxgezi->addObject(thisbox);
				break;
			case 3:
				if(j<=2)
				{
					thisbox->set_point(ccp(55,30+gezi_h+gezi_h*j));
					boxgezi->addObject(thisbox);
				}
				break;
			default:

				break;
			}
			bid++;
		}
	}
	vector<int> maua ;

	for (int i = 0; i < boxgezi->count(); i++)
	{
		Zp_BoxData* bdata = (Zp_BoxData*)boxgezi->objectAtIndex(i);
		Gzi* gz = new Gzi(allbd,bdata);
		maua.push_back(bdata->get_boxid());
	}
	GlobalInfo::getInstance()->set_gizilist(maua);

	CCMenuItemImage *item1 = CCMenuItemImage::create(IMG_ZP_START.c_str(), IMG_ZP_START0.c_str(), layer, menu_selector(TurntableSystem::runPlay));
	item1->setPosition(ccp(cbd->getContentSize().width/2, cbd->getContentSize().height/2+10));
	CCMenu *menu = CCMenu::create(item1, NULL);
	menu->setPosition(CCPointZero);
	cbd->addChild(menu, 0,TAG_ZP_PLAY);

	allbd->addChild(cbd,2,TAG_ZP_ZHONGJIAN);
	layer->addChild(allbd,3,TAG_ZP_BD);

}

void TurntableSystem::runPlay(CCObject* pSender)
{
	runnum = -1;
	float timerun = 0.1f; 
	runTurntableGet(timerun);
}

void TurntableSystem::runTurntableGet(float time)
{
	this->schedule(schedule_selector(TurntableSystem::runAct), time); 
}


void TurntableSystem::runAct(float time)
{
	vector<int> gezi_l = GlobalInfo::getInstance()->get_gizilist();
	//做事儿
	if(gezi_l.size()>0)
	{
		if(fnum>gezi_l.size()-1)
		{
			fnum = 0;
		}
		int bid = gezi_l.at(fnum);
		changeBox(bid,true);
		//再把上一个变回来
		int lastnum = fnum-1;
		if(lastnum<0)
		{
			lastnum=gezi_l.size()-1;
		}
		int lastid = gezi_l.at(lastnum);
		changeBox(lastid,false);
		fnum++;
	}
	runnum++;
	this->unschedule(schedule_selector(TurntableSystem::runAct)); 
	CCLOG("------%f----times=%d-",time,runnum);
	if(runnum<25)
	{
		float nexttime =  time+runnum*0.01f;
		if(nexttime>=1.5f)
		{
			nexttime=1.5f;
		}
		this->schedule(schedule_selector(TurntableSystem::runAct),nexttime);
	}
}

void TurntableSystem::changeBox(int boxid,bool change)
{
	CCPoint thisboxpiont = this->getChildByTag(TAG_ZP_BD)->getChildByTag(boxid)->getPosition();
	this->getChildByTag(TAG_ZP_BD)->removeChildByTag(boxid);
	Zp_BoxData* thisbox = new Zp_BoxData();
	thisbox->set_boxid(boxid);
	thisbox->set_xuanzhong(change);
	thisbox->set_boxReward(getReward(boxid%6));
	thisbox->set_point(thisboxpiont);
	Gzi* gz = new Gzi((CCSprite*)this->getChildByTag(TAG_ZP_BD),thisbox);
}

int TurntableSystem::getReward(int id)
{
	switch (id)
	{
	case 0:
		return 500;
		break;
	case 1:
		return 1000;
		break;
	case 2:
		return 10000;
		break;
	case 3:
		return 100000;
		break;
	case 4:
		return 1000000;
		break;
	case 5:
		return 0;
		break;
	default:
		return 0;
		break;
	}
}

TurntableSystem::~TurntableSystem(void)
{
}

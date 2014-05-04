#include "Gzi.h"
#include "../ZhuanPanSystem/Zp_ImgPath.h"
#include "../VisibleRect.h"

Gzi::Gzi(CCSprite* sp,Zp_BoxData* data)
{
	string setbd;
	if(data->get_xuanzhong()==true)
	{
		setbd = IMG_ZP_KUANGBD_XUANZHONG;
	}
	else
	{
		setbd = IMG_ZP_KUANGBD;
	}
	CCSprite* bd = CCSprite::create(setbd.c_str());
	bd->setPosition(data->get_point());
	int bd_w = bd->getContentSize().width;
	int bd_h = bd->getContentSize().height;
	CCSprite* chips_500 = CCSprite::create(IMG_ZP_500.c_str());
	CCSprite* chips_1000 = CCSprite::create(IMG_ZP_1000.c_str());
	CCSprite* chips_1w = CCSprite::create(IMG_ZP_1w.c_str());
	CCSprite* chips_10w = CCSprite::create(IMG_ZP_10w.c_str());
	CCSprite* chips_100w = CCSprite::create(IMG_ZP_100w.c_str());
	CCSprite* chips_meiyou = CCSprite::create(IMG_ZP_MEIYOU.c_str());

	switch (data->get_boxid())
	{

	case 0:
		chips_500->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_500,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 1:
		chips_1000->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1000,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 2:
		chips_1w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1w,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 3:
		chips_10w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_10w,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 4:
		chips_100w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_100w,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 5:
		chips_meiyou->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_meiyou,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 6:
		chips_500->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_500,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 7:
		chips_1000->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1000,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 8:
		chips_1w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 9:
		chips_10w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_10w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 10:
		chips_100w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_100w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 11:
		chips_meiyou->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_meiyou,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 12:
		chips_500->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_500,4,TAG_ZP_GEZI_NEIRONG);
		break;
	case 13:
		chips_1000->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1000,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 14:
		chips_1w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 15:
		chips_10w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_10w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 16:
		chips_100w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_100w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 17:
		chips_meiyou->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_meiyou,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 18:
		chips_500->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_500,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 19:
		chips_1000->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1000,4,TAG_ZP_GEZI_NEIRONG);
		break;

	case 20:
		chips_1w->setPosition(ccp(bd_w/2,bd_h/2));
		bd->addChild(chips_1w,4,TAG_ZP_GEZI_NEIRONG);
		break;

	
	default:
		break;
	}

	sp->addChild(bd,3,data->get_boxid());
}

Gzi::~Gzi(void)
{
}

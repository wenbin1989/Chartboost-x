#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    m_interstitialShowed = false;
    
    ChartboostX::sharedChartboostX()->setDelegate(this);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello Chartboost-X", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    
    CCMenuItemFont* pCacheItem = CCMenuItemFont::create("Cache Interstitial", this, menu_selector(HelloWorld::menuCacheCallback));
    pCacheItem->setFontSizeObj(TITLE_FONT_SIZE);
    pCacheItem->setPosition(ccp(origin.x + visibleSize.width/4 ,
                                origin.y + visibleSize.height/2));
    pMenu->addChild(pCacheItem);
    
    CCMenuItemFont* pShowItem = CCMenuItemFont::create("Show Interstitial", this, menu_selector(HelloWorld::menuShowCallback));
    pShowItem->setPosition(ccp(origin.x + visibleSize.width*3/4 ,
                                origin.y + visibleSize.height/2));
    pShowItem->setFontSizeObj(TITLE_FONT_SIZE);
    pMenu->addChild(pShowItem);
    
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::menuCacheCallback(CCObject* pSender)
{
    ChartboostX::sharedChartboostX()->cacheInterstitial();
}

void HelloWorld::menuShowCallback(CCObject* pSender)
{
    ChartboostX::sharedChartboostX()->showInterstitial();
}

bool HelloWorld::shouldDisplayInterstitial(const char* location)
{
    CCLOG("about to display interstitial at location %s", location);
    
    return !m_interstitialShowed;
}

void HelloWorld::didCacheInterstitial(const char* location)
{
    CCLOG("did cache interstitial at location %s", location);
}

void HelloWorld::didDismissInterstitial(const char* location)
{
    CCLOG("did dismiss interstitial at location %s", location);
    
    m_interstitialShowed = true;
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
}

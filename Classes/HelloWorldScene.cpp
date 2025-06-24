#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

// 创建场景实例
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// 当文件加载失败时打印错误信息，避免程序崩溃
static void problemLoading(const char* filename)
{
    printf("加载文件时出错: %s\n", filename);
    printf("根据编译方式不同，你可能需要在HelloWorldScene.cpp的文件名前添加'Resources/'\n");
}

// 在"init"方法中初始化场景实例
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. 首先调用父类初始化
    if (!Scene::init())
    {
        return false;
    }

    // 初始化场景资源管理器
    auto resourceManager = SceneResourceManager::getInstance();
    resourceManager->init(this);

    

    return true;
}





// 关闭按钮回调函数
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    // 关闭cocos2d-x游戏场景并退出应用程序
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);  // iOS平台需要显式退出
#endif
}
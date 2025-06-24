#include "AppDelegate.h"
#include "HelloWorldScene.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "不要同时使用AudioEngine和SimpleAudioEngine。请在游戏中选择其一！"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

// 设计分辨率大小
static cocos2d::Size designResolutionSize = cocos2d::Size(1080, 2080);
// 小分辨率大小
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
// 中等分辨率大小
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
// 大分辨率大小
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

// 构造函数
AppDelegate::AppDelegate()
{
}

// 析构函数
AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// 如果你想使用不同的上下文，修改glContextAttrs的值
// 这将影响所有平台
void AppDelegate::initGLContextAttrs()
{
    // 设置OpenGL上下文属性：红、绿、蓝、透明度、深度、模板、多重采样数
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

    GLView::setGLContextAttrs(glContextAttrs);
}

// 如果你想使用包管理器安装更多包，
// 不要修改或删除此函数
static int register_all_packages()
{
    return 0; // 包管理器标志
}

// 应用程序启动完成时调用
bool AppDelegate::applicationDidFinishLaunching() {
    // 初始化导演
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("card_2dx", cocos2d::Rect(0, 0, 1080, 2080),0.5); // 直接指定窗口大小
        glview->setDesignResolutionSize(1080, 2080, ResolutionPolicy::FIXED_WIDTH);
#else
        glview = GLViewImpl::create("card_2dx");
#endif
        director->setOpenGLView(glview);
    }

    // 开启FPS显示
    director->setDisplayStats(false);

    // 设置FPS。如果不调用此函数，默认值为1.0/60
    director->setAnimationInterval(1.0f / 60);

    // 设置设计分辨率
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();

    // 如果屏幕高度大于中等分辨率的高度
    if (frameSize.height > mediumResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
    }
    // 如果屏幕高度大于小分辨率的高度
    else if (frameSize.height > smallResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
    }
    // 如果屏幕高度小于中等分辨率的高度
    else
    {
        director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
    }

    // 注册所有包
    register_all_packages();

    // 创建场景，这是一个自动释放对象
    auto scene = HelloWorld::createScene();

    // 运行场景
    director->runWithScene(scene);

    return true;
}

// 当应用程序处于非活动状态时调用。注意，当接收到电话时会调用此函数
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// 当应用程序再次处于活动状态时调用
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

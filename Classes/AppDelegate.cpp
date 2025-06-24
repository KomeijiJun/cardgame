#include "AppDelegate.h"
#include "HelloWorldScene.h"

// #define USE_AUDIO_ENGINE 1
// #define USE_SIMPLE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE && USE_SIMPLE_AUDIO_ENGINE
#error "��Ҫͬʱʹ��AudioEngine��SimpleAudioEngine��������Ϸ��ѡ����һ��"
#endif

#if USE_AUDIO_ENGINE
#include "audio/include/AudioEngine.h"
using namespace cocos2d::experimental;
#elif USE_SIMPLE_AUDIO_ENGINE
#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;
#endif

USING_NS_CC;

// ��Ʒֱ��ʴ�С
static cocos2d::Size designResolutionSize = cocos2d::Size(1080, 2080);
// С�ֱ��ʴ�С
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
// �еȷֱ��ʴ�С
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1024, 768);
// ��ֱ��ʴ�С
static cocos2d::Size largeResolutionSize = cocos2d::Size(2048, 1536);

// ���캯��
AppDelegate::AppDelegate()
{
}

// ��������
AppDelegate::~AppDelegate()
{
#if USE_AUDIO_ENGINE
    AudioEngine::end();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::end();
#endif
}

// �������ʹ�ò�ͬ�������ģ��޸�glContextAttrs��ֵ
// �⽫Ӱ������ƽ̨
void AppDelegate::initGLContextAttrs()
{
    // ����OpenGL���������ԣ��졢�̡�����͸���ȡ���ȡ�ģ�塢���ز�����
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };

    GLView::setGLContextAttrs(glContextAttrs);
}

// �������ʹ�ð���������װ�������
// ��Ҫ�޸Ļ�ɾ���˺���
static int register_all_packages()
{
    return 0; // ����������־
}

// Ӧ�ó����������ʱ����
bool AppDelegate::applicationDidFinishLaunching() {
    // ��ʼ������
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("card_2dx", cocos2d::Rect(0, 0, 1080, 2080),0.5); // ֱ��ָ�����ڴ�С
        glview->setDesignResolutionSize(1080, 2080, ResolutionPolicy::FIXED_WIDTH);
#else
        glview = GLViewImpl::create("card_2dx");
#endif
        director->setOpenGLView(glview);
    }

    // ����FPS��ʾ
    director->setDisplayStats(false);

    // ����FPS����������ô˺�����Ĭ��ֵΪ1.0/60
    director->setAnimationInterval(1.0f / 60);

    // ������Ʒֱ���
    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();

    // �����Ļ�߶ȴ����еȷֱ��ʵĸ߶�
    if (frameSize.height > mediumResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(largeResolutionSize.height / designResolutionSize.height, largeResolutionSize.width / designResolutionSize.width));
    }
    // �����Ļ�߶ȴ���С�ֱ��ʵĸ߶�
    else if (frameSize.height > smallResolutionSize.height)
    {
        director->setContentScaleFactor(MIN(mediumResolutionSize.height / designResolutionSize.height, mediumResolutionSize.width / designResolutionSize.width));
    }
    // �����Ļ�߶�С���еȷֱ��ʵĸ߶�
    else
    {
        director->setContentScaleFactor(MIN(smallResolutionSize.height / designResolutionSize.height, smallResolutionSize.width / designResolutionSize.width));
    }

    // ע�����а�
    register_all_packages();

    // ��������������һ���Զ��ͷŶ���
    auto scene = HelloWorld::createScene();

    // ���г���
    director->runWithScene(scene);

    return true;
}

// ��Ӧ�ó����ڷǻ״̬ʱ���á�ע�⣬�����յ��绰ʱ����ô˺���
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::pauseAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
#endif
}

// ��Ӧ�ó����ٴδ��ڻ״̬ʱ����
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

#if USE_AUDIO_ENGINE
    AudioEngine::resumeAll();
#elif USE_SIMPLE_AUDIO_ENGINE
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
#endif
}

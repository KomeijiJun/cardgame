#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

// ��������ʵ��
Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// ���ļ�����ʧ��ʱ��ӡ������Ϣ������������
static void problemLoading(const char* filename)
{
    printf("�����ļ�ʱ����: %s\n", filename);
    printf("���ݱ��뷽ʽ��ͬ���������Ҫ��HelloWorldScene.cpp���ļ���ǰ���'Resources/'\n");
}

// ��"init"�����г�ʼ������ʵ��
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. ���ȵ��ø����ʼ��
    if (!Scene::init())
    {
        return false;
    }

    // ��ʼ��������Դ������
    auto resourceManager = SceneResourceManager::getInstance();
    resourceManager->init(this);

    

    return true;
}





// �رհ�ť�ص�����
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    // �ر�cocos2d-x��Ϸ�������˳�Ӧ�ó���
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);  // iOSƽ̨��Ҫ��ʽ�˳�
#endif
}
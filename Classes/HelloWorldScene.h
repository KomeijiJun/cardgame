#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../Classes/controllers/SceneResourceManager.h"
#include "../Classes/models/LevelDataParser.h"

/**
 * HelloWorld������ - ��Ϸ������
 * �̳���cocos2d::Scene������Ϸ����ʱ�Ļ���������Ԫ
 */
class HelloWorld : public cocos2d::Scene
{
public:
    /**
     * ��������ʵ���ľ�̬��������
     * @return ����HelloWorld����������ָ��
     */
    static cocos2d::Scene* createScene();

    /**
     * ��ʼ����������
     * @return ��ʼ���ɹ�����true��ʧ�ܷ���false
     */
    virtual bool init();

    /**
     * �رհ�ť�ص�����
     * @param pSender �¼�����������
     */
    void menuCloseCallback(cocos2d::Ref* pSender);

    /**
     * �Զ�����create()��createWithArgs()�����ĺ�
     * �ṩ������ı�׼ʵ�����ӿ�
     */
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
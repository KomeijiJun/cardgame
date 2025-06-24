// SceneResourceManager.h
#ifndef __SCENE_RESOURCE_MANAGER_H__
#define __SCENE_RESOURCE_MANAGER_H__

#include "cocos2d.h"
#include "cocos2d.h"
#include "../layers/BackgroundLayer.h"
#include "../layers/CardLayer.h"
#include "../models/LevelDataParser.h"

class SceneResourceManager
{
public:
    // ����ģʽʵ��
    static SceneResourceManager* getInstance();
    static void destroyInstance();

    // ��ʼ����Դ������
    bool init(cocos2d::Node* parentNode);

    // ��ȡ����ͼ��
    BackgroundLayer* getBackgroundLayer() const { return m_backgroundLayer; }

private:
    // ����ģʽ���캯��
    SceneResourceManager();
    virtual ~SceneResourceManager();

    // ��ֹ����
    SceneResourceManager(const SceneResourceManager&) = delete;
    SceneResourceManager& operator=(const SceneResourceManager&) = delete;

    // ��Ա����
    static SceneResourceManager* s_instance;
    BackgroundLayer* m_backgroundLayer;  // ����ͼ��
};

#endif // __SCENE_RESOURCE_MANAGER_H__
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
    // 单例模式实现
    static SceneResourceManager* getInstance();
    static void destroyInstance();

    // 初始化资源管理器
    bool init(cocos2d::Node* parentNode);

    // 获取背景图层
    BackgroundLayer* getBackgroundLayer() const { return m_backgroundLayer; }

private:
    // 单例模式构造函数
    SceneResourceManager();
    virtual ~SceneResourceManager();

    // 禁止拷贝
    SceneResourceManager(const SceneResourceManager&) = delete;
    SceneResourceManager& operator=(const SceneResourceManager&) = delete;

    // 成员变量
    static SceneResourceManager* s_instance;
    BackgroundLayer* m_backgroundLayer;  // 背景图层
};

#endif // __SCENE_RESOURCE_MANAGER_H__
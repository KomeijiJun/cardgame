#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "../Classes/controllers/SceneResourceManager.h"
#include "../Classes/models/LevelDataParser.h"

/**
 * HelloWorld场景类 - 游戏主场景
 * 继承自cocos2d::Scene，是游戏运行时的基本场景单元
 */
class HelloWorld : public cocos2d::Scene
{
public:
    /**
     * 创建场景实例的静态工厂方法
     * @return 返回HelloWorld场景的智能指针
     */
    static cocos2d::Scene* createScene();

    /**
     * 初始化场景内容
     * @return 初始化成功返回true，失败返回false
     */
    virtual bool init();

    /**
     * 关闭按钮回调函数
     * @param pSender 事件发送者引用
     */
    void menuCloseCallback(cocos2d::Ref* pSender);

    /**
     * 自动生成create()和createWithArgs()方法的宏
     * 提供场景类的标准实例化接口
     */
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
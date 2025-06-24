// BackgroundLayer.h
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
    CREATE_FUNC(BackgroundLayer);

    // 初始化方法
    virtual bool init();

private:
    // 初始化背景
    void initBackground();
};

#endif // __BACKGROUND_LAYER_H__
// BackgroundLayer.h
#ifndef __BACKGROUND_LAYER_H__
#define __BACKGROUND_LAYER_H__

#include "cocos2d.h"

class BackgroundLayer : public cocos2d::Layer
{
public:
    CREATE_FUNC(BackgroundLayer);

    // ��ʼ������
    virtual bool init();

private:
    // ��ʼ������
    void initBackground();
};

#endif // __BACKGROUND_LAYER_H__
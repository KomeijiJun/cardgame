// BackgroundLayer.cpp
#include "BackgroundLayer.h"

USING_NS_CC;

bool BackgroundLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    initBackground();
    return true;
}

void BackgroundLayer::initBackground()
{
    // 获取可见区域大小和原点
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 计算上下的高度
    float upperHeight = visibleSize.height * 2.8f / 4.0f;
    float lowerHeight = visibleSize.height * 1.2f / 4.0f;

    // 创建上半部分（棕色）
    auto upperPart = DrawNode::create();
    Vec2 upperVertices[4] = {
        Vec2(origin.x, origin.y + lowerHeight),
        Vec2(origin.x + visibleSize.width, origin.y + lowerHeight),
        Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height),
        Vec2(origin.x, origin.y + visibleSize.height)
    };
    upperPart->drawSolidPoly(upperVertices, 4, Color4F(0.54f, 0.27f, 0.07f, 1.0f)); // 棕色
    this->addChild(upperPart);

    // 创建下半部分（紫色）
    auto lowerPart = DrawNode::create();
    Vec2 lowerVertices[4] = {
        Vec2(origin.x, origin.y),
        Vec2(origin.x + visibleSize.width, origin.y),
        Vec2(origin.x + visibleSize.width, origin.y + lowerHeight),
        Vec2(origin.x, origin.y + lowerHeight)
    };
    lowerPart->drawSolidPoly(lowerVertices, 4, Color4F(0.5f, 0.0f, 0.5f, 1.0f)); // 紫色
    this->addChild(lowerPart);
}
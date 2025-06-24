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
    // ��ȡ�ɼ������С��ԭ��
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // �������µĸ߶�
    float upperHeight = visibleSize.height * 2.8f / 4.0f;
    float lowerHeight = visibleSize.height * 1.2f / 4.0f;

    // �����ϰ벿�֣���ɫ��
    auto upperPart = DrawNode::create();
    Vec2 upperVertices[4] = {
        Vec2(origin.x, origin.y + lowerHeight),
        Vec2(origin.x + visibleSize.width, origin.y + lowerHeight),
        Vec2(origin.x + visibleSize.width, origin.y + visibleSize.height),
        Vec2(origin.x, origin.y + visibleSize.height)
    };
    upperPart->drawSolidPoly(upperVertices, 4, Color4F(0.54f, 0.27f, 0.07f, 1.0f)); // ��ɫ
    this->addChild(upperPart);

    // �����°벿�֣���ɫ��
    auto lowerPart = DrawNode::create();
    Vec2 lowerVertices[4] = {
        Vec2(origin.x, origin.y),
        Vec2(origin.x + visibleSize.width, origin.y),
        Vec2(origin.x + visibleSize.width, origin.y + lowerHeight),
        Vec2(origin.x, origin.y + lowerHeight)
    };
    lowerPart->drawSolidPoly(lowerVertices, 4, Color4F(0.5f, 0.0f, 0.5f, 1.0f)); // ��ɫ
    this->addChild(lowerPart);
}
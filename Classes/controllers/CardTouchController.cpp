// ClickMoveController.cpp
#include "CardTouchController.h"

ClickMoveController* ClickMoveController::create(CardView* cardView, const cocos2d::Vec2& targetPos)
{
    auto controller = new (std::nothrow) ClickMoveController();
    if (controller && controller->init(cardView, targetPos))
    {
        controller->autorelease();
        return controller;
    }
    CC_SAFE_DELETE(controller);
    return nullptr;
}

bool ClickMoveController::init(CardView* cardView, const cocos2d::Vec2& targetPos)
{

    if (!Node::init())
    {
        return false;
    }

    m_cardView = cardView;
    m_targetPos = targetPos;

    setupTouchListener(cardView);

    return true;
}

void ClickMoveController::setupTouchListener(CardView* cardView)
{
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = [this, cardView](cocos2d::Touch* touch, cocos2d::Event* event) {
        auto pos = touch->getLocation();
        if (cardView->getBoundingBox().containsPoint(pos))
        {
            onCardClicked(touch, event, cardView, m_targetPos);
            return true;
        }
        return false;
        };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void ClickMoveController::onCardClicked(cocos2d::Touch* touch, cocos2d::Event* event, CardView* cardView, const cocos2d::Vec2& targetPos)
{
    cardView->moveTo(targetPos, 0.3f);
}
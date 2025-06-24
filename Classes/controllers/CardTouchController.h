// ClickMoveController.h
#ifndef CLICK_MOVE_CONTROLLER_H
#define CLICK_MOVE_CONTROLLER_H

#include "cocos2d.h"
#include "../views/CardView.h"

class ClickMoveController : public cocos2d::Node
{
public:
    static ClickMoveController* create(CardView* cardView, const cocos2d::Vec2& targetPos);
    virtual bool init(CardView* cardView, const cocos2d::Vec2& targetPos);

private:
    void setupTouchListener(CardView* cardView);
    void onCardClicked(cocos2d::Touch* touch, cocos2d::Event* event, CardView* cardView, const cocos2d::Vec2& targetPos);

    CardView* m_cardView;
    cocos2d::Vec2 m_targetPos;
};

#endif // CLICK_MOVE_CONTROLLER_H
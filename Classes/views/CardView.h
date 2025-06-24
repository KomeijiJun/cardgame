// Classes/views/CardView.h
#ifndef CARD_VIEW_H
#define CARD_VIEW_H

#include "cocos2d.h"
#include "../models/CardModel.h"

class CardView : public Node {
public:
    static CardView* create(const CardModel& model, bool isBig = false);
    void setModel(const CardModel& model);
    void moveTo(const Vec2& pos, float duration = 0.3f);

private:
    bool init(const CardModel& model, bool isBig);
    void updateDisplay();

    CardModel _model;
    bool _isBig = false;
    Sprite* _back = nullptr;   // ÅÆ±³
    Sprite* _suit = nullptr;   // »¨É«
    Sprite* _number = nullptr; // Êý×Ö
};

#endif // CARD_VIEW_H
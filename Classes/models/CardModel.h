// Classes/models/CardModel.h
#ifndef CARD_MODEL_H
#define CARD_MODEL_H

#include "cocos2d.h"
#include "../configs/CardEnums.h"

using namespace CardEnums;
using namespace cocos2d;

class CardModel {
public:
    enum Zone { Playfield, Stack }; // À˘ Ù«¯”Ú

    CardFaceType getFace() const { return _face; }
    void setFace(CardFaceType face) { _face = face; }

    CardSuitType getSuit() const { return _suit; }
    void setSuit(CardSuitType suit) { _suit = suit; }

    const Vec2& getPosition() const { return _position; }
    void setPosition(const Vec2& pos) { _position = pos; }

    bool isVisible() const { return _visible; }
    void setVisible(bool visible) { _visible = visible; }

    Zone getZone() const { return _zone; }
    void setZone(Zone zone) { _zone = zone; }

    int getIndex() const { return _index; }
    void setIndex(int index) { _index = index; }

private:
    CardFaceType _face = CFT_NONE;
    CardSuitType _suit = CST_NONE;
    Vec2 _position;
    bool _visible = false;
    Zone _zone = Zone::Playfield;
    int _index = -1;
};

#endif // CARD_MODEL_H
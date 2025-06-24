// CardLayer.h
#ifndef CARD_LAYER_H
#define CARD_LAYER_H

#include "cocos2d.h"
#include "../views/CardView.h"
#include "../models/LevelDataParser.h"

class CardLayer : public cocos2d::Layer
{
public:
    CREATE_FUNC(CardLayer);

    virtual bool init();

private:
    void createCardsFromLevelData(const LevelDataParser::LevelData& levelData);
};

#endif // CARD_LAYER_H
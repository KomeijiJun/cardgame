// Classes/utils/CardUtil.h
#ifndef CARD_UTIL_H
#define CARD_UTIL_H

#include "../configs/CardEnums.h"
#include "cocos2d.h"

using namespace CardEnums;

class CardUtil {
public:
    static std::string getSuitPath(CardSuitType suit);
    static std::string getNumberPath(CardFaceType face, CardSuitType suit, bool isBig);
};

#endif // CARD_UTIL_H
// Classes/configs/enums/CardEnums.h
#ifndef CARD_ENUMS_H
#define CARD_ENUMS_H

namespace CardEnums {
    enum CardSuitType {
        CST_NONE = -1,
        CST_CLUBS,      // Ã·»¨ (0)
        CST_DIAMONDS,   // ·½¿é (1)
        CST_HEARTS,     // ºìÌÒ (2)
        CST_SPADES,     // ºÚÌÒ (3)
        CST_NUM_TYPES
    };

    enum CardFaceType {
        CFT_NONE = -1,
        CFT_ACE,        // A (0)
        CFT_TWO,        // 2 (1)
        CFT_THREE,      // 3 (2)
        CFT_FOUR,       // 4 (3)
        CFT_FIVE,       // 5 (4)
        CFT_SIX,        // 6 (5)
        CFT_SEVEN,      // 7 (6)
        CFT_EIGHT,      // 8 (7)
        CFT_NINE,       // 9 (8)
        CFT_TEN,        // 10 (9)
        CFT_JACK,       // J (10)
        CFT_QUEEN,      // Q (11)
        CFT_KING,       // K (12)
        CFT_NUM_TYPES
    };
}

#endif // CARD_ENUMS_H
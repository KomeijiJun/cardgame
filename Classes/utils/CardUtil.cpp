// Classes/utils/CardUtil.cpp
#include "CardUtil.h"

using namespace cocos2d;

/**
 * 根据花色枚举值获取对应的花色图标路径
 * @param suit 花色枚举值（来自CardEnums::CardSuitType）
 * @return 图标文件路径，无效花色返回空字符串
 */
std::string CardUtil::getSuitPath(CardSuitType suit) {
    // 通过switch判断不同花色，返回对应的图标路径
    // 所有花色图标存储在"suits/"目录下，文件名与花色对应
    switch (suit) {
    case CST_CLUBS:    return "/res/suits/club.png";    // 梅花图标
    case CST_DIAMONDS: return "/res/suits/diamond.png"; // 方块图标
    case CST_HEARTS:   return "/res/suits/heart.png";   // 红桃图标
    case CST_SPADES:   return "/res/suits/spade.png";   // 黑桃图标
    default: return "";                            // 无效花色返回空
    }
}

/**
 * 根据牌面、花色和尺寸获取对应的点数字母图标路径
 * @param face 牌面枚举值（来自CardEnums::CardFaceType）
 * @param suit 花色枚举值（用于判断颜色）
 * @param isBig 是否为大尺寸图标
 * @return 图标文件路径，无效输入返回空字符串
 */
std::string CardUtil::getNumberPath(CardFaceType face, CardSuitType suit, bool isBig) {
    // 根据花色判断图标颜色：梅花/黑桃为黑色，方块/红桃为红色
    std::string color = (suit == CST_CLUBS || suit == CST_SPADES) ? "black" : "red";
    std::string faceStr;

    // 将牌面枚举值转换为对应的字符串（A、2、3...K）
    switch (face) {
    case CFT_ACE:   faceStr = "A"; break;    // 王牌A
    case CFT_TWO:   faceStr = "2"; break;    // 数字2
    case CFT_THREE: faceStr = "3"; break;    // 数字3
    case CFT_FOUR:  faceStr = "4"; break;    // 数字4
    case CFT_FIVE:  faceStr = "5"; break;    // 数字5
    case CFT_SIX:   faceStr = "6"; break;    // 数字6
    case CFT_SEVEN: faceStr = "7"; break;    // 数字7
    case CFT_EIGHT: faceStr = "8"; break;    // 数字8
    case CFT_NINE:  faceStr = "9"; break;    // 数字9
    case CFT_TEN:   faceStr = "10"; break;   // 数字10
    case CFT_JACK:  faceStr = "J"; break;    // 花牌J
    case CFT_QUEEN: faceStr = "Q"; break;    // 花牌Q
    case CFT_KING:  faceStr = "K"; break;    // 花牌K
    default: faceStr = "";                   // 无效牌面返回空
    }

    // 根据尺寸参数确定文件名前缀（大尺寸或小尺寸）
    std::string size = isBig ? "big_" : "small_";
    // 拼接完整路径："number/[尺寸]_[颜色]_[面值].png"
    return "/res/number/" + size + color + "_" + faceStr + ".png";
}


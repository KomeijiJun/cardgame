// Classes/utils/CardUtil.cpp
#include "CardUtil.h"

using namespace cocos2d;

/**
 * ���ݻ�ɫö��ֵ��ȡ��Ӧ�Ļ�ɫͼ��·��
 * @param suit ��ɫö��ֵ������CardEnums::CardSuitType��
 * @return ͼ���ļ�·������Ч��ɫ���ؿ��ַ���
 */
std::string CardUtil::getSuitPath(CardSuitType suit) {
    // ͨ��switch�жϲ�ͬ��ɫ�����ض�Ӧ��ͼ��·��
    // ���л�ɫͼ��洢��"suits/"Ŀ¼�£��ļ����뻨ɫ��Ӧ
    switch (suit) {
    case CST_CLUBS:    return "/res/suits/club.png";    // ÷��ͼ��
    case CST_DIAMONDS: return "/res/suits/diamond.png"; // ����ͼ��
    case CST_HEARTS:   return "/res/suits/heart.png";   // ����ͼ��
    case CST_SPADES:   return "/res/suits/spade.png";   // ����ͼ��
    default: return "";                            // ��Ч��ɫ���ؿ�
    }
}

/**
 * �������桢��ɫ�ͳߴ��ȡ��Ӧ�ĵ�����ĸͼ��·��
 * @param face ����ö��ֵ������CardEnums::CardFaceType��
 * @param suit ��ɫö��ֵ�������ж���ɫ��
 * @param isBig �Ƿ�Ϊ��ߴ�ͼ��
 * @return ͼ���ļ�·������Ч���뷵�ؿ��ַ���
 */
std::string CardUtil::getNumberPath(CardFaceType face, CardSuitType suit, bool isBig) {
    // ���ݻ�ɫ�ж�ͼ����ɫ��÷��/����Ϊ��ɫ������/����Ϊ��ɫ
    std::string color = (suit == CST_CLUBS || suit == CST_SPADES) ? "black" : "red";
    std::string faceStr;

    // ������ö��ֵת��Ϊ��Ӧ���ַ�����A��2��3...K��
    switch (face) {
    case CFT_ACE:   faceStr = "A"; break;    // ����A
    case CFT_TWO:   faceStr = "2"; break;    // ����2
    case CFT_THREE: faceStr = "3"; break;    // ����3
    case CFT_FOUR:  faceStr = "4"; break;    // ����4
    case CFT_FIVE:  faceStr = "5"; break;    // ����5
    case CFT_SIX:   faceStr = "6"; break;    // ����6
    case CFT_SEVEN: faceStr = "7"; break;    // ����7
    case CFT_EIGHT: faceStr = "8"; break;    // ����8
    case CFT_NINE:  faceStr = "9"; break;    // ����9
    case CFT_TEN:   faceStr = "10"; break;   // ����10
    case CFT_JACK:  faceStr = "J"; break;    // ����J
    case CFT_QUEEN: faceStr = "Q"; break;    // ����Q
    case CFT_KING:  faceStr = "K"; break;    // ����K
    default: faceStr = "";                   // ��Ч���淵�ؿ�
    }

    // ���ݳߴ����ȷ���ļ���ǰ׺����ߴ��С�ߴ磩
    std::string size = isBig ? "big_" : "small_";
    // ƴ������·����"number/[�ߴ�]_[��ɫ]_[��ֵ].png"
    return "/res/number/" + size + color + "_" + faceStr + ".png";
}


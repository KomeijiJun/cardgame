// LevelDataParser.h
#ifndef __LEVEL_DATA_PARSER_H__
#define __LEVEL_DATA_PARSER_H__

#include <fstream>
#include "cocos2d.h"
#include <vector>
#include <string>

class LevelDataParser
{
public:
    // �������ݽṹ
    struct CardData
    {
        int cardFace;  // ����ֵ
        int cardSuit;  // ��ɫ
        cocos2d::Vec2 position;  // λ��
    };

    // �ؿ����ݽṹ
    struct LevelData
    {
        std::vector<CardData> playfieldCards;  // ��Ϸ������
        std::vector<CardData> stackCards;      // �ѵ�������
    };

    // �����ؿ�����
    static LevelData parseLevelData(const std::string& filePath);
    // ���� LevelData �� .txt �ļ�
    static bool exportLevelDataToTxt(const LevelData& levelData, const std::string& outputFilePath);
};

#endif // __LEVEL_DATA_PARSER_H__
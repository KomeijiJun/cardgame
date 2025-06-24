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
    // 卡牌数据结构
    struct CardData
    {
        int cardFace;  // 牌面值
        int cardSuit;  // 花色
        cocos2d::Vec2 position;  // 位置
    };

    // 关卡数据结构
    struct LevelData
    {
        std::vector<CardData> playfieldCards;  // 游戏区卡牌
        std::vector<CardData> stackCards;      // 堆叠区卡牌
    };

    // 解析关卡数据
    static LevelData parseLevelData(const std::string& filePath);
    // 导出 LevelData 到 .txt 文件
    static bool exportLevelDataToTxt(const LevelData& levelData, const std::string& outputFilePath);
};

#endif // __LEVEL_DATA_PARSER_H__
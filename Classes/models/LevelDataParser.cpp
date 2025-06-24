// LevelDataParser.cpp
#include "LevelDataParser.h"
#include "cocos-ext.h"  // 用于JSON解析

USING_NS_CC;
USING_NS_CC_EXT;

LevelDataParser::LevelData LevelDataParser::parseLevelData(const std::string& filePath)
{
    LevelData levelData;

    // 读取JSON文件
    std::string fileContent = FileUtils::getInstance()->getStringFromFile(filePath);
    if (fileContent.empty())
    {
        CCLOGERROR("Failed to read level data from: %s", filePath.c_str());
        return levelData;
    }

    // 解析JSON
    rapidjson::Document doc;
    doc.Parse<0>(fileContent.c_str());

    if (doc.HasParseError())
    {
        CCLOGERROR("JSON parse error: %s", doc.GetParseError());
        return levelData;
    }

    // 解析游戏区卡牌
    if (doc.HasMember("Playfield") && doc["Playfield"].IsArray())
    {
        const rapidjson::Value& playfieldArray = doc["Playfield"];
        for (rapidjson::SizeType i = 0; i < playfieldArray.Size(); i++)
        {
            const rapidjson::Value& cardObj = playfieldArray[i];
            CardData card;

            card.cardFace = cardObj["CardFace"].GetInt();
            card.cardSuit = cardObj["CardSuit"].GetInt();

            const rapidjson::Value& posObj = cardObj["Position"];
            card.position.x = posObj["x"].GetFloat();
            card.position.y = posObj["y"].GetFloat();

            levelData.playfieldCards.push_back(card);
        }
    }

    // 解析堆叠区卡牌
    if (doc.HasMember("Stack") && doc["Stack"].IsArray())
    {
        const rapidjson::Value& stackArray = doc["Stack"];
        for (rapidjson::SizeType i = 0; i < stackArray.Size(); i++)
        {
            const rapidjson::Value& cardObj = stackArray[i];
            CardData card;

            card.cardFace = cardObj["CardFace"].GetInt();
            card.cardSuit = cardObj["CardSuit"].GetInt();

            const rapidjson::Value& posObj = cardObj["Position"];
            card.position.x = posObj["x"].GetFloat();
            card.position.y = posObj["y"].GetFloat();

            levelData.stackCards.push_back(card);
        }
    }

    return levelData;
}

bool LevelDataParser::exportLevelDataToTxt(const LevelData& levelData, const std::string& outputFilePath)
{
    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open())
    {
        CCLOGERROR("Failed to open output file: %s", outputFilePath.c_str());
        return false;
    }

    // 导出游戏场卡片数据
    outputFile << "Playfield Cards:\n";
    for (const auto& card : levelData.playfieldCards)
    {
        outputFile << "Face: " << card.cardFace << ", Suit: " << card.cardSuit
            << ", Position: (" << card.position.x << ", " << card.position.y << ")\n";
    }

    // 导出栈卡片数据
    outputFile << "\nStack Cards:\n";
    for (const auto& card : levelData.stackCards)
    {
        outputFile << "Face: " << card.cardFace << ", Suit: " << card.cardSuit
            << ", Position: (" << card.position.x << ", " << card.position.y << ")\n";
    }

    outputFile.close();
    return true;
}

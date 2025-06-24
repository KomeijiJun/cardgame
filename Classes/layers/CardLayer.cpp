// CardLayer.cpp
#include "CardLayer.h"
#include "../models/CardModel.h"
#include "../controllers/CardTouchController.h"
#include <iostream> 

USING_NS_CC;

bool CardLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // 解析JSON文件获取关卡数据
    std::string filePath = "game1.json"; // 替换为实际的JSON文件路径
    LevelDataParser::LevelData levelData = LevelDataParser::parseLevelData(filePath);


    // 测试：创建CardModel实例
    //CardModel cardModel;
    //cardModel.setFace(CardEnums::CardFaceType::CFT_THREE);
    //cardModel.setSuit(CardEnums::CardSuitType::CST_CLUBS);
    //cardModel.setPosition(Vec2(320, 400)); // 初始位置
    //cardModel.setVisible(true);
    // 创建CardView实例
    //CardView* cardView = CardView::create(cardModel, TRUE);
    //if (cardView)
    //{
        // 将CardView添加到当前图层
     //   this->addChild(cardView);

        // 创建点击移动控制器
      //  cocos2d::Vec2 targetPos(1000, 1000); // 指定目标位置
       // auto controller = ClickMoveController::create(cardView, targetPos);
       // this->addChild(controller);
    //}
    // 根据关卡数据创建卡牌
    createCardsFromLevelData(levelData);

    return true;
}

void CardLayer::createCardsFromLevelData(const LevelDataParser::LevelData& levelData)
{
    // 处理游戏场卡牌
    for (const auto& cardData : levelData.playfieldCards)
    {
        // 创建CardModel实例
        CardModel cardModel;
        cardModel.setFace(static_cast<CardEnums::CardFaceType>(cardData.cardFace));
        cardModel.setSuit(static_cast<CardEnums::CardSuitType>(cardData.cardSuit));
        cardModel.setPosition(cardData.position);
        cardModel.setVisible(true);

        // 创建CardView实例
        CardView* cardView = CardView::create(cardModel, false);
        if (cardView)
        {
            // 将CardView添加到当前图层
            this->addChild(cardView);

            // 创建点击移动控制器
            cocos2d::Vec2 targetPos(100, 100); // 指定目标位置
            auto controller = ClickMoveController::create(cardView, targetPos);
            this->addChild(controller);
        }
    }

    // 处理堆叠卡牌
    for (const auto& cardData : levelData.stackCards)
    {
        // 创建CardModel实例
        CardModel cardModel;
        cardModel.setFace(static_cast<CardEnums::CardFaceType>(cardData.cardFace));
        cardModel.setSuit(static_cast<CardEnums::CardSuitType>(cardData.cardSuit));
        cardModel.setPosition(cardData.position);
        cardModel.setVisible(true);

        // 创建CardView实例
        CardView* cardView = CardView::create(cardModel, false);
        if (cardView)
        {
            // 将CardView添加到当前图层
            this->addChild(cardView);

            // 创建点击移动控制器
            cocos2d::Vec2 targetPos(300, 400); // 指定目标位置
            auto controller = ClickMoveController::create(cardView, targetPos);
            this->addChild(controller);
        }
    }
}
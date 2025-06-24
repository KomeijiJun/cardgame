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

    // ����JSON�ļ���ȡ�ؿ�����
    std::string filePath = "game1.json"; // �滻Ϊʵ�ʵ�JSON�ļ�·��
    LevelDataParser::LevelData levelData = LevelDataParser::parseLevelData(filePath);


    // ���ԣ�����CardModelʵ��
    //CardModel cardModel;
    //cardModel.setFace(CardEnums::CardFaceType::CFT_THREE);
    //cardModel.setSuit(CardEnums::CardSuitType::CST_CLUBS);
    //cardModel.setPosition(Vec2(320, 400)); // ��ʼλ��
    //cardModel.setVisible(true);
    // ����CardViewʵ��
    //CardView* cardView = CardView::create(cardModel, TRUE);
    //if (cardView)
    //{
        // ��CardView��ӵ���ǰͼ��
     //   this->addChild(cardView);

        // ��������ƶ�������
      //  cocos2d::Vec2 targetPos(1000, 1000); // ָ��Ŀ��λ��
       // auto controller = ClickMoveController::create(cardView, targetPos);
       // this->addChild(controller);
    //}
    // ���ݹؿ����ݴ�������
    createCardsFromLevelData(levelData);

    return true;
}

void CardLayer::createCardsFromLevelData(const LevelDataParser::LevelData& levelData)
{
    // ������Ϸ������
    for (const auto& cardData : levelData.playfieldCards)
    {
        // ����CardModelʵ��
        CardModel cardModel;
        cardModel.setFace(static_cast<CardEnums::CardFaceType>(cardData.cardFace));
        cardModel.setSuit(static_cast<CardEnums::CardSuitType>(cardData.cardSuit));
        cardModel.setPosition(cardData.position);
        cardModel.setVisible(true);

        // ����CardViewʵ��
        CardView* cardView = CardView::create(cardModel, false);
        if (cardView)
        {
            // ��CardView��ӵ���ǰͼ��
            this->addChild(cardView);

            // ��������ƶ�������
            cocos2d::Vec2 targetPos(100, 100); // ָ��Ŀ��λ��
            auto controller = ClickMoveController::create(cardView, targetPos);
            this->addChild(controller);
        }
    }

    // ����ѵ�����
    for (const auto& cardData : levelData.stackCards)
    {
        // ����CardModelʵ��
        CardModel cardModel;
        cardModel.setFace(static_cast<CardEnums::CardFaceType>(cardData.cardFace));
        cardModel.setSuit(static_cast<CardEnums::CardSuitType>(cardData.cardSuit));
        cardModel.setPosition(cardData.position);
        cardModel.setVisible(true);

        // ����CardViewʵ��
        CardView* cardView = CardView::create(cardModel, false);
        if (cardView)
        {
            // ��CardView��ӵ���ǰͼ��
            this->addChild(cardView);

            // ��������ƶ�������
            cocos2d::Vec2 targetPos(300, 400); // ָ��Ŀ��λ��
            auto controller = ClickMoveController::create(cardView, targetPos);
            this->addChild(controller);
        }
    }
}
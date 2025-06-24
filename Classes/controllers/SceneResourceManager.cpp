// SceneResourceManager.cpp
#include "SceneResourceManager.h"
#include <iostream> 
// ��ʼ����̬��Ա����
SceneResourceManager* SceneResourceManager::s_instance = nullptr;

// ��ȡ����ʵ��
SceneResourceManager* SceneResourceManager::getInstance()
{
    if (s_instance == nullptr)
    {
        s_instance = new (std::nothrow) SceneResourceManager();
        CCASSERT(s_instance, "FATAL: Not enough memory to create SceneResourceManager instance!");
    }
    return s_instance;
}

// ���ٵ���ʵ��
void SceneResourceManager::destroyInstance()
{
    CC_SAFE_DELETE(s_instance);
}

// ���캯��
SceneResourceManager::SceneResourceManager()
    : m_backgroundLayer(nullptr)
{
}

// ��������
SceneResourceManager::~SceneResourceManager()
{
    // ������Դ
    if (m_backgroundLayer)
    {
        m_backgroundLayer->removeFromParent();
        m_backgroundLayer = nullptr;
    }
}

// ��ʼ����Դ������
bool SceneResourceManager::init(cocos2d::Node* parentNode)
{
    if (parentNode == nullptr)
    {
        CCLOGERROR("SceneResourceManager::init() - parentNode is nullptr!");
        return false;
    }
    

    // ����CardLayerʵ��
    CardLayer* cardLayer = CardLayer::create();
    if (cardLayer)
    {
        // ��CardLayer��ӵ���ǰ����
        parentNode->addChild(cardLayer,10);
    }


    // ��������ͼ��
    m_backgroundLayer = BackgroundLayer::create();
    if (m_backgroundLayer)
    {
        parentNode->addChild(m_backgroundLayer, 0);  // �㼶��Ϊ0��������ײ�
        return true;
    }



    // ���� LevelDataParser ���� JSON �ļ�
//    std::string filePath = "game1.json"; // �滻Ϊʵ�ʵ� JSON �ļ�·��
//    LevelDataParser::LevelData levelData = LevelDataParser::parseLevelData(filePath);

    //���ԣ��������Ŀ�����Ϣ������txt�ĵ�
//    std::string outputFilePath = "F:\\COCOS\\output.txt";
//    if (LevelDataParser::exportLevelDataToTxt(levelData, outputFilePath))
//    {
//        std::cout << "Level data exported to " << outputFilePath << " successfully." << std::endl;
//    }
//    else
//    {
//        std::cout << "Failed to export level data." << std::endl;
//    }

    // ������������Ϸ����Ƭ����
//    for (const auto& card : levelData.playfieldCards)
//    {
//        CCLOG("Playfield Card - Face: %d, Suit: %d, Position: (%f, %f)", card.cardFace, card.cardSuit, card.position.x, card.position.y);
        // ������Ը��ݽ�����������ͷ��þ������ϷԪ��
        // ���磺
        // auto sprite = Sprite::create("card_texture.png");
        // sprite->setPosition(card.position);
        // this->addChild(sprite);
//    }

    // ����������ջ��Ƭ����
//    for (const auto& card : levelData.stackCards)
//    {
//        CCLOG("Stack Card - Face: %d, Suit: %d, Position: (%f, %f)", card.cardFace, card.cardSuit, card.position.x, card.position.y);
        // ͬ�����Ը��ݽ�����������ͷ��þ������ϷԪ��
//    }

    return false;
}
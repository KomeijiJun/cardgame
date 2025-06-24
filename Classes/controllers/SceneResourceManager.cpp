// SceneResourceManager.cpp
#include "SceneResourceManager.h"
#include <iostream> 
// 初始化静态成员变量
SceneResourceManager* SceneResourceManager::s_instance = nullptr;

// 获取单例实例
SceneResourceManager* SceneResourceManager::getInstance()
{
    if (s_instance == nullptr)
    {
        s_instance = new (std::nothrow) SceneResourceManager();
        CCASSERT(s_instance, "FATAL: Not enough memory to create SceneResourceManager instance!");
    }
    return s_instance;
}

// 销毁单例实例
void SceneResourceManager::destroyInstance()
{
    CC_SAFE_DELETE(s_instance);
}

// 构造函数
SceneResourceManager::SceneResourceManager()
    : m_backgroundLayer(nullptr)
{
}

// 析构函数
SceneResourceManager::~SceneResourceManager()
{
    // 清理资源
    if (m_backgroundLayer)
    {
        m_backgroundLayer->removeFromParent();
        m_backgroundLayer = nullptr;
    }
}

// 初始化资源管理器
bool SceneResourceManager::init(cocos2d::Node* parentNode)
{
    if (parentNode == nullptr)
    {
        CCLOGERROR("SceneResourceManager::init() - parentNode is nullptr!");
        return false;
    }
    

    // 创建CardLayer实例
    CardLayer* cardLayer = CardLayer::create();
    if (cardLayer)
    {
        // 将CardLayer添加到当前场景
        parentNode->addChild(cardLayer,10);
    }


    // 创建背景图层
    m_backgroundLayer = BackgroundLayer::create();
    if (m_backgroundLayer)
    {
        parentNode->addChild(m_backgroundLayer, 0);  // 层级设为0，放在最底层
        return true;
    }



    // 调用 LevelDataParser 解析 JSON 文件
//    std::string filePath = "game1.json"; // 替换为实际的 JSON 文件路径
//    LevelDataParser::LevelData levelData = LevelDataParser::parseLevelData(filePath);

    //测试：将解析的卡牌信息导出至txt文档
//    std::string outputFilePath = "F:\\COCOS\\output.txt";
//    if (LevelDataParser::exportLevelDataToTxt(levelData, outputFilePath))
//    {
//        std::cout << "Level data exported to " << outputFilePath << " successfully." << std::endl;
//    }
//    else
//    {
//        std::cout << "Failed to export level data." << std::endl;
//    }

    // 处理解析后的游戏场卡片数据
//    for (const auto& card : levelData.playfieldCards)
//    {
//        CCLOG("Playfield Card - Face: %d, Suit: %d, Position: (%f, %f)", card.cardFace, card.cardSuit, card.position.x, card.position.y);
        // 这里可以根据解析结果创建和放置精灵等游戏元素
        // 例如：
        // auto sprite = Sprite::create("card_texture.png");
        // sprite->setPosition(card.position);
        // this->addChild(sprite);
//    }

    // 处理解析后的栈卡片数据
//    for (const auto& card : levelData.stackCards)
//    {
//        CCLOG("Stack Card - Face: %d, Suit: %d, Position: (%f, %f)", card.cardFace, card.cardSuit, card.position.x, card.position.y);
        // 同样可以根据解析结果创建和放置精灵等游戏元素
//    }

    return false;
}
# 程序设计文档

## 一、概述

### 1.1 项目背景

本项目是一个基于 Cocos2d-x 引擎开发的卡片游戏。

### 1.2 项目目标

- 实现卡片的创建和显示，卡片包含花色和数字信息。
- 支持从 JSON 文件中读取关卡数据，动态生成卡片。
- 实现卡片的点击移动功能。
- 提供背景图层，增强游戏的视觉效果。

## 二、系统架构设计

### 2.1 整体架构

本系统采用分层架构，主要分为视图层、模型层、控制层和工具层，各层之间职责明确，降低耦合度，提高代码的可维护性和可扩展性。

### 2.2 分层架构设计

#### 2.2.1 视图层（Views）

- **CardView**：负责卡片的显示和动画效果，根据卡片模型（CardModel）的数据更新卡片的花色、数字和位置。
- **BackgroundLayer**：负责绘制游戏背景，将屏幕分为上下两部分，分别填充不同颜色。
- **CardLayer**：负责卡片的创建和管理，从 JSON 文件中读取关卡数据，根据数据创建卡片视图（CardView）并添加到场景中。

#### 2.2.2 模型层（Models）

- **CardModel**：表示卡片的抽象模型，包含卡片的花色、数字、位置、可见性、所在区域和索引等属性。
- **LevelDataParser**：负责解析 JSON 格式的关卡数据文件，将数据转换为 LevelData 结构，供 CardLayer 使用。

#### 2.2.3 控制层（Controllers）

- **CardTouchController**：负责处理卡片的点击事件，当用户点击卡片时，将卡片移动到指定位置。
- **SceneResourceManager**：负责管理场景资源，包括背景图层和卡片图层的初始化和添加。

#### 2.2.4 工具层（Utils）

- **CardUtil**：提供与卡片相关的工具方法，如根据花色和数字获取对应的图片路径。

## 三、详细设计

### 3.1 类设计

#### 3.1.1 CardView 类

- **功能**：负责卡片的显示和动画效果。

- 属性


  - `CardModel _model`：卡片的模型数据。
  - `bool _isBig`：是否为大尺寸数字。
  - `Sprite* _back`：卡片的背面精灵。
  - `Sprite* _suit`：卡片的花色精灵。
  - `Sprite* _number`：卡片的数字精灵。

- 方法


  - `static CardView* create(const CardModel& model, bool isBig = false)`：静态创建方法，用于创建 CardView 实例。
  - `void setModel(const CardModel& model)`：设置卡片的模型数据，并更新显示。
  - `void moveTo(const Vec2& pos, float duration = 0.3f)`：将卡片移动到指定位置。
  - `bool init(const CardModel& model, bool isBig)`：初始化卡片视图。
  - `void updateDisplay()`：根据模型数据更新卡片的显示。

#### 3.1.2 CardModel 类

- **功能**：表示卡片的抽象模型。

- 属性


  - `CardFaceType _face`：卡片的数字。
  - `CardSuitType _suit`：卡片的花色。
  - `Vec2 _position`：卡片的位置。
  - `bool _visible`：卡片是否可见。
  - `Zone _zone`：卡片所在的区域（游戏场或栈）。
  - `int _index`：卡片的索引。

- **方法**：提供了属性的获取和设置方法。

#### 3.1.3 CardTouchController 类

- **功能**：处理卡片的点击事件。

- 属性


  - `CardView* m_cardView`：关联的卡片视图。
  - `Vec2 m_targetPos`：卡片点击后要移动到的目标位置。

- 方法


  - `static ClickMoveController* create(CardView* cardView, const Vec2& targetPos)`：静态创建方法，用于创建 ClickMoveController 实例。
  - `virtual bool init(CardView* cardView, const Vec2& targetPos)`：初始化控制器。
  - `void setupTouchListener(CardView* cardView)`：设置触摸监听器。
  - `void onCardClicked(cocos2d::Touch* touch, cocos2d::Event* event, CardView* cardView, const cocos2d::Vec2& targetPos)`：处理卡片点击事件。

#### 3.1.4 SceneResourceManager 类

- **功能**：管理场景资源，包括背景图层和卡片图层的初始化和添加。

- 属性


  - `static SceneResourceManager* s_instance`：单例实例。
  - `BackgroundLayer* m_backgroundLayer`：背景图层。

- 方法


  - `static SceneResourceManager* getInstance()`：获取单例实例。
  - `static void destroyInstance()`：销毁单例实例。
  - `bool init(cocos2d::Node* parentNode)`：初始化场景资源。
  - `BackgroundLayer* getBackgroundLayer() const`：获取背景图层。

#### 3.1.5 BackgroundLayer 类

- **功能**：绘制游戏背景。

- 方法


  - `CREATE_FUNC(BackgroundLayer)`：创建背景图层实例。
  - `virtual bool init()`：初始化背景图层。
  - `void initBackground()`：初始化背景绘制。

#### 3.1.6 CardLayer 类

- **功能**：负责卡片的创建和管理。

- 方法


  - `CREATE_FUNC(CardLayer)`：创建卡片图层实例。
  - `virtual bool init()`：初始化卡片图层。
  - `void createCardsFromLevelData(const LevelDataParser::LevelData& levelData)`：根据关卡数据创建卡片。

#### 3.1.7 LevelDataParser 类

- **功能**：解析 JSON 格式的关卡数据文件。

- 内部结构


  - `struct CardData`：表示卡片的数据，包含数字、花色和位置。
  - `struct LevelData`：表示关卡数据，包含游戏场卡片和栈卡片。

- 方法


  - `static LevelData parseLevelData(const std::string& filePath)`：解析关卡数据文件。
  - `static bool exportLevelDataToTxt(const LevelData& levelData, const std::string& outputFilePath)`：将关卡数据导出到文本文件。

#### 3.1.8 CardUtil 类

- **功能**：提供与卡片相关的工具方法。

- 方法


  - `static std::string getSuitPath(CardSuitType suit)`：根据花色获取花色图片的路径。
  - `static std::string getNumberPath(CardFaceType face, CardSuitType suit, bool isBig)`：根据数字、花色和尺寸获取数字图片的路径。
  - `static bool isFaceDiffOne(CardFaceType f1, CardFaceType f2)`：判断两张卡片的数字是否相差 1。


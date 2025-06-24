// Classes/views/CardView.cpp
#include "CardView.h"
#include "../utils/CardUtil.h"

using namespace cocos2d;

/**
 * 创建卡牌视图的静态工厂方法
 * @param model 卡牌数据模型
 * @param isBig 是否为大尺寸卡牌
 * @return 创建成功返回CardView指针，失败返回nullptr
 */
CardView* CardView::create(const CardModel& model, bool isBig) {
    auto view = new CardView();
    if (view && view->init(model, isBig)) {
        view->autorelease();  // 将对象添加到自动释放池，避免内存泄漏
        return view;
    }
    CC_SAFE_DELETE(view);  // 初始化失败时安全删除对象
    return nullptr;
}

/**
 * 初始化卡牌视图
 * @param model 卡牌数据模型
 * @param isBig 是否为大尺寸卡牌
 * @return 初始化成功返回true，失败返回false
 */
bool CardView::init(const CardModel& model, bool isBig) {
    if (!Node::init()) return false;  // 先调用基类初始化

    // 保存模型数据和尺寸配置
    _model = model;
    _isBig = isBig;

    // 根据模型数据更新视图显示
    updateDisplay();
    // 设置卡牌位置
    this->setPosition(_model.getPosition());
    return true;
}

/**
 * 设置卡牌数据模型，并更新视图显示
 * @param model 新的卡牌数据模型
 */
void CardView::setModel(const CardModel& model) {
    _model = model;         // 更新模型数据
    updateDisplay();        // 触发视图更新
}

/**
 * 根据模型数据更新卡牌显示内容
 * 会移除所有子节点并重新创建卡牌元素
 */
 // CardView.cpp
void CardView::updateDisplay() {
    removeAllChildren();    // 移除所有子节点

    // 创建卡牌背面精灵
    _back = Sprite::create("card_general.png");
    if (_back) {
        addChild(_back);                  // 添加到视图

        // 获取牌背精灵的大小
        Size backSize = _back->getContentSize();

        // 定义边距，确保数字和花色在卡牌内部
        float margin = 40;

        // 1. 创建并添加左上角花色图片
        std::string suitPath = CardUtil::getSuitPath(_model.getSuit());
        _suit = Sprite::create(suitPath);
        if (_suit) {
            _suit->setPosition(Vec2(backSize.width - 190, backSize.height - 260) );  // 设置在牌背左上角内部
            //_suit->setScale(0.5f);             // 缩放图片大小
            addChild(_suit);                   // 添加到视图
        }

        // 2. 创建并添加右上角数字图片
        std::string numberPath = CardUtil::getNumberPath(_model.getFace(), _model.getSuit(), false);
        _number = Sprite::create(numberPath);
        if (_number) {
            _number->setPosition(Vec2(-50, backSize.height - 260));  // 设置在牌背右上角内部
            //_number->setScale(0.5f);             // 缩放图片大小
            addChild(_number);                   // 添加到视图
        }

        // 3. 创建并添加中心大数字图片
        std::string bigNumberPath = CardUtil::getNumberPath(_model.getFace(), _model.getSuit(), true);
        _number = Sprite::create(bigNumberPath);
        if (_number) {
            _number->setPosition(Vec2(0,-30));  // 设置在牌背右上角内部
            //_number->setScale(0.5f);             // 缩放图片大小
            addChild(_number);                   // 添加到视图
        }
    }
}
/**
 * 执行卡牌移动动画
 * @param pos 目标位置坐标
 * @param duration 动画持续时间（秒）
 */
void CardView::moveTo(const Vec2& pos, float duration) {
    // 使用cocos2d-x的MoveTo动作执行平滑移动
    runAction(MoveTo::create(duration, pos));
}
// Classes/views/CardView.cpp
#include "CardView.h"
#include "../utils/CardUtil.h"

using namespace cocos2d;

/**
 * ����������ͼ�ľ�̬��������
 * @param model ��������ģ��
 * @param isBig �Ƿ�Ϊ��ߴ翨��
 * @return �����ɹ�����CardViewָ�룬ʧ�ܷ���nullptr
 */
CardView* CardView::create(const CardModel& model, bool isBig) {
    auto view = new CardView();
    if (view && view->init(model, isBig)) {
        view->autorelease();  // ��������ӵ��Զ��ͷųأ������ڴ�й©
        return view;
    }
    CC_SAFE_DELETE(view);  // ��ʼ��ʧ��ʱ��ȫɾ������
    return nullptr;
}

/**
 * ��ʼ��������ͼ
 * @param model ��������ģ��
 * @param isBig �Ƿ�Ϊ��ߴ翨��
 * @return ��ʼ���ɹ�����true��ʧ�ܷ���false
 */
bool CardView::init(const CardModel& model, bool isBig) {
    if (!Node::init()) return false;  // �ȵ��û����ʼ��

    // ����ģ�����ݺͳߴ�����
    _model = model;
    _isBig = isBig;

    // ����ģ�����ݸ�����ͼ��ʾ
    updateDisplay();
    // ���ÿ���λ��
    this->setPosition(_model.getPosition());
    return true;
}

/**
 * ���ÿ�������ģ�ͣ���������ͼ��ʾ
 * @param model �µĿ�������ģ��
 */
void CardView::setModel(const CardModel& model) {
    _model = model;         // ����ģ������
    updateDisplay();        // ������ͼ����
}

/**
 * ����ģ�����ݸ��¿�����ʾ����
 * ���Ƴ������ӽڵ㲢���´�������Ԫ��
 */
 // CardView.cpp
void CardView::updateDisplay() {
    removeAllChildren();    // �Ƴ������ӽڵ�

    // �������Ʊ��澫��
    _back = Sprite::create("card_general.png");
    if (_back) {
        addChild(_back);                  // ��ӵ���ͼ

        // ��ȡ�Ʊ�����Ĵ�С
        Size backSize = _back->getContentSize();

        // ����߾࣬ȷ�����ֺͻ�ɫ�ڿ����ڲ�
        float margin = 40;

        // 1. ������������Ͻǻ�ɫͼƬ
        std::string suitPath = CardUtil::getSuitPath(_model.getSuit());
        _suit = Sprite::create(suitPath);
        if (_suit) {
            _suit->setPosition(Vec2(backSize.width - 190, backSize.height - 260) );  // �������Ʊ����Ͻ��ڲ�
            //_suit->setScale(0.5f);             // ����ͼƬ��С
            addChild(_suit);                   // ��ӵ���ͼ
        }

        // 2. ������������Ͻ�����ͼƬ
        std::string numberPath = CardUtil::getNumberPath(_model.getFace(), _model.getSuit(), false);
        _number = Sprite::create(numberPath);
        if (_number) {
            _number->setPosition(Vec2(-50, backSize.height - 260));  // �������Ʊ����Ͻ��ڲ�
            //_number->setScale(0.5f);             // ����ͼƬ��С
            addChild(_number);                   // ��ӵ���ͼ
        }

        // 3. ������������Ĵ�����ͼƬ
        std::string bigNumberPath = CardUtil::getNumberPath(_model.getFace(), _model.getSuit(), true);
        _number = Sprite::create(bigNumberPath);
        if (_number) {
            _number->setPosition(Vec2(0,-30));  // �������Ʊ����Ͻ��ڲ�
            //_number->setScale(0.5f);             // ����ͼƬ��С
            addChild(_number);                   // ��ӵ���ͼ
        }
    }
}
/**
 * ִ�п����ƶ�����
 * @param pos Ŀ��λ������
 * @param duration ��������ʱ�䣨�룩
 */
void CardView::moveTo(const Vec2& pos, float duration) {
    // ʹ��cocos2d-x��MoveTo����ִ��ƽ���ƶ�
    runAction(MoveTo::create(duration, pos));
}
#include "MyLevelSelectLayer.hpp"

bool MyLevelSelectLayer::init(int page) {

    if (!LevelSelectLayer::init(page)) {
        return false;
    }

    auto infoMenu = this->getChildByID("info-menu");

    auto plainButtonSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
    plainButtonSprite->setScale(0.65f);
    plainButtonSprite->setLayout(AnchorLayout::create());
    plainButtonSprite->updateLayout();

    auto button = CCMenuItemSpriteExtra::create(plainButtonSprite, nullptr, this, menu_selector(MyLevelSelectLayer::onOpenReplayMenu));
    button->setID("replay-menu-button"_spr);
    button->setPosition({-30.f, 0.f});
    infoMenu->addChild(button);
    infoMenu->updateLayout();

    return true;
}

void MyLevelSelectLayer::onOpenReplayMenu(CCObject*) {

    auto runPopup = ReplayPopup::create();
    runPopup->setID("GDPP-popup"_spr);
    runPopup->setZOrder(999);
    this->addChild(runPopup);
}
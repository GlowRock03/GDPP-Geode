#include "MyLevelInfoLayer.hpp"

bool MyLevelInfoLayer::init(GJGameLevel* level, bool challenge) {

    if (!LevelInfoLayer::init(level, challenge)) {
        return false;
    }

    auto leftSideMenu = this->getChildByID("left-side-menu");

    auto plainButtonSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
    auto button = CCMenuItemSpriteExtra::create(plainButtonSprite, nullptr, this, menu_selector(MyLevelInfoLayer::onOpenReplayMenu));
    button->setID("replay-menu-button"_spr);
    leftSideMenu->addChild(button);
    leftSideMenu->updateLayout();

    return true;
}

void MyLevelInfoLayer::onOpenReplayMenu(CCObject*) {

    auto runPopup = ReplayPopup::create();
    runPopup->setID("GDPP-popup"_spr);
    runPopup->setZOrder(999);
    this->addChild(runPopup);
}
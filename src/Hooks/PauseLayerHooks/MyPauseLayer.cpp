#include "MyPauseLayer.hpp"

void MyPauseLayer::customSetup() {

    PauseLayer::customSetup();

    auto rightSideMenu = this->getChildByID("right-button-menu");

    auto plainButtonSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
    plainButtonSprite->setScale(0.65f);
    plainButtonSprite->setLayout(AnchorLayout::create());

    plainButtonSprite->updateLayout();

    auto button = CCMenuItemSpriteExtra::create(plainButtonSprite, nullptr, this, menu_selector(MyPauseLayer::onRunMenu));

    button->setID("gdpp-button"_spr);
    rightSideMenu->addChild(button);
    rightSideMenu->updateLayout();
}

void MyPauseLayer::onRunMenu(CCObject*) {

    Notification::create(
        "GDPP Activated",
        NotificationIcon::Success
    )->show();

    /*
    auto runPopup = ::create();
    runPopup->setID("GDPP-popup"_spr);
    runPopup->setZOrder(999);
    this->addChild(runPopup);
    */
}
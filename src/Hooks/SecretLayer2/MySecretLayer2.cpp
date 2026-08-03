#include "MySecretLayer2.hpp"

bool MySecretLayer2::init() {

    if (!SecretLayer2::init()) {
        return false;
    }

    auto menu = this->getChildByID("menu");

    auto plainButtonSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
    auto button = CCMenuItemSpriteExtra::create(plainButtonSprite, nullptr, this, menu_selector(MySecretLayer2::onOpenReplayMenu));
    button->setID("replay-menu-button"_spr);
    button->setPosition({500.f, -80.f});
    menu->addChild(button);
    menu->updateLayout();

    return true;
}

void MySecretLayer2::onOpenReplayMenu(CCObject*) {

    auto runPopup = ReplayPopup::create();
    runPopup->setID("GDPP-popup"_spr);
    runPopup->setZOrder(999);
    this->addChild(runPopup);
}
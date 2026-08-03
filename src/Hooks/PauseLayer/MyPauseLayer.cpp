#include "MyPauseLayer.hpp"

void MyPauseLayer::customSetup() {

    PauseLayer::customSetup();

    auto rightSideMenu = this->getChildByID("right-button-menu");

    auto plainButtonSprite = CCSprite::createWithSpriteFrameName("GJ_plainBtn_001.png");
    plainButtonSprite->setScale(0.65f);
    plainButtonSprite->setLayout(AnchorLayout::create());

    plainButtonSprite->updateLayout();

    auto button = CCMenuItemSpriteExtra::create(plainButtonSprite, nullptr, this, menu_selector(MyPauseLayer::onOpenStopReplayMenu));

    button->setID("stop-replay-button"_spr);
    rightSideMenu->addChild(button);
    rightSideMenu->updateLayout();
}

void MyPauseLayer::onOpenStopReplayMenu(CCObject*) {

    auto runPopup = StopReplayPopup::create();
    runPopup->setID("GDPP-popup"_spr);
    runPopup->setZOrder(999);
    this->addChild(runPopup);
}

void MyPauseLayer::onResume(CCObject* sender) {

    PauseLayer::onResume(sender);

    GDPPManager::get().getReplayManager().setHeldButtonRestore(true);
}

void MyPauseLayer::goEdit() {

    PauseLayer::goEdit();

    GDPPManager::get().getReplayManager().stopReplay();
}

void MyPauseLayer::onQuit(CCObject* sender) {

    PauseLayer::onQuit(sender);

    GDPPManager::get().getReplayManager().stopReplay();
}
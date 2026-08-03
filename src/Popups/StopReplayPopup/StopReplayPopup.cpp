#include "StopReplayPopup.hpp"

StopReplayPopup* StopReplayPopup::create() {

    auto popup = new StopReplayPopup;

    if (popup->init(0)) {

        popup->autorelease();
        return popup;
    }

    delete popup;
    return nullptr;
}

bool StopReplayPopup::init(int value) {

    if (!Popup::init(300.f, 240.f, "GJ_square04.png")) return false;

    auto mainContainer = CCNode::create();
    mainContainer->setLayout(AnchorLayout::create());
    mainContainer->setContentSize(m_buttonMenu->getContentSize());
    mainContainer->setAnchorPoint({0.5f, 0.5f});
    mainContainer->setPosition(this->getContentSize() / 2);
    mainContainer->setID("main-content-node");
    this->addChild(mainContainer);

    auto stopSprite = ButtonSprite::create("Stop Replay");
    m_stopButton = CCMenuItemSpriteExtra::create(stopSprite, this, menu_selector(StopReplayPopup::onStop));
    m_stopButton->setPosition({150, 20});

    m_buttonMenu->addChild(m_stopButton);

    mainContainer->updateLayout();

    return true;
}

void StopReplayPopup::onStop(CCObject*) {

    auto& replay = GDPPManager::get().getReplayManager();

    if (GDPPManager::get().getReplayManager().isReplayRunning() || GDPPManager::get().getReplayManager().isReplayQueued()) {

        GDPPManager::get().getReplayManager().stopReplay();
        
    } else {

        Notification::create("No Replay To Stop", NotificationIcon::Success)->show();
    }

    return;
}
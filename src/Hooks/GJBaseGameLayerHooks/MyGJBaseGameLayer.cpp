#include "MyGJBaseGameLayer.hpp"

void MyGJBaseGameLayer::processQueuedButtons(float dt, bool clearInputQueue) {

    GJBaseGameLayer::processQueuedButtons(dt, clearInputQueue);

    if (!PlayLayer::get())
        return;

    uint64_t frame = m_gameState.m_currentProgress / 2;

    GDPPManager::get().getReplayManager().update(frame);
}

void MyGJBaseGameLayer::handleButton(bool down, int button, bool isPlayer1) {
    
    if (GDPPManager::get().getReplayManager().isReplayRunning()) {

        if (!GDPPManager::get().getReplayManager().isInjectingInput()) 
            return;

        #ifdef GEODE_IS_MOBILE
            m_allowedButtons.clear();
        #endif

        log::info("GDPP Input -> Button {} Player {} {}", button, isPlayer1 ? 2 : 1, down ? "DOWN" : "UP");
    }

    GJBaseGameLayer::handleButton(down, button, isPlayer1);
}
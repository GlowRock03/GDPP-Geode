#include "MyGJBaseGameLayer.hpp"

void MyGJBaseGameLayer::processQueuedButtons(float dt, bool clearInputQueue) {

    GJBaseGameLayer::processQueuedButtons(dt, clearInputQueue);

    if (!PlayLayer::get())
        return;

    uint64_t frame = m_gameState.m_currentProgress / 2;

    //log::info("Frame={} (Real) Frame={} Time={}", m_gameState.m_currentProgress, frame, m_gameState.m_levelTime);

    GDPPManager::get().getReplayManager().update(frame);
}
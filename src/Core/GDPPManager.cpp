#include "GDPPManager.hpp"

using namespace geode::prelude;

GDPPManager& GDPPManager::get() {

    static GDPPManager instance;
    return instance;
}

ReplayManager& GDPPManager::getReplayManager() {

    return m_replayManager;
}

void GDPPManager::startReplay() {

    if (m_replayRunning)
        return;

    auto& replayManager = getReplayManager();

    if (!replayManager.loadReplay()) {

        FLAlertLayer::create("Replay Error", "Failed to load replay file.", "OK")->show();
        return;
    }

    replayManager.startPlayback();
    m_replayRunning = true;

    log::info("GDPP replay started");
}

bool GDPPManager::isReplayRunning() const {
    
    return m_recording;
}
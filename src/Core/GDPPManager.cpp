#include "GDPPManager.hpp"

using namespace geode::prelude;

GDPPManager& GDPPManager::get() {

    static GDPPManager instance;
    return instance;
}

ReplayManager& GDPPManager::getReplayManager() {

    return m_replayManager;
}

void GDPPManager::startRecording() {

    if (m_recording)
        return;

    m_recording = true;

    log::info("GDPP recording started.");
}

bool GDPPManager::isRecording() const {
    
    return m_recording;
}
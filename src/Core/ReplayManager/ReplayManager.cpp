#include "ReplayManager.hpp"

void ReplayManager::setReplayFile(std::filesystem::path path) {

    m_path = std::move(path);
}

bool ReplayManager::hasReplay() const {

    return !m_path.empty();
}

bool ReplayManager::loadReplay() {

    if (!hasReplay()) {

        log::error("No replay selected");
        return false;
    }

    m_loaded = m_replay.load(m_path);

    if (m_loaded) {

        m_replay.printDebugInfo();
    }
    return m_loaded;
}

void ReplayManager::startPlayback() {

    if (!m_loaded) {

        log::error("Cannot start playback. Replay not loaded.");
        return;
    }

    m_playing = true;
    m_currentFrame = 0;

    log::info("Playback initialized");
}

void ReplayManager::update(float dt) {

    if (!m_playing)
        return;

    /*
        Later:

        - increment frame
        - check inputs
        - inject player controls

    */
    m_currentFrame++;
}
#include "ReplayManager.hpp"

void ReplayManager::setReplayFile(std::filesystem::path path) {

    m_path = std::move(path);
}

bool ReplayManager::hasReplay() const {

    return !m_path.empty();
}

bool ReplayManager::loadReplay() {

    if (!hasReplay())
        return false;


    if (!m_replay.load(m_path))
        return false;


    //m_replay.printDebugInfo();
    m_replay.printDebugInfo();

    m_loaded = true;

    return true;
}

void ReplayManager::startPlayback() {

    if (!m_loaded) {

        log::error("Cannot start playback. Replay not loaded.");
        return;
    }

    m_replay.reset();

    m_playing = true;
    m_currentFrame = 0;

    log::info("Playback initialized");
}

void ReplayManager::update(uint64_t frame) {

    if (!m_playing)
        return;

    auto inputs = m_replay.getInputsForFrame(frame);

    for (auto const& input : inputs) {

        log::info("Replay frame {} -> Button {} {} ; Player {}", frame, input.button, input.down ? "DOWN" : "UP", input.player2);
    }
}
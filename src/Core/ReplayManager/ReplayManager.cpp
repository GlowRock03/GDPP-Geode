#include "ReplayManager.hpp"

ReplayManager& ReplayManager::get() {

    static ReplayManager instance;
    return instance;
}

void ReplayManager::setReplayFile(std::filesystem::path path) {

    m_path = std::move(path);
}

bool ReplayManager::hasReplay() const {

    return !m_path.empty();
}

const std::filesystem::path& ReplayManager::replayPath() const {
    
    return m_path;
}
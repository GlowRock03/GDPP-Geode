#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "Replay.hpp"

class ReplayManager {

enum ReplayState {
    QUEUED,
    REPLAYING,
    STOPPED
}; 
    
public:

    void setReplayFile(std::filesystem::path path);
    bool hasReplay() const;
    bool loadReplay();

    void startPlayback();
    bool isInjectingInput() const;
    void update(uint64_t frame);

    void queueReplay();
    void startReplay();
    void stopReplay();

    bool isReplayQueued();
    bool isReplayRunning();
    bool isReplayStopped();

private:

    std::filesystem::path m_path;
    Replay m_replay;
    bool m_loaded = false;

    bool m_injectingInput = false;
    uint64_t m_currentFrame = 0;

    enum ReplayState m_replayState = STOPPED;
};
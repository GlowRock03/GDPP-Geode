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

    bool getHeldButtonRestore();
    void setHeldButtonRestore(bool set);
    void restoreHeldButtons(uint64_t frame);

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

    struct HeldState {
        bool held = false;
        uint8_t button = 1;
    };
    HeldState m_player1State;
    HeldState m_player2State;

    bool m_injectingInput = false;
    bool m_restoreHeldButtons = false;

    enum ReplayState m_replayState = STOPPED;
};
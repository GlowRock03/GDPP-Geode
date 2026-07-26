#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include "Replay.hpp"

class ReplayManager {

public:

    void setReplayFile(std::filesystem::path path);
    bool hasReplay() const;

    bool loadReplay();
    void startPlayback();
    void update(uint64_t frame);

    std::vector<ReplayInput> getInputsForFrame(uint64_t frame);

private:

    std::filesystem::path m_path;

    Replay m_replay;
    bool m_loaded = false;
    bool m_playing = false;
    uint64_t m_currentFrame = 0;
};
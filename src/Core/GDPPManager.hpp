#pragma once

#include <Geode/Geode.hpp>

#include "ReplayManager/ReplayManager.hpp"

class GDPPManager {
    
public:

    static GDPPManager& get();
    ReplayManager& getReplayManager();

    void startReplay();
    bool isReplayRunning() const;

private:

    GDPPManager() = default;

    bool m_recording = false;
    bool m_replayRunning = false;
    ReplayManager m_replayManager;
};
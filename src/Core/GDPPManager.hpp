#pragma once

#include <Geode/Geode.hpp>

#include "ReplayManager/ReplayManager.hpp"

class GDPPManager {
    
public:

    static GDPPManager& get();
    ReplayManager& getReplayManager();

    void startRecording();
    bool isRecording() const;

private:

    GDPPManager() = default;

    bool m_recording = false;
    ReplayManager m_replayManager;
};
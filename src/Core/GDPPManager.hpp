#pragma once

#include <Geode/Geode.hpp>

#include "ReplayManager/ReplayManager.hpp"

class GDPPManager {

public:
    static GDPPManager& get();
    ReplayManager& getReplayManager();

private:
    GDPPManager() = default;
    ReplayManager m_replayManager;
};
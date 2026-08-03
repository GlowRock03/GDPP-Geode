#pragma once

#include <Geode/Geode.hpp>

#include "ReplayManager/ReplayManager.hpp"
#include "LevelManager/LevelManager.hpp"

class GDPPManager {

public:
    static GDPPManager& get();
    ReplayManager& getReplayManager();
    LevelManager& getLevelManager();

private:
    GDPPManager() = default;
    ReplayManager m_replayManager;
    LevelManager m_levelManager;
};
#include "GDPPManager.hpp"

using namespace geode::prelude;

GDPPManager& GDPPManager::get() {

    static GDPPManager instance;
    return instance;
}

ReplayManager& GDPPManager::getReplayManager() {

    return m_replayManager;
}
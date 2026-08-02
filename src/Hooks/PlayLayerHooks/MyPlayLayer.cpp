#include "MyPlayLayer.hpp"

//change to another hook
void MyPlayLayer::resetLevel() {

    PlayLayer::resetLevel();

    if (GDPPManager::get().getReplayManager().isReplayQueued()) {

        GDPPManager::get().getReplayManager().startReplay();
    }
}

void MyPlayLayer::levelComplete() {

    PlayLayer::levelComplete();

    GDPPManager::get().getReplayManager().stopReplay();
}
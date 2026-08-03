#include "MyPlayerObject.hpp"

void MyPlayerObject::releaseAllButtons() {

    log::info("called release all buttons");

    if (!GDPPManager::get().getReplayManager().isReplayRunning()) {

        log::info("releasing all buttons");
        PlayerObject::releaseAllButtons();
    }
}
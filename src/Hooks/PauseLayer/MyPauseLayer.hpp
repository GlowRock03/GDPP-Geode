#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

#include "../../Popups/StopReplayPopup/StopReplayPopup.hpp"
#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:

    void customSetup();
    void onOpenStopReplayMenu(CCObject*);
    
    void onResume(CCObject*);
    void goEdit();
    void onQuit(CCObject*);
};
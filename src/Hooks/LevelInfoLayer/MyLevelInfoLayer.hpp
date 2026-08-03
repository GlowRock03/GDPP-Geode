#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

#include "../../Popups/ReplayPopup/ReplayPopup.hpp"
#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MyLevelInfoLayer, LevelInfoLayer) {
public:

    bool init(GJGameLevel* level, bool challenge);
    void onOpenReplayMenu(CCObject*);
};
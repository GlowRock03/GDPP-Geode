#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSelectLayer.hpp>

#include "../../Popups/ReplayPopup/ReplayPopup.hpp"
#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MyLevelSelectLayer, LevelSelectLayer) {
public:

    bool init(int page);
    void onOpenReplayMenu(CCObject*);
};
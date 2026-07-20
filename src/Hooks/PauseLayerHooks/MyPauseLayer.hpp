#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

#include "../../Popups/GDPPPopup/GDPPPopup.hpp"

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:

    void customSetup();
    void onOpenGDPPMenu(CCObject*);
};
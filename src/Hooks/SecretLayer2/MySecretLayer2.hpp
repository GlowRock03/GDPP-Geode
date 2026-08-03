#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/SecretLayer2.hpp>

#include "../../Popups/ReplayPopup/ReplayPopup.hpp"
#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MySecretLayer2, SecretLayer2) {
public:

    bool init();
    void onOpenReplayMenu(CCObject*);
};
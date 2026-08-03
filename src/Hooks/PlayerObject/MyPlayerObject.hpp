#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayerObject.hpp>

#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MyPlayerObject, PlayerObject) {
public:

    void releaseAllButtons();
};
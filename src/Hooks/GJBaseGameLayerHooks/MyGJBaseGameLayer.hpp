#pragma once

#include "../../Core/GDPPManager.hpp"

#include <Geode/Geode.hpp>
#include <Geode/modify/GJBaseGameLayer.hpp>

using namespace geode::prelude;

class $modify(MyGJBaseGameLayer, GJBaseGameLayer) {

public:

    void processQueuedButtons(float dt, bool clearInputQueue);
};
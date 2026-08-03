#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class $modify(MyPlayLayer, PlayLayer) {
public:

    void resetLevel();
    void levelComplete();

    void addObject(GameObject* object);
};
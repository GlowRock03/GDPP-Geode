#pragma once

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:

    void customSetup();
    void onRunMenu(CCObject*);
};
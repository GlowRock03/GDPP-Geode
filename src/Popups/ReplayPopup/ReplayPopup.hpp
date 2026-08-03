#pragma once

#include <Geode/Geode.hpp>

#include <Geode/binding/LevelSelectLayer.hpp>
#include <Geode/binding/LevelInfoLayer.hpp>
#include <Geode/binding/SecretLayer2.hpp>

#include <Geode/utils/file.hpp>
#include <Geode/utils/async.hpp>

#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class ReplayPopup : public Popup {

public: 

    static ReplayPopup* create();

protected:

    bool init(int value);

    CCLabelBMFont* m_replayLabel = nullptr;
    CCMenuItemSpriteExtra* m_startButton = nullptr;
    CCMenuItemSpriteExtra* m_stopButton = nullptr;

    void onSelectReplay(CCObject*);
    void onReplaySelected(std::filesystem::path path);
    void onStart(CCObject*);
    void onStop(CCObject*);
};
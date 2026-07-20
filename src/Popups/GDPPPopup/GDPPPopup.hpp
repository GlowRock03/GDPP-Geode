#pragma once

#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/utils/async.hpp>

#include "../../Core/GDPPManager.hpp"

using namespace geode::prelude;

class GDPPPopup : public Popup {

public: 

    static GDPPPopup* create();

protected:

    bool init(int value);

    CCLabelBMFont* m_replayLabel = nullptr;
    CCMenuItemSpriteExtra* m_startButton = nullptr;

    void onSelectReplay(CCObject*);
    void onReplaySelected(std::filesystem::path path);
    void onStart(CCObject*);
};
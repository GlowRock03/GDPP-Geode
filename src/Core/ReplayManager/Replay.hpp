#pragma once

#include <filesystem>
#include <vector>
#include <string>

#include <Geode/Geode.hpp>
#include <gdr/gdr.hpp>

#include "GDRReplay.hpp"

using namespace geode::prelude;

struct ReplayInput {

    uint64_t frame;
    uint8_t button;
    bool down;
};

class Replay {

public:

    bool load(std::filesystem::path path);
    void printDebugInfo() const;

private:

    std::string m_author;
    std::string m_description;
    std::string m_botName;
    int m_botVersion = 0;
    uint32_t m_levelID = 0;
    std::string m_levelName;
    int m_gameVersion = 0;
    double m_framerate = 240.0;
    uint64_t m_duration = 0;
    bool m_platformer = false;
    bool m_ldm = false;
    std::vector<ReplayInput> m_inputs;
};
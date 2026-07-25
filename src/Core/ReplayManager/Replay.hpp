#pragma once

#include <filesystem>
#include <vector>
#include <string>

#include <Geode/Geode.hpp>

using namespace geode::prelude;

struct ReplayInput {

    uint64_t frame;
    uint8_t button;
    bool down;
};

class Replay {

public:

    bool load(std::filesystem::path path);
    const std::vector<ReplayInput>& getInputs() const;
    void printDebugInfo() const;

private:

    std::string m_author;
    std::string m_description;
    uint64_t m_duration = 0;
    double m_framerate = 240.0;
    std::vector<ReplayInput> m_inputs;
};
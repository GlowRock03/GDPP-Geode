#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ReplayManager {

public:

    static ReplayManager& get();

    void setReplayFile(std::filesystem::path path);
    bool hasReplay() const;

    const std::filesystem::path& replayPath() const;

private:

    std::filesystem::path m_path;
};
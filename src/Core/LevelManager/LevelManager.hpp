#pragma once

#include "GDPPObject.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class LevelManager {

public:

    void registerObject(GameObject* object);

private:

    std::vector<GDPPObject> m_objects;

};
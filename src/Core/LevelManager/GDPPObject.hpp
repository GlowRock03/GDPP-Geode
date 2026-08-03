#pragma once

#include <Geode/binding/GameObject.hpp>

#include <cstdint>

using namespace geode::prelude;

class GDPPObject {

public:

    GDPPObject(GameObject* gameObject);

    uint64_t getID() const;
    GameObject* getGameObject() const;

private:

    inline static uint64_t s_nextID = 0;

    uint64_t m_id;
    GameObject* m_gameObject;
};
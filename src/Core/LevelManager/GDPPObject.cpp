#include "GDPPObject.hpp"

GDPPObject::GDPPObject(GameObject* gameObject) {

    m_id = s_nextID++;

    m_gameObject = gameObject;
}

uint64_t GDPPObject::getID() const {

    return m_id;
}

GameObject* GDPPObject::getGameObject() const {

    return m_gameObject;
}
#include "LevelManager.hpp"

void LevelManager::registerObject(GameObject* object) {

    GDPPObject gdppObject(object);
    m_objects.push_back(gdppObject);
    //log::info("Registered GDPP Object ID={}", gdppObject.getID());
}
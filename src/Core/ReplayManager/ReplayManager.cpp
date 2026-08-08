#include "ReplayManager.hpp"

void ReplayManager::setReplayFile(std::filesystem::path path) {

    m_path = std::move(path);
}

bool ReplayManager::hasReplay() const {

    return !m_path.empty();
}

bool ReplayManager::loadReplay() {

    if (!hasReplay())
        return false;


    if (!m_replay.load(m_path))
        return false;

    m_replay.printDebugInfo();

    m_loaded = true;

    return true;
}


void ReplayManager::startPlayback() {

    if (!m_loaded) {

        log::error("Cannot start playback. Replay not loaded.");
        return;
    }

    m_replay.reset();

    startReplay();

    log::info("Playback initialized");
    Notification::create("Replay Started", NotificationIcon::Success)->show();
}

bool ReplayManager::isInjectingInput() const {

    return m_injectingInput;
}

//asumption: no platformer support, can be added later but expands the scope of the project
void ReplayManager::update(uint64_t frame) {

    if (!isReplayRunning())
        return;

    auto playLayer = PlayLayer::get();

    if (!playLayer)
        return;

    auto inputs = m_replay.getInputsForFrame(frame);

    for (auto const& input : inputs) {

        log::info("Replay frame {} -> Button {} {} ; Player {}", frame, input.button, input.down ? "DOWN" : "UP", input.player2);

        if (input.player2) {
            m_player2State.held = input.down;
            m_player2State.button = input.button;
        }
        else {
            m_player1State.held = input.down;
            m_player1State.button = input.button;
        }
        
        m_injectingInput = true;
        playLayer->handleButton(input.down, input.button, !input.player2);
        m_injectingInput = false;
    }
}

bool ReplayManager::getHeldButtonRestore() {

    return m_restoreHeldButtons;
}

void ReplayManager::setHeldButtonRestore(bool set) {

    m_restoreHeldButtons = set;
}

void ReplayManager::restoreHeldButtons(uint64_t frame) {

    auto playLayer = PlayLayer::get();

    if (!playLayer)
        return;

    if (m_player1State.held) {

        m_injectingInput = true;
        playLayer->queueButton(m_player1State.button, true, true, frame);
        m_injectingInput = false;
    }

    if (m_player2State.held) {

        m_injectingInput = true;
        playLayer->queueButton(m_player2State.button, true, true, frame);
        m_injectingInput = false;
    }

    m_restoreHeldButtons = false;
}


void ReplayManager::queueReplay() {

    if (m_replayState == ReplayManager::ReplayState::REPLAYING)
        return;

    m_replayState = ReplayManager::ReplayState::QUEUED;
}

void ReplayManager::startReplay() {

    if (m_replayState == ReplayManager::ReplayState::REPLAYING)
        return;

    if (!loadReplay()) {

        FLAlertLayer::create("Replay Error", "Failed to load replay file.", "OK")->show();
        return;
    }

    m_replay.reset();
    m_player1State.held = false;
    m_player2State.held = false;
    m_restoreHeldButtons = false;

    m_replayState = ReplayManager::ReplayState::REPLAYING;

    Notification::create("Replay Started", NotificationIcon::Success)->show();
}

void ReplayManager::stopReplay() {

    if (m_replayState != ReplayManager::ReplayState::REPLAYING)
        return;

    m_path.clear();
    m_replay.reset();

    m_player1State.held = false;
    m_player2State.held = false;

    m_restoreHeldButtons = false;
    m_injectingInput = false;

    

    m_replayState = ReplayManager::ReplayState::STOPPED;

    Notification::create("Replay Stopped", NotificationIcon::Success)->show();
}


bool ReplayManager::isReplayQueued() {
    
    return m_replayState == ReplayManager::ReplayState::QUEUED;
}

bool ReplayManager::isReplayRunning() {
    
    return m_replayState == ReplayManager::ReplayState::REPLAYING;
}

bool ReplayManager::isReplayStopped() {
    
    return m_replayState == ReplayManager::ReplayState::STOPPED;
}
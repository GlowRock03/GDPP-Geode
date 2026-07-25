#include "Replay.hpp"

bool Replay::load(std::filesystem::path path) {

    log::info("Loading replay: {}", path.string());

    /*
        TODO:

        Read .gdr2

        Parse:

        Header
        Metadata
        Death frames
        Inputs

    */

    return true;
}


const std::vector<ReplayInput>& Replay::getInputs() const {

    return m_inputs;
}

void Replay::printDebugInfo() const {

    log::info("Replay Metadata:");

    log::info("Author: {}", m_author);

    log::info("Description: {}", m_description);

    log::info("Duration: {} frames", m_duration);

    log::info("Framerate: {}", m_framerate);

    log::info("Input count: {}", m_inputs.size());

    size_t count = 0;

    for (auto& input : m_inputs) {

        log::info("Input {}: Frame={} Button={} Down={}", count, input.frame, input.button, input.down);
        count++;
        
        if (count >= 10)
            break;
    }
}
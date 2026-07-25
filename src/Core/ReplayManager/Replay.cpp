#include "Replay.hpp"

bool Replay::load(std::filesystem::path path)
{

    log::info("Loading replay: {}", path.string());


    auto result = GDPPGDRReplay::importData(path);


    if (result.isErr())
    {
        log::error(
            "Failed to load replay: {}",
            result.unwrapErr()
        );

        return false;
    }


    auto replay = result.unwrap();


    //
    // Metadata
    //

    m_author = replay.author;

    m_description = replay.description;

    m_botName = replay.botInfo.name;
    m_botVersion = replay.botInfo.version;


    m_levelID = replay.levelInfo.id;
    m_levelName = replay.levelInfo.name;


    m_gameVersion = replay.gameVersion;

    m_framerate = replay.framerate;

    m_duration = replay.duration;


    m_platformer = replay.platformer;

    m_ldm = replay.ldm;


    //
    // Inputs
    //

    m_inputs.clear();

    m_inputs.reserve(replay.inputs.size());


    for (auto const& input : replay.inputs)
    {
        ReplayInput converted;

        converted.frame = input.frame;
        converted.button = input.button;
        converted.down = input.down;


        m_inputs.push_back(converted);
    }


    log::info(
        "Replay loaded successfully. Inputs: {}",
        m_inputs.size()
    );


    return true;
}

void Replay::printDebugInfo() const
{

    log::info("Replay Metadata:");
    
    log::info("Author: {}", m_author);

    log::info("Bot: {} v{}", 
        m_botName,
        m_botVersion
    );


    log::info(
        "Level: {} ({})",
        m_levelName,
        m_levelID
    );


    log::info(
        "Duration: {} frames",
        m_duration
    );


    log::info(
        "Framerate: {}",
        m_framerate
    );


    log::info(
        "Input count: {}",
        m_inputs.size()
    );


    for (size_t i = 0; i < std::min<size_t>(10, m_inputs.size()); i++)
    {
        auto& input = m_inputs[i];

        log::info(
            "Input {}: Frame={} Button={} Down={}",
            i,
            input.frame,
            input.button,
            input.down
        );
    }
}
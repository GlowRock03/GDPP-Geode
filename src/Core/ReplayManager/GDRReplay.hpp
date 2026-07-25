#pragma once

#include <gdr/gdr.hpp>


struct GDPPGDRReplay : gdr::Replay<GDPPGDRReplay, gdr::Input<>> {

    GDPPGDRReplay() : Replay("GDPP", 1) {}
};
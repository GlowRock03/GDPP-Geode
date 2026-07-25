#include "GDPPPopup.hpp"

GDPPPopup* GDPPPopup::create() {

    auto popup = new GDPPPopup;

    if (popup->init(0)) {

        popup->autorelease();
        return popup;
    }

    delete popup;
    return nullptr;
}

bool GDPPPopup::init(int value) {

    if (!Popup::init(300.f, 240.f, "GJ_square04.png")) return false;

    auto mainContainer = CCNode::create();
    mainContainer->setLayout(AnchorLayout::create());
    mainContainer->setContentSize(m_buttonMenu->getContentSize());
    mainContainer->setAnchorPoint({0.5f, 0.5f});
    mainContainer->setPosition(this->getContentSize() / 2);
    mainContainer->setID("main-content-node");
    this->addChild(mainContainer);

    m_replayLabel = CCLabelBMFont::create("No replay selected", "goldFont.fnt");
    m_replayLabel->setScale(0.5f);
    m_replayLabel->setPosition({150, 170});
    mainContainer->addChild(m_replayLabel);

    auto selectSprite = ButtonSprite::create("Select Replay");
    auto selectButton = CCMenuItemSpriteExtra::create(selectSprite, this, menu_selector(GDPPPopup::onSelectReplay));
    selectButton->setPosition({150, 120});

    auto startSprite = ButtonSprite::create("Start");
    m_startButton = CCMenuItemSpriteExtra::create(startSprite, this, menu_selector(GDPPPopup::onStart));
    m_startButton->setPosition({150, 70});
    m_startButton->setEnabled(false);

    m_buttonMenu->addChild(selectButton);
    m_buttonMenu->addChild(m_startButton);

    mainContainer->updateLayout();

    return true;
}

void GDPPPopup::onSelectReplay(CCObject*) {

    file::FilePickOptions::Filter filter = {
        .description = "Geometry Dash Replay",
        .files = {
            "*.gdr2"
        }
    };


    file::FilePickOptions options = {
        std::nullopt,
        {filter}
    };

    async::spawn(
        file::pick(file::PickMode::OpenFile, options),
        [this](Result<std::optional<std::filesystem::path>> result) {

            if (result.isOk()) {
                auto opt = result.unwrap();
                if (opt) {
                    auto path = opt.value();
                    onReplaySelected(path);
                } else {
                    // User cancelled the dialog
                }
            }
        }
    );
}

void GDPPPopup::onReplaySelected(std::filesystem::path path) {

    auto extension = path.extension().string();

    std::ranges::transform(extension, extension.begin(),
        [](unsigned char c) {
            return std::tolower(c);
        }
    );

    if (extension != ".gdr2") {

        FLAlertLayer::create("Invalid File", "Please select a .gdr2 replay file.", "OK" )->show();
        return;
    }

    GDPPManager::get().getReplayManager().setReplayFile(path);
    m_replayLabel->setString(path.filename().string().c_str());
    m_startButton->setEnabled(true);

    geode::log::info("Selected replay: {}", path.string());
}

void GDPPPopup::onStart(CCObject*) {

    auto& replay = GDPPManager::get().getReplayManager();

    if (!replay.hasReplay()) {

        FLAlertLayer::create("Error", "No replay selected", "OK")->show();
        return;
    }

    GDPPManager::get().startReplay();
}
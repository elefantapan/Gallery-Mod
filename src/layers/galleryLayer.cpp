#include <Geode/geode.hpp>
#include "galleryLayer.h"

using namespace geode::prelude;

GalleryLayer* GalleryLayer::create() {
    GalleryLayer* layer = new GalleryLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

void GalleryLayer::OnMyClick(CCObject* target) {
    ++clicked;
    FLAlertLayer::create(
        "Geode",
        "You have clicked " + std::to_string(clicked) + " times",
        "OK"
    )->show();
}

bool GalleryLayer::init() {
    clicked = 0; // Initialize the 'clicked' variable
    if (!CCLayer::init()) return false;
    
    auto menu = CCMenu::create();
    menu->setContentSize(CCSize(964, 49)); // Corrected syntax for setting content size
    menu->setPosition(CCPoint(79, 298)); // Corrected syntax for setting position
    
    auto spr = CircleButtonSprite::createWithSprite("logo.png"_spr);
    auto btn = CCMenuItemSpriteExtra::create(
        spr, this, menu_selector(GalleryLayer::OnMyClick)
    );
    menu->addChild(btn);
    
    addChild(menu); // Add the menu to the layer
    
    return true;
}

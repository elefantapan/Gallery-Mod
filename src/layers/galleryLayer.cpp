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

bool GalleryLayer::init() {
    if (!CCLayer::init()) return false;
    auto menu = CCMenu::create();
    auto spr = CircleButtonSprite::createWithSprite("logo.png"_spr);
    auto btn = CCMenuItemSpriteExtra::create(
        spr, this, nullptr
    );
    menu->addChild(btn);
    this->addChild(menu);
    return true;
}
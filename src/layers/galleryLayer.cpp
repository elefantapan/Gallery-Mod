#include <Geode/Geode.hpp>
#include "galleryLayer.h"

using namespace geode::prelude;

GalleryLayer*  GalleryLayer::create() {
    GalleryLayer* layer = new GalleryLayer();
    if (layer && layer->init()) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

int clicked = 0;
void OnMyClick(CCObject* target) {
    ++clicked;
    FLAlertLayer::create(
        "Geode",
        "You have clicked " + std::to_string(clicked) + " times",
        "OK"
    )->show();
}

bool GalleryLayer::init() {

    if (!CCLayer::init()) return false;
    auto menu = CCMenu::create();
    menu->setContentSize(CCSize {CCPoint {964, 49}});
    menu->setPosition(CCPoint {79, 298});
    auto spr = CircleButtonSprite::createWithSprite("logo.png"_spr);
    auto btn = CCMenuItemSpriteExtra::create(
        spr, this, OnMyClick
    );
    menu->addChild(btn);
    return true;
}

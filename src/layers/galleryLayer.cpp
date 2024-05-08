#include <Geode/Geode.hpp>
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

void GalleryLayer::OnMyClick(CCObject* target) {
    auto director = CCDirector::sharedDirector();
    auto winSize = director->getWinSize();

    auto scene = director->getRunningScene();
    GJGarageLayer* garage;
    #ifdef GEODE_IS_ANDROID64 //lol
    auto scene2 = GJGarageLayer::scene();
    garage = getChildOfType<GJGarageLayer>(scene2, 0);
    #else
    garage = GJGarageLayer::node();
    #endif

    scene->addChild(garage, -1);

    auto moveTo = CCMoveTo::create(0.3f, ccp(0, winSize.height));
    auto easeIn = CCEaseIn::create(moveTo, 2.0f);
    auto callFunc = CCCallFunc::create(this, callfunc_selector(SogLayer::onExit));
    auto callFunc2 = CCCallFunc::create(this, callfunc_selector(SogLayer::removeFromParent));

    auto ccSeq = CCSequence::create(easeIn, callFunc, callFunc2, 0);
    this->runAction(ccSeq);
    GameManager::sharedState()->fadeInMenuMusic();
}

bool GalleryLayer::init() {
    int clicked = 0; // Initialize the 'clicked' variable
    if (!CCLayer::init()) return false;
    
    auto menu = CCMenu::create();
    menu->setContentSize(CCSize(964, 49)); // Corrected syntax for setting content size
    menu->setPosition(CCPoint(79, 298)); // Corrected syntax for setting position
    
    auto spr = CircleButtonSprite::createWithSprite("logo.png"_spr);
    auto btn = CCMenuItemSpriteExtra::create(
        spr, this, menu_selector(GalleryLayer::OnMyClick)
    );
    auto backBtn = CCMenuItemSpriteExtra::create(
        spr, this, menu_selector(GalleryLayer::OnMyClick2)
    );
    menu->addChild(btn);
    menu->addChild(backBtn);
    
    addChild(menu); // Add the menu to the layer
    
    return true;
}

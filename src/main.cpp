#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>
#include "layers/galleryLayer.h"

using namespace cocos2d;
using namespace geode::prelude;

CCPoint AnchorPointZero = {
    0,
    0
};

class $modify(MyMenuLayer, MenuLayer) {
    void onMyButton(CCObject* sender) {
        auto scene = CCScene::create();
        auto layer = GalleryLayer::create();
        scene->addChild(layer);
        CCDirector::sharedDirector()->pushScene(scene);
    }
    // Signature is `bool MenuLayer::init()`
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }
        

        // assuming you have a onMyButton function
        //set the button sprite
        auto spr = CCSprite::create("logo.png"_spr);
        
        //create the menu button and set the position and anchor
        auto btn = CCMenuItemSpriteExtra::create(
            spr, this, menu_selector(MyMenuLayer::onMyButton)
        );
        auto menu = this->getChildByID("right-side-menu"); // Define the right side of the menu
        menu->addChild(btn);
        menu->updateLayout();

        return true;
    }
};

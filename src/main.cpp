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

class $modify(MenuLayer) {
    FLAlertLayer::create(
    "Title",    // title
    "Hi mom!",  // content
    "OK"        // button
    )->show();
};

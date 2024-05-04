#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
private:
    bool init() override;
};
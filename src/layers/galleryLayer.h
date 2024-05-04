#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
    void onClose(CCObject*);
private:
    bool init() override;
};
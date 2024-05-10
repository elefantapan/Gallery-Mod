#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
    void onClose(CCObject*);
private:
    int clicked = 0;
    bool init() override;
};

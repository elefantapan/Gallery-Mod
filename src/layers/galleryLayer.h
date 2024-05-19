#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
    void OnMyClick(CCObject* target); // Declare OnMyClick function
private:
    int clicked = 0;
    bool init() override;
};

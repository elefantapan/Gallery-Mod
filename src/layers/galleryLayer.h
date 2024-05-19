#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
    void OnMyClick2(CCObject* target); // Declare OnMyClick2 function
    void OnMyClick(CCObject* target); // Declare OnMyClick function
private:
    int clicked = 0;
    bool init() override;
};

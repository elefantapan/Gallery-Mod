#pragma once

class GalleryLayer : public cocos2d::CCLayer {
public:
    static GalleryLayer* create();
    void OnMyClkick2(CCObject* target); 
    void OnMyClick(CCObject* target); 
    void onClose(CCObject*);
private:
    int clicked = 0;
    bool init() override;
};


#ifndef __QRCODE_H__
#define __QRCODE_H__

#include "2d/CCSprite.h"
#include "ui/UIWidget.h"
#include "ui/GUIExport.h"

NS_CC_BEGIN
namespace ui {
    class CC_DLL QrCode : public Widget {
    public:
        static QrCode* create(const std::string& code);
        static QrCode* create();
        virtual bool LoadCodeByString(const std::string& code);
        virtual void SetOriginSize();
    protected:
        void initRenderer() override;
        void onSizeChanged() override;

        void adaptRenderers() override;

        void CodeTextureScaleChangedWithSize();
        Widget* createCloneInstance() override;
        void copySpecialProperties(Widget* model) override;

        virtual bool Init(const std::string& code);
        
    protected:
        static constexpr int CodeRendererZOrder = -1;
        cocos2d::Sprite* codeRenderer = nullptr;
        bool codeRendererAdaptDirty = false;
        int originSize = 0;
    };
}
NS_CC_END

#endif
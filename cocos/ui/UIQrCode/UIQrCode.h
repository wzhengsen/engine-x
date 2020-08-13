
#ifndef __QRCODE_H__
#define __QRCODE_H__

#include "ui/UIWidget.h"

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
        Sprite* codeRenderer = nullptr;
        bool codeRendererAdaptDirty = false;
        int originSize = 0;
    };
}
NS_CC_END

#endif
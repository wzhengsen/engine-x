#include "ui/UIQrCode/UIQRCode.h"
#include "QrEncode/qrencode.h"
#include "QrEncode/qrspec.h"

using namespace cocos2d::ui;

QrCode* QrCode::create(const std::string& code) {
    QrCode* qr = new (std::nothrow) QrCode();
    if (qr && qr->Init(code))
    {
        qr->autorelease();
        return qr;
    }
    CC_SAFE_DELETE(qr);
    return nullptr;
}

QrCode* QrCode::create() {
    QrCode* qr = new (std::nothrow) QrCode();
    if (qr && qr->init()) {
        qr->autorelease();
        return qr;
    }
    CC_SAFE_DELETE(qr);
    return nullptr;
}

Widget* QrCode::createCloneInstance() {
    return QrCode::create();
}

void QrCode::copySpecialProperties(Widget* widget) {
    QrCode* qr = dynamic_cast<QrCode*>(widget);
    if (qr) {
        const auto imageSprite = qr->codeRenderer;
        if (imageSprite) {
            codeRenderer->initWithSpriteFrame(imageSprite->getSpriteFrame());
        }
    }
}

bool QrCode::Init(const std::string& code) {
    return init() && LoadCodeByString(code);
}

void QrCode::initRenderer() {
    codeRenderer = Sprite::create();
    addProtectedChild(codeRenderer, CodeRendererZOrder, -1);
}

bool QrCode::LoadCodeByString(const std::string& code) {
    bool flag = false;
    QRcode* _qrcode = QRcode_encodeString(code.c_str(), 0, QR_ECLEVEL_H, QR_MODE_8, 1);

    if (_qrcode) {
        const int width = _qrcode->width;
        unsigned char* imageData = new unsigned char[width * width * 4];
        //默认为白色
        memset(imageData, 255, width * width * 4);

        Texture2D* texture = new (std::nothrow) Texture2D();
        for (int i = 0; i < _qrcode->width; ++i) {
            for (int j = 0; j < _qrcode->width; ++j) {
                if ((_qrcode->data[i * _qrcode->width + j] & 1) == 1) {
                    imageData[i * _qrcode->width * 4 + j * 4] = 0;     //r
                    imageData[i * _qrcode->width * 4 + j * 4 + 1] = 0; //g
                    imageData[i * _qrcode->width * 4 + j * 4 + 2] = 0; //b
                }
            }
        }
        //关闭抗锯齿，防止缩放后线条粘连
        texture->setAliasTexParameters();

        const Size s = Size(width, width);
        //使用RGBA8888格式以支持截图png
        texture->initWithData(imageData, width * width, backend::PixelFormat::RGBA8888, width, width, s);
        flag = codeRenderer->initWithTexture(texture);
        originSize = width;
        QRcode_free(_qrcode);
        codeRendererAdaptDirty = true;
    }
    return flag;
}

void QrCode::SetOriginSize() {
    setContentSize(Size(originSize,originSize));
}

void QrCode::CodeTextureScaleChangedWithSize() {
    codeRenderer->setContentSize(_contentSize);
    codeRenderer->setPosition(_contentSize.width / 2.0f, _contentSize.height / 2.0f);
}

void QrCode::adaptRenderers() {
    if (codeRendererAdaptDirty) {
        CodeTextureScaleChangedWithSize();
        codeRendererAdaptDirty = false;
    }
}

void QrCode::onSizeChanged() {
    Widget::onSizeChanged();
    codeRendererAdaptDirty = true;
}

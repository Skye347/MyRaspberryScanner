#ifndef QR_BASE_H
#define QR_BASE_H
#include<string>

class QRDecoderBase{
public:
    virtual std::string Decoder(const std::string& ImgPath)=0;
};

#endif
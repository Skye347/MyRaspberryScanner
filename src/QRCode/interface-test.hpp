#ifndef TEST_H
#define TEST_H

#include"qr-module-base.h"
#include<iostream>
#include<string>

class QRDecoder_test : public QRDecoderBase
{
  public:
    QRDecoder_test() : isInit(false)
    {
        isInit = Init();
    }
    ~QRDecoder_test()
    {

    }
    std::string Decoder(const std::string &ImgPath)
    {
        return ImgPath;
    }

  private:
    bool Init()
    {
        return true;
    }
    bool isInit;
};

#endif
#ifndef QR_HEADER
#define QR_HEADER
#include"./PyDecoder/QRDecoder_python.hpp"
#include"interface-test.hpp"
#include"../Config/config.h"

#ifdef USE_QRDECODER_PYTHON
    typedef QRDecoder_python QRDecoderDefault;
#elif defined(USE_QRDECODER_TEST)
    typedef QRDecoder_test QRDecoderDefault;
#else
    #error No decoder selected in config.h
#endif

#endif
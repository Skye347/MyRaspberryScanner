#ifndef QRDECODER_PY_H
#define QRDECODER_PY_H

#include "../qr-module-base.h"
#include<iostream>
#include<string>
#include<boost/python.hpp>

namespace py = boost::python;

class QRDecoder_python : public QRDecoderBase
{
  public:
    QRDecoder_python() : isInit(false)
    {
        isInit = Init();
    }
    ~QRDecoder_python()
    {

    }
    std::string Decoder(const std::string &ImgPath)
    {
        Py_Initialize();
        py::object global(py::import("__main__").attr("__dict__"));
        py::object pyFile=py::exec_file("static/qrdecoder.py", global, global);
        pyFile.PyErr_Print();
        pyDecoder=global["decoder"];
        std::cout<<"extract"<<std::endl;
        //execute method decoder
        std::string val = py::extract<std::string>(pyDecoder(ImgPath));
        return val;
    }
  private:
    bool Init()
    {
        return true;
    }
    bool isInit;
    py::object pyDecoder;

};

#endif
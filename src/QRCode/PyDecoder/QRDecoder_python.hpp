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
        try{
            std::cout<<"extract"<<std::endl;
            //execute method decoder
            std::string val = py::extract<std::string>(pyDecoder(ImgPath));
            return val;
        }
        catch(boost::python::error_already_set&){
            PyErr_Print();
            return "error";
        }
    }
  private:
    bool Init()
    {
        try{
            Py_Initialize();
            py::object global(py::import("__main__").attr("__dict__"));
            py::object pyFile=py::exec_file("static/qrdecoder.py", global, global);
            pyDecoder=global["decoder"];
            return true;
        }
        catch(boost::python::error_already_set&){
            PyErr_Print();
            return false;
        }
    }
    bool isInit;
    py::object pyDecoder;

};

#endif
#include "QRCode/qr-module.h"
#include "Data/data-general.h"
#include<iostream>

using namespace std;

int main(int argc,char** argv){
    string a(argv[1]);
    QRDecoderDefault decoder;
    std::cout<<decoder.Decoder(a)<<endl;
    return 0;
}
#include "QRCode/qr-module.h"
#include "Data/data-general.h"
#include<iostream>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include<thread>

//using namespace std;
using namespace cv;

CvCapture* pCapture=NULL;
bool running=false;

void thread_task(){
    // IplImage* img;
    // while(running){
    //     if(pCapture==NULL){
    //         std::cout<<"pCapture null"<<std::endl;
    //     }
    //     img=cvQueryFrame(pCapture);
    //     std::cout<<"saving"<<std::endl;
    //     cvSaveImage("current.jpg",img,0);
    //     std::cout<<"releasing"<<std::endl;
    //     cvReleaseImage(&img);
    //     sleep(1);
    // }
}

int main(int argc,char** argv){
    // string a(argv[1]);
    // QRDecoderDefault decoder;
    // std::cout<<decoder.Decoder(a)<<endl;
  //声明IplImage指针  
  IplImage* pFrame = NULL;  
  
 //获取摄像头  
  pCapture = cvCreateCameraCapture(-1);  
   
  //创建窗口  
  cvNamedWindow("video", 1);  
  running=true;
  std::thread t(thread_task); 
  //显示视屏  
  while(1)  
  {  
      pFrame=cvQueryFrame( pCapture );  
      if(!pFrame)break;  
      cvShowImage("video",pFrame);
      cvSaveImage("current.jpg",pFrame,0);  
      char c=cvWaitKey(33);  
      if(c==27)break;  
      QRDecoderDefault decoder;
      std::string a="/home/skye/CppProject/src/current.jpg";
      std::cout<<decoder.Decoder(a)<<std::endl;
      usleep(10000);
  }  
  cvReleaseCapture(&pCapture);  
  cvDestroyWindow("video");
  running=false;
  t.join();  
}
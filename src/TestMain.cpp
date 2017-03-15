#include "QRCode/qr-module.h"
#include "Data/data-general.h"
#include<iostream>
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc.hpp>  
#include <opencv2/core/core.hpp>  
#include<thread>
#include"Config/config.h"

//using namespace std;
using namespace cv;

CvCapture* pCapture=NULL;

void stop_handler(int signo){
    _exit(0);
}

int main(int argc,char** argv){
  signal(SIGINT,stop_handler);
  //声明IplImage指针  
  IplImage* pFrame = NULL;  
  
 //获取摄像头  
  pCapture = cvCreateCameraCapture(-1);  
   
#ifdef SHOW_CAMWINDOW 
  //创建窗口  
  cvNamedWindow("video", 1); 
#endif 
  //显示视屏  
  while(1)  
  {  
      pFrame=cvQueryFrame( pCapture );  
      if(!pFrame)break;
#ifdef SHOW_CAMWINDOW  
      cvShowImage("video",pFrame);
#endif
      cvSaveImage("current.jpg",pFrame,0);  
      char c=cvWaitKey(33);  
      if(c==27)break;  
      QRDecoderDefault decoder;
      std::string a="current.jpg";
      std::cout<<decoder.Decoder(a)<<std::endl;
      usleep(FRAME_INTERVAL);
  }  
  cvReleaseCapture(&pCapture); 
#ifdef SHOW_CAMWINDOW  
  cvDestroyWindow("video");
#endif
}
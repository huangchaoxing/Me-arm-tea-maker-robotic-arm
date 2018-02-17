#include <stdio.h>
#include <conio.h>
#include "tserial.h"
#include "bot_control.h"
#include "opencv2/opencv.hpp"
#include <highgui.h>
#include<opencv2/opencv.hpp> 
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stdlib.h>
using namespace cv;
using namespace std;

serial comm; //serial is a class type defined in these files, used for referring to the communication device


/*void sendRedFlag()     //the function that send red tea signal as 1
{   char flag;
         flag='1';
	comm.startDevice("COM3",9600); 
	comm.send_data(flag);
	comm.stopDevice();
	getch();
}*/

/*void sendx(int x,int y) //the function that send green tea signal as 2
{   
	char string1[25];
	char string2[5];
     itoa(x,string1,10);
	  itoa(y,string2,10);
     //char s[100]="x";
	 strcat(string1,string2);
	 for(int i=0;i<=4;i++)
	{comm.startDevice("COM3",9600);
	comm.send_data(string1[i]);
	comm.stopDevice();
	//getch();
	 }
}*/
 

/*void sendy(int y) //the function that send green tea signal as 2
 {   char string[25];
     itoa(y,string,10);
	 
     char s[100]="y";
	 strcat(s,string);
	 for(int i=0;i<=2;i++)
	{comm.startDevice("COM3",9600);
	comm.send_data(s[i]);
	comm.stopDevice();
	//getch();
	 }
}*/


void sendx(int x)
{  char X;
   X=char(x);
   comm.startDevice("COM3",9600);
   comm.send_data(X);
   comm.stopDevice();

}
void sendy(int y)
{  char Y;
   Y=char(y);
   comm.startDevice("COM3",9600);
   comm.send_data(Y);
   comm.stopDevice();
}

void main() {

//char flagRed=1;
//char flagGreen=2;
	  double x;
	  double y;
	  double u;
	  double v;
	  IplImage *pImg = NULL;
   // CvCapture *cap = cvCaptureFromCAM(0);
	 CvCapture *cap = cvCreateCameraCapture(0);
    char fileName[100];
    char key;
    int count = 0;
	
    while(1)
    {
        pImg = cvQueryFrame(cap);
       // cvFlip(pImg, NULL, 1); //水平翻转图像，像照镜子一样，不想要这个效果可以去掉此句
        key = cvWaitKey(50);
        if(key == 27) break; //按ESC键退出程序
        if(key == 'c')       //按c键拍照
        {
            sprintf(fileName, "Picture %d.jpg", ++count); //生成文件名
            cvSaveImage(fileName, pImg);
            cvXorS(pImg, cvScalarAll(255), pImg);         //将拍到的图像反色（闪一下形成拍照效果）

            cvShowImage("Camera",pImg);
            cvWaitKey(200); //反色图像显示ms
			
			Mat image=imread(fileName); //读取拍摄的照片,覆盖前一张
			imshow("photo",image);
			Mat midimage;
			cvtColor(image,midimage,CV_BGR2GRAY);//边缘检测后的灰度图
			GaussianBlur(midimage,midimage,Size(9,9),2,2);//高斯平滑

			vector<Vec3f> circles;
			HoughCircles(midimage,circles,CV_HOUGH_GRADIENT,1.5,240,250,50,0,0);
			//霍夫圆变换


			for(size_t i=0;i<circles.size();i++)
			{
			    Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));  
                int radius = cvRound(circles[i][2]);  
                //绘制圆心  
                circle( image, center, 15, Scalar(0,255,0), -1, 8, 0 );  
                //绘制圆轮廓  
                circle( image, center, radius, Scalar(155,50,255), 3, 8, 0 );  
				u=cvRound(circles[i][0]);
				v=cvRound(circles[i][1]);
		      printf("u=%f,v=%f\n",u,v);
			 
			}
			   x=(0.00086*u-0.1465)/0.0016;
			   y=(0.000857*v-0.0699)/0.0016+5; 
			    printf("x=%fmm,v=%fmm\n",x,y);
			   x=x/10;
			   y=y/10;
			   x=x-5.5; //相对于底座坐标
			   y=y-2;
			    printf("x=%fcm,v=%fcm\n",x,y);
			   x=(int)(x+0.5);
			   y=(int)(y+0.5);
			   
			   //坐标转换，在此仅作示意
			   printf("x=%fcm,y=%fcm\n",x,y);
			//x=15;
			  // y=-4; 
			 sendx(x);
			 sendy(y);
			namedWindow("效果图",500);
			imshow("效果图",image);
			 

        }
        cvShowImage("Camera",pImg);
		 
    }
	//namedWindow("photo");
	//Mat image=imread("Picture 1.jpg");
	//imshow("photo",image);
    cvReleaseCapture(&cap);
    //return 0;
}


/*Mat image=imread("2.jpg",1);     //load the image of the cup
namedWindow("1",CV_WINDOW_FREERATIO);
imshow("1",image);

Mat outputRed;
inRange(image,Scalar(10,10,100),Scalar(100,100,255),outputRed);  //change the red part into white
Mat outputGreen;
inRange(image,Scalar(35,43,46),Scalar(77,255,255),outputGreen);  // change the green part into white

int x1,x2;
	x1=countNonZero(outputRed);      // this part compares the intensity of the white part and determind which kind of tea it belongs to
	x2=countNonZero(outputGreen);
	if(x1>x2)
	{ cout<<"red tea";
	  sendRedFlag();
	  
	    }
	else{cout<<"green tea";
	      sendGreenFlag();}

	namedWindow("OutputRED",CV_WINDOW_FREERATIO);
	imshow("OutputRED",outputRed);
	namedWindow("OutputGreen",CV_WINDOW_FREERATIO);
	imshow("OutputGreen",outputGreen);



//char data; //To store the character to send
//printf("Enter character to be sent"); //User prompt
//data=getchar(); //User input
//comm.startDevice("COM3", 9600);
/* “COM 2” refers to the com port in which the USB to SERIAL port is attached. It is shown by right clicking on my computer, then going to properties and then device manager
9600 is the baud-rate in bits per second */
//comm.send_data(data); //The data is sent through the port
//comm.stopDevice(); //The device is closed down
//getch();





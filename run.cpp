#include<stdio.h>
#include<iostream>
//#include <features2d.hpp>
#include <highgui.h>
#include <cv.h>
#include <cxcore.h>
#include<fstream>

using namespace std;


int main(){


CvMat *image1=0;
ofstream outputFile("surf_1.txt");


static CvScalar red_color[] ={0,0,255};
IplImage* image=cvLoadImage("image.jpg");

image1 = cvCreateMat(image->height, image->width, CV_8UC1);
cvCvtColor(image, image1, CV_BGR2GRAY);

CvSeq* descriptors=0,*keypoints=0;

CvMemStorage* stor = cvCreateMemStorage(0);

CvSURFParams params=cvSURFParams(500,1);
cvExtractSURF(image1,0,&keypoints,&descriptors,stor,params);
for(CvSeq* c=descriptors;c!=NULL;c=c->h_next){
for(int i=0;i<c->total;++i){
CvPoint* p=(CvPoint*)cvGetSeqElem(c,i);
//cout<<p->y<<endl;
outputFile << p->y<<endl;

}



/*

for(int i=0;i<keypoints->total;i++)
{

CvSURFPoint* r=(CvSURFPoint*)cvGetSeqElem(keypoints,i);
CvPoint center;
int radius;
center.x=cvRound(r->pt.x);
center.y=cvRound(r->pt.y);
radius=cvRound(r->size*1.2/9.*2);
cvCircle(image,center, radius,red_color[0],1,8,0);
}

char key;
while(key != 'q' )
{

cvShowImage("image",image);
cvWaitKey(30);

cin>>key;

}

*/

}
return 0;


}








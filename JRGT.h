#include <cv.h>
#include <highgui.h>
#include <vector.h>
#include <string>
#define pi 22/7


using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

 typedef vector<string> Vec_place;
                typedef vector<Vec_place> Mat_place;

class JRGT{


public:
long line_size;
	JRGT();
	virtual ~JRGT();
	IplImage*  descriptorGauss(IplImage *src);
	IplImage* descriptorGabor(IplImage* im,float phase,float psi,float scale);
	vector<IplImage*> load_image_db();
	int movement_model();
	double euclidean(vector<string> v1,vector<double> v2);
	// pour extraction avec JGRT
	Vec globalComputationFeatures(vector<IplImage*> db_image);
	Mat_place place_detection();
	//vector<double> node_matching(Mat_place,Vec);
		void gf_extractor(IplImage* image);
		Vec globalComputationFeatures(IplImage* image);
		double euclidean_double(vector<double> v1,vector<double> v2);
		void ekf_RFID();
		void  fingerprint();
		float coss(vector<int> tag_val,int j);
	//rfid correction
//training
	//navigation
};





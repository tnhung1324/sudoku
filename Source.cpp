#include "opencv2/opencv.hpp"
#include <string>
#include <sstream>

using namespace cv;
using namespace std;

//§‚∂’≈‹º∆¶r 
int gesture() {
	VideoCapture cam(0);
	if (!cam.isOpened()) {
		cout << "ERROR not opened " << endl;
		return -1;
	}
	namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"


	int iLowH = 100;
	int iHighH = 124;

	int iLowS = 206;
	int iHighS = 255;

	int iLowV = 209;
	int iHighV = 255;

	//Create trackbars in "Control" window
	cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
	cvCreateTrackbar("HighH", "Control", &iHighH, 179);

	cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
	cvCreateTrackbar("HighS", "Control", &iHighS, 255);

	cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
	cvCreateTrackbar("HighV", "Control", &iHighV, 255);
	int i = 0;
	while (i < 10)
	{
		Mat imgOriginal;

		bool bSuccess = cam.read(imgOriginal); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		Mat imgHSV;
		vector<Mat> hsvSplit;

		cvResizeWindow("Thresholded Image", 480, 480);
		cvResizeWindow("Original", 480, 480);
		flip(imgOriginal, imgOriginal, 1);
		flip(imgHSV, imgHSV, 1);

		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

		//¶]¨∞ß⁄≠Ã≈™®˙™∫¨O±m¶‚πœ°A™Ω§Ëπœß°ø≈§∆ª›≠n¶bHSV™≈∂°∞µ
		split(imgHSV, hsvSplit);
		equalizeHist(hsvSplit[2], hsvSplit[2]);
		merge(hsvSplit, imgHSV);

		Mat imgThresholded;

		inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), imgThresholded); //Threshold the image

		//∂}æﬁß@ (•h∞£§@®«æ∏¬I)
		Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
		morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

		//≥¨æﬁß@ (≥sΩu§@®«≥s≥q∞Ï)
		morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);

		int col_1 = 0, col_2 = 160, col_3 = 320, col_4 = 480;
		int row_1 = 0, row_2 = 160, row_3 = 320, row_4 = 480;
		int h, s, v;
		int count_color = 0;
		int x, y;
		int path_2 = 0;
		string str;
		string path;

		//up
		line(imgOriginal, Point(col_2, row_1), Point(col_3, row_1), Scalar(0, 255, 0), 2);
		line(imgOriginal, Point(col_2, row_1), Point(col_2, row_2), Scalar(0, 255, 0), 2);
		line(imgOriginal, Point(col_2, row_2), Point(col_3, row_2), Scalar(0, 255, 0), 2);
		line(imgOriginal, Point(col_3, row_2), Point(col_3, row_1), Scalar(0, 255, 0), 2);
		path = "up";
		putText(imgOriginal, path, Point(200, 70), CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, 8, false);

		//down
		line(imgOriginal, Point(col_2, row_3), Point(col_2, row_4), Scalar(255, 255, 0), 2);
		line(imgOriginal, Point(col_2, row_3), Point(col_3, row_3), Scalar(255, 255, 0), 2);
		line(imgOriginal, Point(col_3, row_4), Point(col_3, row_3), Scalar(255, 255, 0), 2);
		line(imgOriginal, Point(col_3, row_4), Point(col_2, row_4), Scalar(255, 255, 0), 2);
		path = "down";
		putText(imgOriginal, path, Point(160, 400), CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, 8, false);

		//right
		line(imgOriginal, Point(col_3, row_2), Point(col_4, row_2), Scalar(0, 0, 255), 2);
		line(imgOriginal, Point(col_3, row_2), Point(col_3, row_3), Scalar(0, 0, 255), 2);
		line(imgOriginal, Point(col_4, row_3), Point(col_4, row_2), Scalar(0, 0, 255), 2);
		line(imgOriginal, Point(col_4, row_3), Point(col_3, row_3), Scalar(0, 0, 255), 2);
		path = "right";
		putText(imgOriginal, path, Point(330, 250), CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, 8, false);

		//left
		line(imgOriginal, Point(col_1, row_2), Point(col_2, row_2), Scalar(0, 255, 255), 2);
		line(imgOriginal, Point(col_1, row_2), Point(col_1, row_3), Scalar(0, 255, 255), 2);
		line(imgOriginal, Point(col_2, row_3), Point(col_1, row_3), Scalar(0, 255, 255), 2);
		line(imgOriginal, Point(col_2, row_2), Point(col_2, row_3), Scalar(0, 255, 255), 2);
		path = "left";
		putText(imgOriginal, path, Point(25, 250), CV_FONT_HERSHEY_SIMPLEX, 2, Scalar(255, 0, 0), 2, 8, false);


		//y = 125;
		//x = 200;
/************************************øÎ√—√C¶‚¨∞¬≈¶‚***********************************************/
		//UP
		for (x = 160; x < 320; x++) {
			for (y = 0; y < 160; y++) {
				h = imgHSV.at<cv::Vec3b>(y, x)[0];
				s = imgHSV.at<cv::Vec3b>(y, x)[1];
				v = imgHSV.at<cv::Vec3b>(y, x)[2];

				if (h > iLowH && h < iHighH && s > iLowS && s < iHighS && v > iLowV && v < iHighV) {
					count_color++;
				}
				if (count_color > 50) {
					str = "up";
					path_2 = 1;
				}
			}
		}
		count_color = 0;
		path_2 = 0;

		//DOWN
		for (x = 160; x < 320; x++) {
			for (y = 320; y < 480; y++) {
				h = imgHSV.at<cv::Vec3b>(y, x)[0];
				s = imgHSV.at<cv::Vec3b>(y, x)[1];
				v = imgHSV.at<cv::Vec3b>(y, x)[2];

				if (h > iLowH && h < iHighH && s > iLowS && s < iHighS && v > iLowV && v < iHighV) {
					count_color++;
				}
				if (count_color > 50) {
					str = "down";
					path_2 = 2;
				}
			}
		}
		count_color = 0;
		path_2 = 0;

		//LEFT
		for (x = 0; x < 160; x++) {
			for (y = 160; y < 320; y++) {
				h = imgHSV.at<cv::Vec3b>(y, x)[0];
				s = imgHSV.at<cv::Vec3b>(y, x)[1];
				v = imgHSV.at<cv::Vec3b>(y, x)[2];

				if (h > iLowH && h < iHighH && s > iLowS && s < iHighS && v > iLowV && v < iHighV) {
					count_color++;
				}
				if (count_color > 50) {
					str = "left";
					path_2 = 3;
				}
			}
		}
		count_color = 0;
		path_2 = 0;

		//RIGHT
		for (x = 320; x < 480; x++) {
			for (y = 160; y < 320; y++) {
				h = imgHSV.at<cv::Vec3b>(y, x)[0];
				s = imgHSV.at<cv::Vec3b>(y, x)[1];
				v = imgHSV.at<cv::Vec3b>(y, x)[2];

				if (h > iLowH && h < iHighH && s > iLowS && s < iHighS && v > iLowV && v < iHighV) {
					count_color++;
				}
				if (count_color > 50) {
					str = "right";
					path_2 = 4;
				}
			}
		}
		count_color = 0;
		path_2 = 0;

		putText(imgOriginal, str, Point(70, 70), CV_FONT_HERSHEY_SIMPLEX, 3, Scalar(255, 0, 0), 2, 8, false);


		imshow("Thresholded Image", imgThresholded); //show the thresholded image
		imshow("Original", imgOriginal); //show the original image


		char key = (char)waitKey(300);
		if (key == 27)
			break;
		i++;
	}
	Mat img;
	Mat img_threshold;
	Mat img_gray;
	Mat img_roi;
	namedWindow("Original_image", CV_WINDOW_AUTOSIZE);
	namedWindow("Gray_image", CV_WINDOW_AUTOSIZE);
	namedWindow("Thresholded_image", CV_WINDOW_AUTOSIZE);
	namedWindow("ROI", CV_WINDOW_AUTOSIZE);
	char a[40];
	int count = 0;
	int timecount = 0;//≠p∫‚while∂]¥X¶∏
	while (timecount < 10) {
		bool b = cam.read(img);
		if (!b) {
			cout << "ERROR : cannot read" << endl;
			return -1;
		}
		Rect roi(340, 100, 270, 270);
		img_roi = img(roi);
		cvtColor(img_roi, img_gray, CV_RGB2GRAY);

		GaussianBlur(img_gray, img_gray, Size(19, 19), 0.0, 0);
		threshold(img_gray, img_threshold, 0, 255, THRESH_BINARY_INV + THRESH_OTSU);

		vector<vector<Point> >contours;
		vector<Vec4i>hierarchy;
		findContours(img_threshold, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point());
		if (contours.size() > 0) {
			size_t indexOfBiggestContour = -1;
			size_t sizeOfBiggestContour = 0;
			for (size_t i = 0; i < contours.size(); i++) {
				if (contours[i].size() > sizeOfBiggestContour) {
					sizeOfBiggestContour = contours[i].size();
					indexOfBiggestContour = i;
				}
			}
			vector<vector<int> >hull(contours.size());
			vector<vector<Point> >hullPoint(contours.size());
			vector<vector<Vec4i> >defects(contours.size());
			vector<vector<Point> >defectPoint(contours.size());
			vector<vector<Point> >contours_poly(contours.size());
			Point2f rect_point[4];
			vector<RotatedRect>minRect(contours.size());
			vector<Rect> boundRect(contours.size());
			for (size_t i = 0; i < contours.size(); i++) {
				if (contourArea(contours[i]) > 5000) {
					convexHull(contours[i], hull[i], true);
					convexityDefects(contours[i], hull[i], defects[i]);
					if (indexOfBiggestContour == i) {
						minRect[i] = minAreaRect(contours[i]);
						for (size_t k = 0; k < hull[i].size(); k++) {
							int ind = hull[i][k];
							hullPoint[i].push_back(contours[i][ind]);
						}
						count = 0;

						for (size_t k = 0; k < defects[i].size(); k++) {
							if (defects[i][k][3] > 13 * 256) {
								/*   int p_start=defects[i][k][0];   */
								int p_end = defects[i][k][1];
								int p_far = defects[i][k][2];
								defectPoint[i].push_back(contours[i][p_far]);
								circle(img_roi, contours[i][p_end], 3, Scalar(0, 255, 0), 2);
								count++;
							}

						}

						if (count == 1)
							strcpy_s(a, "1 ");
						else if (count == 2)
							strcpy_s(a, "2 ");
						else if (count == 3)
							strcpy_s(a, "3 ");
						else if (count == 4)
							strcpy_s(a, "4");
						else
							strcpy_s(a, "0");


						putText(img, a, Point(70, 70), CV_FONT_HERSHEY_SIMPLEX, 3, Scalar(255, 0, 0), 2, 8, false);
						drawContours(img_threshold, contours, i, Scalar(255, 255, 0), 2, 8, vector<Vec4i>(), 0, Point());
						drawContours(img_threshold, hullPoint, i, Scalar(255, 255, 0), 1, 8, vector<Vec4i>(), 0, Point());
						drawContours(img_roi, hullPoint, i, Scalar(0, 0, 255), 2, 8, vector<Vec4i>(), 0, Point());
						approxPolyDP(contours[i], contours_poly[i], 3, false);
						boundRect[i] = boundingRect(contours_poly[i]);
						rectangle(img_roi, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2, 8, 0);
						minRect[i].points(rect_point);
						for (size_t k = 0; k < 4; k++) {
							line(img_roi, rect_point[k], rect_point[(k + 1) % 4], Scalar(0, 255, 0), 2, 8);
						}

					}
				}

			}
			imshow("Original_image", img);
			imshow("Gray_image", img_gray);
			imshow("Thresholded_image", img_threshold);
			imshow("ROI", img_roi);
			if (waitKey(30) == 27) {
				return -1;
			}
			//cout << timecount++;
			timecount++;

		}
	}
	cam.release();//√ˆƒ·π≥¿Y§ß´·¶A©I•sÆ…§~Ø‡•¥∂}
	//cout << count;
	return count;
}

//≥B≤z∞}¶C¶Ï∏m®√©Ò≠»®√¿À¨d
void localvacter(char board[][4], Point counter, char value) {
	char ansboard[4][4];//µ™Æ◊∞}¶C
	//2314
	ansboard[0][0] = '2';
	ansboard[0][1] = '3';
	ansboard[0][2] = '1';
	ansboard[0][3] = '4';
	//4132
	ansboard[1][0] = '4';
	ansboard[1][1] = '1';
	ansboard[1][2] = '3';
	ansboard[1][3] = '2';
	//1243
	ansboard[2][0] = '1';
	ansboard[2][1] = '2';
	ansboard[2][2] = '4';
	ansboard[2][3] = '3';
	//3421
	ansboard[3][0] = '3';
	ansboard[3][1] = '4';
	ansboard[3][2] = '2';
	ansboard[3][3] = '1';

	int pt_add = 148;
	int pt_x = 5;
	int pt_y = 10;
	float count = 0.5;
	if (value > 5 || value < 0) {
		cout << "0 < value < 5";
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (counter.x == pt_x + pt_add * (count + i) && counter.y == pt_y + pt_add * (count + j)) {
				board[j][i] = value;//ß‚µ™Æ◊©Ò∂i∞}¶C
				if (board[j][i] != ansboard[j][i]) { //¿À¨dµ™Æ◊
					board[j][i] = '0';
				}
			}
		}
	}
}

//∂Ò§J≥Ã™Ï∞}¶C
void readimg(char board[][4]) {
	//•˝∂Ò0
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = '0';
		}
	}
	//¶Aß‚√D•ÿº∆¶r∂Ò§J
	board[0][0] = '2';
	board[0][3] = '4';
	board[1][2] = '3';
	board[2][0] = '1';
	board[3][2] = '2';
}

//≈„•‹≤{¶b¶Ï∏m™∫º∆¶r ,¶^∂«≠»¨∞ßP¬_πC¿∏∞j∞È¨Oß_µ≤ßÙ
int display(char board[][4], Mat sudoku) {
	int end = 0;//ßP¬_•Dµ{¶°πC¿∏∞j∞È¨Oß_µ≤ßÙ,¶PÆ…¨∞¶π∞∆µ{¶°™∫¶^∂«≠»
	//≈„•‹¶bsudoku§W
	int pt_add = 148;
	int pt_x = 5;
	int pt_y = 10;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			stringstream ss;
			ss << board[i][j]; //ß‚int´¨∫A≈‹º∆ºg§J®Ïstringstream
			string convert_str;
			ss >> convert_str;  //≥zπL¶Í¨yπB∫‚§lºg®Ïstring√˛ßOßY•i
			//cout << convert_str;
			putText(sudoku, convert_str, Point(pt_x + pt_add * j, pt_y + pt_add * (i + 1)), FONT_HERSHEY_PLAIN, 10, Scalar(0, 0, 0));
			if (board[i][j] == '0') {
				end = 1;
			}
		}
	}return end;
}

void dealWithImg(Mat & src) {
	/*Mat src_YCrCb;
	cvtColor(src, src_YCrCb, CV_RGB2YCrCb);                     // ËΩ¨Â???YCRCB Á©∫Èó¥Â§ÑÁ?
	vector<Mat> channels;
	split(src_YCrCb, channels);

	Mat target = channels[2];
	threshold(target, target, 0, 255, CV_THRESH_OTSU);              // ‰∫åÂÄºÂ?Â§ÑÁ?

	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));   // ÂºÄËøêÁ??ªÈô§?™ÁÇπ
	morphologyEx(target, target, MORPH_OPEN, element);

	vector<vector<Point>> contours;                                 // ?©Áî®?ÄÂ§ßË??¥Êü•?æÊ???
	findContours(target, contours, CV_RETR_EXTERNAL, CHAIN_APPROX_NONE);
	double mymax = 0;
	vector<Point> max_contours;
	for (int i = 0; i < contours.size(); i++) {
		double area = contourArea(contours[i]);
		if (area > mymax) {
			mymax = area;
			max_contours = contours[i];
		}
	}
	vector<vector<Point>> final_cont;
	final_cont.push_back(max_contours);
	drawContours(src, final_cont, -1, Scalar(255));

	vector<vector<Point>>hull(contours.size());
	//vector<vector<Vec4i>>defects(contours.size());

	for (int i = 0; i < contours.size(); i++) {
		convexHull(contours[i], hull[i], false);
		vector<int> convexHull_IntIdx;
		vector<Vec4i> defects;
		//convexityDefects(contours[i], hull[i], defects[i]);


	}*/

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	RNG rng(clock());
	Mat src_YCrCb;
	cvtColor(src, src_YCrCb, CV_RGB2YCrCb);                     // ËΩ¨Â???YCRCB Á©∫Èó¥Â§ÑÁ?
	vector<Mat> channels;
	split(src_YCrCb, channels);

	Mat target = channels[2];
	threshold(target, target, 0, 255, CV_THRESH_OTSU);              // ‰∫åÂÄºÂ?Â§ÑÁ?

	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));   // ÂºÄËøêÁ??ªÈô§?™ÁÇπ
	morphologyEx(target, target, MORPH_OPEN, element);

	//vector<vector<Point>> contours;
	findContours(target, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	vector<vector<Point>> hull(contours.size());

	Mat imgDst;
	src.copyTo(imgDst);

	for (int i = 0; i < contours.size(); i++) {

		if (isContourConvex(contours[i]) || contours[i].size() < 3) continue;
		convexHull(Mat(contours[i]), hull[i], false);
		vector<int> convexHull_IntIdx;
		vector<Vec4i> defects;

		Mat imgMask;
		cout << "contour # " << i << endl;
		imgMask = Mat::zeros(src.size(), CV_8UC1);
		drawContours(imgMask, contours, i, Scalar(255), -1);
		Mat imgROI;
		src.copyTo(imgROI, imgMask);
		Scalar color1 = Scalar(255, 0, 0);
		drawContours(imgROI, contours, i, color1, 2, 8, vector<Vec4i>(), 0, Point());
		Scalar color2 = Scalar(0, 0, 255);
		drawContours(imgROI, hull, i, color2, 2, 8, vector<Vec4i>(), 0, Point());
		string name = std::to_string(i);
		//imshow(name, imgROI);
		//waitKey(0);

		if (contours[i].size() >= 3)
		{
			convexHull(contours[i], convexHull_IntIdx, true);
			convexityDefects(contours[i], convexHull_IntIdx, defects);
			for (int j = 0; j < defects.size(); ++j)
			{
				//cout << "defects[j]" << defects[j] << endl;
				Matx<int, 4, 1> defectVector = defects[j];
				vector<Point> contours1 = contours[i];
				Point point1 = contours1[defectVector.val[0]];// start point
				Point point2 = contours1[defectVector.val[1]];// end point
				Point point3 = contours1[defectVector.val[2]];// top point
				float dist = defectVector.val[3];
				cout << "point1 = " << point1 << endl;
				cout << "point2 = " << point2 << endl;
				cout << "point3 = " << point3 << endl;
				cout << "defect size = " << dist << endl;
				//printf("dist: %f \n", dist);
				if (defectVector.val[3] <= 10000) { continue; } // skip defects that are shorter than 100 pixel
				circle(imgROI, point1, 8, Scalar(255, 255, 0), -1, CV_AA);  //Èª?
				circle(imgROI, point2, 8, Scalar(0, 255, 0), -1, CV_AA);    //Á∂?
				circle(imgROI, point3, 8, Scalar(0, 0, 255), -1, CV_AA);    //??
				line(imgROI, point1, point2, Scalar(255, 255, 0), 2, 8);    //Èª?
				line(imgROI, point2, point3, Scalar(0, 255, 255), 2, 8);    //??
				line(imgROI, point3, point1, Scalar(255, 0, 255), 2, 8);    //Á¥?
				string name = std::to_string(i);
				imshow("imgROI", imgROI);
				waitKey(0);
			}
		}
	}
}

int main() {
	//string filename = R"(C:\Users\Administrator\Desktop\computer vision\3d-reconstruction-tools\data\videos\video0.avi)";
	//VideoCapture cap(filename);
	VideoCapture cap(0);
	Mat sudoku;
	   
	sudoku = imread("sudoku.jpg", IMREAD_COLOR);

	//?üÈ?:(5,10)
	int pt_add = 148;
	int pt_x = 5;
	int pt_y = 10;
	Point pt1(pt_x, pt_y);
	Point pt2(pt_x + pt_add, pt_y);
	Point pt3(pt_x, pt_y + pt_add);
	Point pt4(pt_x + pt_add, pt_y + pt_add);

	/*
	´K¨OÆaæﬁß@

	if(up && (pt_y - add) > = 10){
		pt_x = pt_x;
		pt_y = pt_y - pt_add;
	}else if(down && (pt_y + add) < = 600){
		pt_x = pt_x;
		pt_y = pt_y + pt_add;
	}else if(left && (pt_x - add) > = 10){
		pt_x = pt_x - pt_add;
		pt_y = pt_y;
	}else if(right && (pt_x + add) > = 600){
		pt_x = pt_x + pt_add;
		pt_y = pt_y;
	}
	*/

	line(sudoku, pt1, pt2, Scalar(0, 255, 0), 2);
	line(sudoku, pt1, pt3, Scalar(0, 255, 0), 2);
	line(sudoku, pt2, pt4, Scalar(0, 255, 0), 2);
	line(sudoku, pt3, pt4, Scalar(0, 255, 0), 2);

	if (pt1.y < pt3.y) {
		printf("down");
	}
	string pt_s;
	pt_s = pt1.x + "," + pt1.y;
	//printf("%s",pt_s);
	putText(sudoku, pt_s, Point(150, 150), CV_FONT_HERSHEY_SIMPLEX, 3, Scalar(255, 0, 0), 2, 8, false);

	namedWindow("º∆øW", 0);
	cvResizeWindow("º∆øW", 600, 600);
	imshow("º∆øW", sudoku);

	/*
	if (!cap.isOpened()) {
		cerr << "can not open camera" << endl;
		exit(-1);
	}*/

	//≥B≤z∞}¶C
	int end = 1;
	char board[4][4];
	readimg(board);//∂Ò∞}¶C™Ï©l≠»
	while (1) {		//πC¿∏™∫∞j∞È,end=1™Ì•‹∞}¶C§§¶≥0
		int value = gesture();//≈™≠»(∂}ƒ·¨€æ˜)
		//localvacter(board, Point counter,(char)value);//©Ò§J∞}¶C(Point counterª›≠nΩT©w¶Ï∏m)®√¿À¨d,≠Yø˘´h©Ò0
		end = display(board, sudoku);//≈„•‹
		imshow("º∆øW", sudoku);
	}

	Mat src;
	/*while (cap.read(src)) {
		dealWithImg(src);
		imshow("src", src);
		int key = waitKey(3);
		if (key == 27)
			break;
	}*/

	waitKey(0);
	return 0;
}



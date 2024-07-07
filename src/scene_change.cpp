#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/videoio.hpp>
#include <vector>
#include <fstream>

using namespace cv;
using namespace std;

double calculateOpticalFlowDifference(const Mat& prevFrame, const Mat& currFrame) {
    Mat prevGray, currGray;
    cvtColor(prevFrame, prevGray, COLOR_BGR2GRAY);
    cvtColor(currFrame, currGray, COLOR_BGR2GRAY);

    vector<Point2f> prevPts, currPts;
    vector<uchar> status;
    vector<float> err;

    goodFeaturesToTrack(prevGray, prevPts, 200, 0.3, 7);
    calcOpticalFlowPyrLK(prevGray, currGray, prevPts, currPts, status, err);

    double diff = 0.0;
    for (size_t i = 0; i < status.size(); i++) {
        if (status[i]) {
            diff += norm(prevPts[i] - currPts[i]);
        }
    }

    return diff;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <video_file> <output_file>" << endl;
        return -1;
    }

    string videoFile = argv[1];
    string outputFile = argv[2];
    VideoCapture cap(videoFile);
    if (!cap.isOpened()) {
        cout << "Error opening video file: " << videoFile << endl;
        return -1;
    }

    Mat prevFrame, currFrame;
    vector<int> sceneChanges;
    double threshold = 2000.0;  // Adjust the threshold based on your needs
    int framePos = 0;

    sceneChanges.push_back(0);

    while (true) {
        if (!cap.read(currFrame)) {
            break;
        }

        if (framePos > 0) {
            double diff = calculateOpticalFlowDifference(prevFrame, currFrame);
            if (diff > threshold) {
                sceneChanges.push_back(framePos);
            }
        }

        currFrame.copyTo(prevFrame);
        framePos++;
    }

    int total_frames = cap.get(CAP_PROP_FRAME_COUNT);
    sceneChanges.push_back(total_frames);

    cap.release();

    ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        cout << "Error opening output file: " << outputFile << endl;
        return -1;
    }

    for (int frame : sceneChanges) {
        outFile << frame << endl;
    }
    outFile.close();

    cout << "Scene changes detected and saved to " << outputFile << endl;

    return 0;
}


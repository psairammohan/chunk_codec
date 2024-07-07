#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv4/opencv2/videoio.hpp>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: ./video_info <video_file_path>" << std::endl;
        return -1;
    }

    std::string video_file_path = argv[1];
    cv::VideoCapture cap(video_file_path);
    int frame_width = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_HEIGHT));
    int fps = static_cast<int>(cap.get(cv::CAP_PROP_FPS));
    int total_frames = static_cast<int>(cap.get(cv::CAP_PROP_FRAME_COUNT));

    std::cout << "Frame Width = " << frame_width << std::endl;
    std::cout << "Frame Height = " << frame_height << std::endl;
    std::cout << "fps = " << fps << std::endl;
    std::cout << "Frame Count = " << total_frames << std::endl; 

}

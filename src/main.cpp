#include <opencv2/opencv.hpp>
#include <string>
#include <filesystem>

int main()
{
    std::filesystem::path imagePath = "background.jpeg";

    cv::Mat image = cv::imread(imagePath.filename());

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3,3));
    cv::Mat destImg;
    cv::morphologyEx(image, destImg, cv::MORPH_CLOSE, kernel, cv::Point(-1,-1), 10);

    cv::imwrite(imagePath.stem().string() + "_close" + imagePath.extension().string(), destImg);
    
    return 0;
}

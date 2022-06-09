#include <opencv2/opencv.hpp>
#include <string>
#include <filesystem>

int main()
{
    std::filesystem::path imagePath = "background.jpeg";

    cv::Mat image = cv::imread(imagePath.filename());

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_CROSS, cv::Size(3, 3));

    // close
    cv::Mat imageClose;
    cv::morphologyEx(image, imageClose, cv::MORPH_CLOSE, kernel, cv::Point(-1, -1), 10);
    cv::imwrite(imagePath.stem().string() + "_close" + imagePath.extension().string(), imageClose);

    // open
    cv::Mat imageOpen;
    cv::morphologyEx(image, imageOpen, cv::MORPH_OPEN, kernel, cv::Point(-1, -1), 10);
    cv::imwrite(imagePath.stem().string() + "_open" + imagePath.extension().string(), imageOpen);

    // blur
    cv::Mat imageBlur;
    cv::blur(image, imageBlur, cv::Size(3, 3));
    cv::imwrite(imagePath.stem().string() + "_blur" + imagePath.extension().string(), imageBlur);

    // canny
    cv::Mat imageCanny;
    cv::Canny(image, imageCanny, 0, 250);
    cv::imwrite(imagePath.stem().string() + "_canny_0_250" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 0, 100);
    cv::imwrite(imagePath.stem().string() + "_canny_100_100" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 100, 100);
    cv::imwrite(imagePath.stem().string() + "_canny_100_100" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 0, 0);
    cv::imwrite(imagePath.stem().string() + "_canny_0_0" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 1000, 1000);
    cv::imwrite(imagePath.stem().string() + "_canny_1000_1000" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 0, 1000);
    cv::imwrite(imagePath.stem().string() + "_canny_0_1000" + imagePath.extension().string(), imageCanny);
    return 0;
}

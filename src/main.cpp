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
    cv::morphologyEx(image, imageClose, cv::MORPH_CLOSE, kernel);
    cv::imwrite(imagePath.stem().string() + "_close" + imagePath.extension().string(), imageClose);
    // close
    cv::morphologyEx(image, imageClose, cv::MORPH_CLOSE, kernel, cv::Point(-1, -1), 10);
    cv::imwrite(imagePath.stem().string() + "_close_10" + imagePath.extension().string(), imageClose);
    
    // close_combine
    imageClose = image;
    cv::dilate(imageClose, imageClose, kernel);
    cv::erode(imageClose, imageClose, kernel);
    cv::imwrite(imagePath.stem().string() + "_close_combine" + imagePath.extension().string(), imageClose);
    // close_combine
    imageClose = image;
    for(int i = 0; i < 10; ++i)
    {
        cv::dilate(imageClose, imageClose, kernel);
        cv::erode(imageClose, imageClose, kernel);
    }
    cv::imwrite(imagePath.stem().string() + "_close_combine_10" + imagePath.extension().string(), imageClose);

    // open
    cv::Mat imageOpen;
    cv::morphologyEx(image, imageOpen, cv::MORPH_OPEN, kernel);
    cv::imwrite(imagePath.stem().string() + "_open" + imagePath.extension().string(), imageOpen);
    // open
    cv::morphologyEx(image, imageOpen, cv::MORPH_OPEN, kernel, cv::Point(-1, -1), 10);
    cv::imwrite(imagePath.stem().string() + "_open_10" + imagePath.extension().string(), imageOpen);

    // open combine
    imageOpen = image;
    cv::erode(imageOpen, imageOpen, kernel);
    cv::dilate(imageOpen, imageOpen, kernel);
    cv::imwrite(imagePath.stem().string() + "_open_combine" + imagePath.extension().string(), imageOpen);
    // open combine
    imageOpen = image;
    for(int i = 0; i < 10; ++i)
    {
        cv::erode(imageOpen, imageOpen, kernel);
    }
    for(int i = 0; i < 10; ++i)
    {
        cv::dilate(imageOpen, imageOpen, kernel);
    }
    cv::imwrite(imagePath.stem().string() + "_open_combine_10" + imagePath.extension().string(), imageOpen);


    // blur
    cv::Mat imageBlur;
    cv::blur(image, imageBlur, cv::Size(3, 3));
    cv::imwrite(imagePath.stem().string() + "_blur" + imagePath.extension().string(), imageBlur);

    // canny
    cv::Mat imageCanny;
    cv::Canny(image, imageCanny, 0, 250);
    cv::imwrite(imagePath.stem().string() + "_canny_0_255" + imagePath.extension().string(), imageCanny);
    // canny
    cv::Canny(image, imageCanny, 85, 255);
    cv::imwrite(imagePath.stem().string() + "_canny_85_255" + imagePath.extension().string(), imageCanny);
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

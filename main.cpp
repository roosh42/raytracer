#include <opencv2/opencv.hpp>

using namespace cv;

int main() {
    // Create an array of RGB values (assuming a 3x3 image)
    int rgbData[3][3][3] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}},
        {{255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };

    // Create a Mat object from the RGB data
    Mat image(3, 3, CV_8UC3, rgbData);

    // Write the image to a BMP file
    imwrite("output.bmp", image);

    return 0;
}
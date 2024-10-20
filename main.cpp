#include <opencv2/opencv.hpp>
#include <optional>
#include <iostream>

#include "Point.hpp"
#include "Direction.hpp"

using std::cout;
using std::endl;
using std::sqrt;
using std::optional;
using std::nullopt;

class Ray {
public:
    Point start;
    Direction dir;

    Ray(Point s, Point other): start{s}, dir{s, other} {}

    Point atT(double t) const{
        return start + (t * Point(dir));
    }
};

class Sphere {
public:
    Point center;
    double radius;

    optional<Point> intersect(const Ray& ray) const {
        Point dir_p = Point(ray.dir);
        Point diff = ray.start - center;
        double a = dir_p * dir_p;
        double b = 2 * (diff * dir_p);
        double c = diff * diff - radius * radius;
        double discriminant = b*b - 4*a*c;
        if (discriminant < 0) {
            return nullopt;
        }
        double t1 = (-b + sqrt(discriminant)) / (2*a);
        double t2 = (-b - sqrt(discriminant)) / (2*a);
        double t = t1 < 0 ? t2 : (t2 < 0 ? t1 : (t1 < t2 ? t1 : t2));
        if (t < 0) {
            return nullopt;
        }
        
        return ray.atT(t);
    }
};

class CCD {
public:
    double x_size;
    double y_size;
    double z_location;
    int rows;
    int columns;

    Point get(int r, int c) {
        double x = (-x_size*0.5) + ((x_size / rows) * (r+0.5));
        double y = (y_size*0.5) - ((y_size / columns) * (c+0.5));
        Point pixel_center = Point{x, y, z_location};
        return pixel_center;
    }
};

int main() {
    // Create an array of RGB values (assuming a 3x3 image)
    int rgbData[3][3][3] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}},
        {{255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };
    CCD ccd{1, 1, 1, 20, 20};
    Sphere sphere{Point{0, 0, -10}, 4};
    for (int r = 0; r < ccd.rows; r++) {
        cout << endl;
        for (int c = 0; c < ccd.columns; c++) {
            Point p = ccd.get(r, c);
            Ray ray{p, Point{0, 0, 0}};
            optional<Point> contact = sphere.intersect(ray);
            if (!contact.has_value()) {
                cout << "  ";
            } else {
                cout << "XX";
            }
        }
    }
    cout << endl;

    // Create a Mat object from the RGB data
    cv::Mat image(3, 3, CV_8UC3, rgbData);

    // Write the image to a BMP file
//    cv::imwrite("output.bmp", image);

    return 0;
}
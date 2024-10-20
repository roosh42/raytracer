#include <opencv2/opencv.hpp>

#include "Point.hpp"
#include "Direction.hpp"

#ifdef COMMENT
class Ray {
public:
    Point start;
    Direction dir;

    Ray(Point s, Point other): start{s}, dir{s, other} {}

    Point atT(double t) {
        return start + (t * Point(dir));
    }
};

class Sphere {
public:
    Point center;
    double radius;

    optional<Point> intersect(Ray ray) {
        double c = dot(ray.start, ray.start) - radius;
        double b = 2 * dot(ray.start, ray.dir);
        double a = dot(ray.dir, ray.dir);
        double discriminant = b*b - 4*a*c;
        double t0 = (-b + sqrt(discriminant)) / (2*a);
        double t1 = (-b - sqrt(discriminant)) / (2*a);
        double t = t0 < 0 ? t1 : (t1 < 0 ? t0 : (t1 < t0 ? t1 : t0));
        if (t < 0) {
            return nullopt;
        }

        Point contact = ray.atT(t);

        return contact;
    }
};

class CCD {
    double x_size;
    double y_size;
    double z_location;
    int rows;
    int columns;

    Point get(int r, int c) {
        double x = (-x_size*0.5) + ((x_size / rows) * r);
        double y = (y_size*0.5) - ((y_size / columns) * c);
        return Point{x, y, z_location};
    }
};
#endif  // COMMENT

int main() {
    // Create an array of RGB values (assuming a 3x3 image)
    int rgbData[3][3][3] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}},
        {{255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
        {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}
    };

    Point p(1, 2, 3);
    
    // // Create a Mat object from the RGB data
    // cv::Mat image(3, 3, cv::CV_8UC3, rgbData);

    // // Write the image to a BMP file
    // cv::imwrite("output.bmp", image);

    return 0;
}
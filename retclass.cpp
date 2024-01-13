// Rectangles.h
#ifndef RECTANGLES_H
#define RECTANGLES_H

#include <string>
#include <iostream>
#include <vector>

class Rectangles {
private:
    double x;
    double y;
    double w;
    double h;
    std::string name;

public:
    Rectangles(double x, double y, double w, double h, std::string retname) 
        : x(x), y(y), w(w), h(h), name(retname) {}

    std::vector<double> origin() {
        return {x, y};
    }

    double getWidth() {
        return w;
    }

    double getHeight() {
        return h;
    }

    std::vector<double> getRectPointsX() {
        return {x, x + w, x + w, x, x};
    }

    std::vector<double> getRectPointsY() {
        return {y, y, y - h, y - h, y};
    }

    bool IntersectionWith(Rectangles ret) {
        if (ret.name != name) {
            std::vector<double> retpointsx = ret.getRectPointsX();
            std::vector<double> retpointsy = ret.getRectPointsY();

            for (size_t i = 0; i < retpointsx.size(); ++i) {
                if ((retpointsx[i] >= x && retpointsx[i] <= x + w) &&
                    (retpointsy[i] <= y && retpointsy[i] >= y - h)) {
                    return true;
                }
            }

            retpointsx = getRectPointsX();
            retpointsy = getRectPointsY();

            for (size_t i = 0; i < retpointsx.size(); ++i) {
                if ((retpointsx[i] >= ret.x && retpointsx[i] <= ret.x + ret.w) &&
                    (retpointsy[i] <= ret.y && retpointsy[i] >= ret.y - ret.h)) {
                    return true;
                }
            }
        }

        return false;
    }
};

#endif // RECTANGLES_H

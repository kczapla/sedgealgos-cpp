#pragma once

namespace sedgealgos {
    class Point2d {
        public:
            Point2d(double x, double y) : xaxis{x}, yaxis{y} {}

            auto x() const {
                return xaxis;
            }

            auto y() const {
                return yaxis;
            }

            double radius() const;
            double theta() const;
            double distance_to(Point2d const& other) const;

        private:
            double xaxis{};
            double yaxis{};
    };
}

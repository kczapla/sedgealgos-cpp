#pragma once
#include "sedgealgos/point2d.hpp"
#include "sedgealgos/interval1d.hpp"

namespace sedgealgos {
    class Interval2d {
    public:
        Interval2d() = default;
        Interval2d(Interval1d x, Interval1d y) : xinterval{std::move(x)}, yinterval{std::move(y)} {}

        double area() const;
        bool contains(Point2d const&) const;
        bool intersects(Interval2d const&) const;

    private:
        Interval1d xinterval{};
        Interval1d yinterval{};
    };
}

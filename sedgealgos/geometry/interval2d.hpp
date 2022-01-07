#pragma once
#include "sedgealgos/geometry/point2d.hpp"
#include "sedgealgos/geometry/interval1d.hpp"

#include <string>

namespace sedgealgos::geometry {
    class Interval2d {
    public:
        Interval2d() = default;
        Interval2d(Interval1d x, Interval1d y) : xinterval{std::move(x)}, yinterval{std::move(y)} {}

        double area() const;
        bool contains(geometry::Point2d const&) const;
        bool intersects(Interval2d const&) const;

        std::string string() const;

    private:
        Interval1d xinterval{};
        Interval1d yinterval{};
    };
}

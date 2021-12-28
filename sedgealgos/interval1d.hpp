namespace sedgealgos {
    class Interval1d {
    public:
       Interval1d() = default;
       Interval1d(double x, double y) : xaxis{x}, yaxis{y} {}

       double length() const;
       bool contains(double) const;

    private:
       double xaxis{};
       double yaxis{};
    };
}


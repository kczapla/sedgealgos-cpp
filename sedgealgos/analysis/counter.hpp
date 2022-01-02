#pragma once

#include <string>

namespace sedgealgos::analysis {
    class Counter {
    public:
        Counter() = default;
        Counter(std::string i) : id{std::move(i)} {}

        void increment();
        int tally() const;

        std::string string() const;

    private:
        int counter{};
        std::string id{};
    };
}

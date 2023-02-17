#include "sedgealgos/io/std_out.hpp"
#include "sedgealgos/random/std_random.hpp"
#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_weights.hpp"

#include <string>
#include <sstream>

namespace { 
    struct Stats {
        int generated_pair_count;
        int connections_count;

        std::string string() const {
            std::stringstream ss;
            ss << "{generated_pairs_number = ";
            ss << std::to_string(generated_pair_count);
            ss << ", connections_count = ";
            ss << std::to_string(connections_count);
            ss << "}";

            return ss.str();
        }
    };

    Stats count(int number_of_points) {
        sedgealgos::io::StdOut out;
        sedgealgos::random::StdRandom random{};
        sedgealgos::algorithms::union_find::QuickUnionUnionFindWithWeights union_find{number_of_points};

        auto const lower{0};
        auto const upper{number_of_points - 1};

        auto connections_count{0};
        auto generated_pair_count{0};
        while (union_find.count() != 1) {
            auto const p{random.uniform(lower, upper)};
            auto const q{random.uniform(lower, upper)};
            generated_pair_count++;

            if (!union_find.connected(p, q)) {
                union_find.connect(p, q);
                connections_count += 1;
            }
        }

        return {generated_pair_count, connections_count};
    }
}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut out;

    if (argc < 2) {
        out.println("Please provide N");
    } else if (argc > 2) {
        out.println("Please provide only N");
    }

    auto const number_of_points{argv[1]};

    auto const stats{::count(std::stoi(number_of_points))};
    out.printf("number of connections %s\n", stats.string());

    return 0;
}

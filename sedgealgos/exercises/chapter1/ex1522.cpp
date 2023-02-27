#include "sedgealgos/io/std_out.hpp"

#include "sedgealgos/random/std_random.hpp"

#include "sedgealgos/algorithms/union_find/quick_find_union_find.hpp"
#include "sedgealgos/algorithms/union_find/quick_union_union_find.hpp"
#include "sedgealgos/algorithms/union_find/quick_union_union_find_with_weights.hpp"

#include <chrono>
#include <string>
#include <thread>
#include <sstream>

namespace { 
    struct Stats {
        int generated_pair_count;
        int connections_count;

        std::string string() const {
            std::stringstream ss;
            ss << "{generated_pairs_number: ";
            ss << std::to_string(generated_pair_count);
            ss << ", connections_count: ";
            ss << std::to_string(connections_count);
            ss << "}";

            return ss.str();
        }
    };

    template <typename UnionFind>
    Stats count(int number_of_points) {
        sedgealgos::io::StdOut out;
        sedgealgos::random::StdRandom random{};
        UnionFind union_find{number_of_points};

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

    struct IterationResult {
        Stats stats;
        int duration;

        std::string string() const {
            std::stringstream ss;
            ss << "{stats: ";
            ss << stats.string();
            ss << ", duration: ";
            ss << duration << "s}";

            return ss.str();
        }
    };

    using IterationResults = std::vector<IterationResult>;

    IterationResult get_average(IterationResults const& test_results) {
        auto number_of_samples{test_results.size()};

        auto sum_generated_pair_count{0};
        auto sum_connections_count{0};
        auto sum_durations{0};
        for (auto& test_result : test_results) {
            sum_generated_pair_count += test_result.stats.generated_pair_count;
            sum_connections_count += test_result.stats.connections_count;
            sum_durations += test_result.duration;
        }

        IterationResult avg_iteration_result;
        avg_iteration_result.stats.generated_pair_count = sum_generated_pair_count / number_of_samples;
        avg_iteration_result.stats.connections_count = sum_connections_count / number_of_samples;
        avg_iteration_result.duration = sum_durations / number_of_samples;

        return avg_iteration_result;
    }

    struct TestResult {
        int n;
        IterationResult average_iteration_reslult;

        std::string string() const {
            std::stringstream ss;
            ss << "{n: "; 
            ss << n;
            ss << ", average iteration result: ";
            ss << average_iteration_reslult.string() << "}";

            return ss.str();
        }
    };

    template<typename T>
    TestResult run_test_iterations(int t, int n) {
        IterationResults results;
        for (auto i{0}; i < t; i++) {
            auto start{std::chrono::high_resolution_clock::now()};
            auto stats{count<T>(n)};
            std::this_thread::sleep_for(std::chrono::seconds(3));
            auto end{std::chrono::high_resolution_clock::now()};
            auto iteration_duration{std::chrono::duration_cast<std::chrono::seconds>(end - start).count()};

            std::cout << "iteration_duration = " << iteration_duration << std::endl;

            results.emplace_back(stats, iteration_duration);
        }

        auto const average_iteration_result{get_average(results)};

        return {n, average_iteration_result};
    }
    

}

int main(int argc, char** argv) {
    sedgealgos::io::StdOut out;

    if (argc < 3) {
        out.println("Please provide T and N");
        return 1;
    } else if (argc > 3) {
        out.println("Please provide only T and only N");
        return 1;
    }

    auto const t{std::stoi(argv[1])};
    auto const n{std::stoi(argv[2])};

    auto const fast_find_union_find_test_result{::run_test_iterations<sedgealgos::algorithms::union_find::QuickFindUnionFind>(t, n)};
    out.printf("quick find union find %s\n", fast_find_union_find_test_result.string());

    auto const fast_union_union_union_find{::run_test_iterations<sedgealgos::algorithms::union_find::QuickUnionUnionFind>(t, n)};
    out.printf("quick union union find %s\n", fast_union_union_union_find.string());

    auto const fast_union_union_union_find_with_weights{::run_test_iterations<sedgealgos::algorithms::union_find::QuickUnionUnionFindWithWeights>(t, n)};
    out.printf("quick union union find with weights %s\n", fast_union_union_union_find_with_weights.string());


    return 0;
}

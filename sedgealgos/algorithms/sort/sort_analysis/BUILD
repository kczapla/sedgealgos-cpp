load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_binary",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_binary(
    name = "sort_compare",
    srcs = ["sort_compare.cpp"],
    deps = [
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:selection_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_selection_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_precalc_gaps_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort_with_sentry",
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort_without_exchange",
        "//sedgealgos/algorithms/sort/sort_analysis:generate_array",
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/data_structures/hash_map:hash_map",
        "//sedgealgos/io:std_out",
        "//sedgealgos/time/stopwatch:stopwatch",
    ],
)

sedgealgos_cc_binary(
    name = "shell_sort_cmp_counter",
    srcs = ["shell_sort_cmp_counter.cpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
    ],
)

sedgealgos_cc_binary(
    name = "worst_case_shell_array",
    srcs = ["worst_case_shell_array.cpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
    ],
)

sedgealgos_cc_binary(
    name = "shell_sort_find_gaps",
    srcs = ["shell_sort_find_gaps.cpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
        "//sedgealgos/time/stopwatch:stopwatch",
    ],
)

sedgealgos_cc_library(
    name = "generate_array",
    hdrs = [
        "generate_array.hpp",
    ],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/data_structures/string:string",
        "//sedgealgos/random:std_random",
    ]
)

sedgealgos_cc_binary(
    name = "doubling_test",
    srcs = ["doubling_test.cpp"],
    deps = [
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:selection_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_selection_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:shell_precalc_gaps_sort",
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort_with_sentry",
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort_without_exchange",
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
        "//sedgealgos/time/stopwatch:stopwatch",
    ],
)

sedgealgos_cc_binary(
    name = "sort",
    srcs = [
        "sort.cpp"
    ],
    deps = [
        "//sedgealgos/algorithms/sort/merge_sort/bottom_up:sort",
        "//sedgealgos/algorithms/sort/merge_sort/top_down:merge_sort",
        "//sedgealgos/algorithms/sort/merge_sort/merge:merge",
        "//sedgealgos/algorithms/sort/merge_sort/merge:faster_merge",
        "//sedgealgos/algorithms/sort/sort_analysis:generate_array",
        "//sedgealgos/data_structures/string:string",
        "//sedgealgos/io:std_out",
        "//sedgealgos/algorithms/sort/sort/callbacks:sort_statistics",
    ],
)
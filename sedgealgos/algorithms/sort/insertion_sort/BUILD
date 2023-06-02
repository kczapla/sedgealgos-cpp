load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "insertion_sort",
    hdrs = ["insertion_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "insertion_sort_without_exchange",
    hdrs = ["insertion_sort_without_exchange.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "insertion_sort_with_sentry",
    hdrs = ["insertion_sort_with_sentry.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)


sedgealgos_cc_library(
    name = "selection_sort",
    hdrs = ["selection_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "shell_sort",
    hdrs = ["shell_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "shell_selection_sort",
    hdrs = ["shell_selection_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "shell_precalc_gaps_sort",
    hdrs = ["shell_precalc_gaps_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "check_sort",
    hdrs = ["check_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_test(
    name = "sort_test",
    srcs = ["sort_test.cpp"],
    deps = [
        "insertion_sort",
        "selection_sort",
        "shell_sort",
        "shell_selection_sort",
        "shell_precalc_gaps_sort",
        "insertion_sort_with_sentry",
        "insertion_sort_without_exchange",
        "//sedgealgos/algorithms/sort/merge_sort/bottom_up:sort",
        "//sedgealgos/algorithms/sort/sort:callbacks_mock",
        "//sedgealgos/algorithms/sort/merge_sort/merge:merge",
    ],
)


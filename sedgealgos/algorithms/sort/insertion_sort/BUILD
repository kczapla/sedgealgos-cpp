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
    name = "selection_sort",
    hdrs = ["selection_sort.hpp"],
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
    ],
)


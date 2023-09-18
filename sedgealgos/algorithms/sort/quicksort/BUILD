load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "quicksort",
    hdrs = [
        "quicksort.hpp",
    ],
)

sedgealgos_cc_test(
    name = "quicksort_test",
    srcs = [
        "quicksort_test.cpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/quicksort:quicksort",
        "//sedgealgos/data_structures/array:array",
    ],
)
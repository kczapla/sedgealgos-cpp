load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "merge_sort",
    hdrs = [
        "sort.hpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/merge_sort:merge_sort",
        "//sedgealgos/algorithms/sort/sort:callbacks",
    ]
)
load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "sort",
    hdrs = [
        "sort.hpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/merge_sort/merge:merge",
        "//sedgealgos/algorithms/sort/sort:callbacks",
    ]
)
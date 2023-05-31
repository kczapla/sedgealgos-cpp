load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "sort_statistics",
    hdrs = [
        "sort_statistics.hpp",
    ],
    srcs = [
        "sort_statistics.cpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/sort:callbacks",
        "//sedgealgos/data_structures/string:string",
    ],
)
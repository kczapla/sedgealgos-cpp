load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "farthest_pair",
    hdrs = ["farthest_pair.hpp"],
    srcs = ["farthest_pair.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ]
)

sedgealgos_cc_test(
    name = "farthest_pair_test",
    srcs = ["farthest_pair_test.cpp"],
    deps = [
        "farthest_pair",
    ],
)


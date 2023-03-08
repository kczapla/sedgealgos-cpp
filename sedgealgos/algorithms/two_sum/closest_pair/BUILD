load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "closest_pair",
    hdrs = ["closest_pair.hpp"],
    srcs = ["closest_pair.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "closest_pair_test",
    srcs = ["closest_pair_test.cpp"],
    deps = [
        "closest_pair",
    ],
)


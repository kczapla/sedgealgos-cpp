load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "four_sum",
    hdrs = ["four_sum.hpp"],
    srcs = ["four_sum.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "four_sum_test",
    srcs = ["four_sum_test.cpp"],
    deps = [
        "four_sum",
    ],
)


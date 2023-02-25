load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "three_sum",
    hdrs = ["three_sum.hpp"],
    srcs = ["three_sum.cpp"],
)

sedgealgos_cc_test(
    name = "three_sum_test",
    srcs = ["three_sum_test.cpp"],
    deps = [
        "three_sum",
    ],
)

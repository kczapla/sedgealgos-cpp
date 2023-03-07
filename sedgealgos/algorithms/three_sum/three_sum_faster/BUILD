load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "three_sum_faster",
    hdrs = ["three_sum_faster.hpp"],
    srcs = ["three_sum_faster.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "three_sum_faster_test",
    srcs = ["three_sum_faster_test.cpp"],
    deps = [
        "three_sum_faster",
    ],
)


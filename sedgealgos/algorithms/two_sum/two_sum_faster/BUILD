load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
    "sedgealgos_cc_binary",
)

sedgealgos_cc_library(
    name = "two_sum_faster",
    hdrs = ["two_sum_faster.hpp"],
    srcs = ["two_sum_faster.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "two_sum_faster_test",
    srcs = ["two_sum_faster_test.cpp"],
    deps = [
        "two_sum_faster",
    ],
)

sedgealgos_cc_binary(
    name = "two_sum_faster_doubling_test",
    srcs = ["two_sum_faster_doubling_test.cpp"],
    deps = [
        "two_sum_faster",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
        "//sedgealgos/time/stopwatch:stopwatch",
    ],
)

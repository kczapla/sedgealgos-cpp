load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "ring_buffer",
    hdrs = ["ring_buffer.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_test(
    name = "ring_buffer_test",
    srcs = ["ring_buffer_test.cpp"],
    deps = [
        "ring_buffer",
    ],
)


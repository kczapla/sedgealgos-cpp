load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "are_equal",
    hdrs = [
        "are_equal.hpp",
    ],
    srcs = [
        "are_equal.cpp",
    ],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "are_equal_test",
    srcs = [
        "are_equal_test.cpp",
    ],
    deps = [
        ":are_equal",
    ],
)

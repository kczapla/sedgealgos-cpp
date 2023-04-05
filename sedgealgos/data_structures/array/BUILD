load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "array",
    hdrs = ["array.hpp"],
)

sedgealgos_cc_test(
    name = "array_test",
    srcs = ["array_test.cpp"],
    deps = [
        "array",
    ],
)


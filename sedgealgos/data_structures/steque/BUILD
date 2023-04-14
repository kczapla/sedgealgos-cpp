load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "steque",
    hdrs = ["steque.hpp"],
    srcs = ["steque.cpp"],
)

sedgealgos_cc_test(
    name = "steque_test",
    srcs = ["steque_test.cpp"],
    deps = [
        "steque",
    ],
)


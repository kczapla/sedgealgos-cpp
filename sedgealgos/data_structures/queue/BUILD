load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "queue",
    hdrs = ["queue.hpp"],
    srcs = ["queue.cpp"],
)

sedgealgos_cc_test(
    name = "queue_test",
    srcs = ["queue_test.cpp"],
    deps = [
        "queue",
    ],
)


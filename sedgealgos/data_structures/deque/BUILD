load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "deque",
    hdrs = ["deque.hpp"],
    deps = [
        "//sedgealgos/data_structures/linked_list:double_linked_list",
    ],
)

sedgealgos_cc_library(
    name = "resizing_array_deque",
    hdrs = ["resizing_array_deque.hpp"],
)

sedgealgos_cc_test(
    name = "deque_test",
    srcs = ["deque_test.cpp"],
    deps = [
        "deque",
        "resizing_array_deque",
    ],
)


load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "text_buffer",
    hdrs = ["text_buffer.hpp"],
    srcs = ["text_buffer.cpp"],
    deps = [
        "//sedgealgos/data_structures/linked_list:single_linked_list",
        "//sedgealgos/stack:stack",
    ],
)

sedgealgos_cc_test(
    name = "text_buffer_test",
    srcs = ["text_buffer_test.cpp"],
    deps = [
        "text_buffer",
    ],
)


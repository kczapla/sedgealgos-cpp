load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "single_linked_list",
    hdrs = ["single_linked_list.hpp"],
)

sedgealgos_cc_test(
    name = "single_linked_list_test",
    srcs = ["single_linked_list_test.cpp"],
    deps = [
        "single_linked_list",
    ],
)

sedgealgos_cc_library(
    name = "double_linked_list",
    hdrs = ["double_linked_list.hpp"],
)

sedgealgos_cc_test(
    name = "double_linked_list_test",
    srcs = ["double_linked_list_test.cpp"],
    deps = [
        "double_linked_list",
    ],
)

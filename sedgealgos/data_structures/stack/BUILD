load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test_library",
)

sedgealgos_cc_library(
    name = "resizing_array_stack",
    hdrs = [ "resizing_array_stack.hpp" ],
)

sedgealgos_cc_library(
    name = "stack_copy",
    hdrs = ["stack_copy.hpp"],
)

sedgealgos_cc_test_library(
    name = "stack_test",
    hdrs = ["stack_test.hpp"],
    deps = [
        "stack_copy",
        "stack",
        "//sedgealgos/data_structures/linked_list:single_linked_list",
    ]
)

sedgealgos_cc_test(
    name = "resizing_array_stack_test",
    srcs = ["resizing_array_stack_test.cpp"],
    deps = [
        "stack_test",
        "resizing_array_stack"
    ],
)

sedgealgos_cc_test(
    name = "linked_list_stack_test",
    srcs = ["linked_list_stack_test.cpp"],
    deps = [
        "stack_test",
    ],
)

sedgealgos_cc_library(
    name = "stack",
    hdrs = ["stack.hpp"],
)

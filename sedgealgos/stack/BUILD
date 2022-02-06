load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "resizing_array_stack",
    hdrs = [ "resizing_array_stack.hpp" ],
)

sedgealgos_cc_test(
    name = "resizing_array_stack_test",
    srcs = ["resizing_array_stack_test.cpp"],
    deps = ["resizing_array_stack"],
)

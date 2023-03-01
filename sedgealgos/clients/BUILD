load(
   "//bazel:sedgealgos_build_system.bzl",
   "sedgealgos_cc_test",
   "sedgealgos_cc_binary",
   "sedgealgos_cc_library",
)

sedgealgos_cc_binary(
    name = "parantheses",
    srcs = ["parantheses.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
        "//sedgealgos/stack:resizing_array_stack"
    ]
)

sedgealgos_cc_binary(
    name = "twosum",
    srcs = ["twosum.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
    ],
)

sedgealgos_cc_binary(
    name = "evaluate",
    srcs = ["evaluate.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
        "//sedgealgos/stack:resizing_array_stack"
    ]
)

sedgealgos_cc_library(
    name = "fill_left_parentheses",
    hdrs = ["fill_left_parentheses.hpp"],
    srcs = ["fill_left_parentheses.cpp"],
    deps = [
        "//sedgealgos/stack:linked_list_stack",
    ],
)

sedgealgos_cc_test(
    name = "fill_left_parentheses_test",
    srcs = ["fill_left_parentheses_test.cpp"],
    deps = [
        "fill_left_parentheses",
    ],
)

sedgealgos_cc_library(
    name = "infix_to_postfix_converter",
    hdrs = ["infix_to_postfix_converter.h"],
    srcs = ["infix_to_postfix_converter.cc"],
    deps = [
        "//sedgealgos/stack:linked_list_stack",
    ],
)

sedgealgos_cc_test(
    name = "infix_to_postfix_converter_test",
    srcs = ["infix_to_postfix_converter_test.cc"],
    deps = [
        "infix_to_postfix_converter",
    ],
)

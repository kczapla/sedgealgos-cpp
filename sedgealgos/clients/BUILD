load(
   "//bazel:sedgealgos_build_system.bzl",
   "sedgealgos_cc_test",
   "sedgealgos_cc_binary",
   "sedgealgos_cc_library",
)

sedgealgos_cc_binary(
    name = "list_directory",
    srcs = [
        "list_directory.cpp",
    ],
    deps = [
        "//sedgealgos/data_structures/queue:queue",
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
    ],
)

sedgealgos_cc_binary(
    name = "move_to_front",
    srcs = [
        "move_to_front.cpp",
    ],
    deps = [
        "//sedgealgos/data_structures/linked_list:single_linked_list",
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
    ],
)

sedgealgos_cc_binary(
    name = "josephus",
    srcs = [
        "josephus.cpp",
    ],
    deps = [
        "//sedgealgos/data_structures/queue:queue",
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
    ],
)

sedgealgos_cc_binary(
    name = "have_all_the_cards",
    srcs = ["have_all_the_cards.cpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/data_structures/queue:random_queue",
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
    ]
)

sedgealgos_cc_binary(
    name = "random_bag",
    srcs = ["random_bag.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
        "//sedgealgos/data_structures/bag:random_bag",
    ]
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
    name = "are_equal",
    srcs = ["are_equal.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
        "//sedgealgos/algorithms/two_sum:are_equal",
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
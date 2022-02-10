load(
   "//bazel:sedgealgos_build_system.bzl",
   "sedgealgos_cc_binary",
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
    name = "evaluate",
    srcs = ["evaluate.cpp"],
    deps = [
        "//sedgealgos/io:in",
        "//sedgealgos/io:std_out",
        "//sedgealgos/stack:resizing_array_stack"
    ]
)

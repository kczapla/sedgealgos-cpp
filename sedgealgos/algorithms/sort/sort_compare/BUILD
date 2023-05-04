load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_binary",
    "sedgealgos_cc_test",
)

sedgealgos_cc_binary(
    name = "sort_compare",
    srcs = ["sort_compare.cpp"],
    deps = [
        "//sedgealgos/io:std_out",
        "//sedgealgos/data_structures/array:array",
    ],
)

load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

cc_binary(
    name = "random_connections",
    srcs = ["ex1516.cpp"],
    deps = [
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
        "//sedgealgos/algorithms/union_find:quick_union_union_find_with_weights"
    ],
)

cc_binary(
    name = "double_test_for_erdos_renyieg",
    srcs = ["ex1522.cpp"],
    deps = [
        "//sedgealgos/io:std_out",
        "//sedgealgos/random:std_random",
        "//sedgealgos/algorithms/union_find:quick_find_union_find",
        "//sedgealgos/algorithms/union_find:quick_union_union_find",
        "//sedgealgos/algorithms/union_find:quick_union_union_find_with_weights",
    ],
)

load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_binary",
    "sedgealgos_cc_test",
)

sedgealgos_cc_binary(
    name = "sort_compare",
    srcs = ["sort_compare.cpp"],
    deps = [
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort",
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/io:std_out",
        "//sedgealgos/time/stopwatch:stopwatch",
    ],
)

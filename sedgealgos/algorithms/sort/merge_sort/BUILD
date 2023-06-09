load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "merge_sort",
    hdrs = [
        "merge_sort.hpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/sort:callbacks",
    ],
)

sedgealgos_cc_test(
    name = "merge_sort_test",
    srcs = [
        "merge_sort_test.cpp",
    ],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/algorithms/sort/sort:callbacks_mock",
        "//sedgealgos/algorithms/sort/insertion_sort:insertion_sort",
        "//sedgealgos/algorithms/sort/merge_sort/merge:merge",
        "//sedgealgos/algorithms/sort/merge_sort/merge:faster_merge",
        "//sedgealgos/algorithms/sort/merge_sort/merge:no_copy_merge",
        "//sedgealgos/algorithms/sort/merge_sort/top_down:merge_sort",
        "//sedgealgos/algorithms/sort/merge_sort/improved_top_down:merge_sort",
        "//sedgealgos/algorithms/sort/merge_sort/bottom_up:sort",
    ],
)
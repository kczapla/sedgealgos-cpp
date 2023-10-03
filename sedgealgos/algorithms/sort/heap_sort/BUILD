load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "heap_sort",
    hdrs = [
        "heap_sort.hpp",
    ],
)

sedgealgos_cc_test(
    name = "heap_sort_test",
    srcs = [
        "heap_sort_test.cpp",
    ],
    deps = [
        "//sedgealgos/algorithms/sort/heap_sort:heap_sort",
        "//sedgealgos/data_structures/array:array",
    ],
)

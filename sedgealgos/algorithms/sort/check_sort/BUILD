load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "check_sort",
    hdrs = ["check_sort.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/data_structures/hash_map:hash_map",

    ],
)

sedgealgos_cc_test(
    name = "check_sort_test",
    srcs = ["check_sort_test.cpp"],
    deps = [
        "check_sort",
    ],
)
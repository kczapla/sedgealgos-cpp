load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "quick_find_union_find",
    hdrs = ["quick_find_union_find.hpp"],
    srcs = ["quick_find_union_find.cpp"],
)

sedgealgos_cc_library(
    name = "quick_union_union_find",
    hdrs = ["quick_union_union_find.hpp"],
    srcs = ["quick_union_union_find.cpp"],
)

sedgealgos_cc_library(
    name = "quick_union_union_find_with_compressed_paths",
    hdrs = ["quick_union_union_find_with_compressed_paths.hpp"],
    srcs = ["quick_union_union_find_with_compressed_paths.cpp"],
)

sedgealgos_cc_library(
    name = "quick_union_union_find_with_weights",
    hdrs = ["quick_union_union_find_with_weights.hpp"],
    srcs = ["quick_union_union_find_with_weights.cpp"],
)

sedgealgos_cc_test(
    name = "union_find_test",
    srcs = ["union_find_test.cc"],
    deps = [
        "quick_find_union_find",
        "quick_union_union_find",
        "quick_union_union_find_with_compressed_paths",
        "quick_union_union_find_with_weights",
    ],
)

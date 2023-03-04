load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "binary_search",
    hdrs = ["binary_search.hpp"],
    srcs = ["binary_search.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "binary_search_test",
    srcs = ["binary_search_test.cpp"],
    deps = [
        "binary_search",
    ],
)


load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "ex1418",
    hdrs = ["ex1418.hpp"],
    srcs = ["ex1418.cpp"],
    deps = [
        "//sedgealgos/array:array",
    ],
)

sedgealgos_cc_test(
    name = "ex1418_test",
    srcs = ["ex1418_test.cpp"],
    deps = [
        "ex1418",
    ],
)


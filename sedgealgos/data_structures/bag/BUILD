load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "random_bag",
    hdrs = ["random_bag.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/random:std_random",
    ],
)

sedgealgos_cc_test(
    name = "random_bag_test",
    srcs = ["random_bag_test.cpp"],
    deps = [
        "random_bag",
    ],
)


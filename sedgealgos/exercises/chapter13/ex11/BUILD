load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "ex11",
    hdrs = ["ex11.hpp"],
    srcs = ["ex11.cpp"],
    deps = [
        "//sedgealgos/stack:linked_list_stack",
    ],
)

sedgealgos_cc_test(
    name = "ex11_test",
    srcs = ["ex11_test.cpp"],
    deps = [
        "ex11",
    ],
)


load(
    "//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_test",
    "sedgealgos_cc_library",
)

sedgealgos_cc_library(
    name = "transaction",
    hdrs = ["transaction.hpp"],
    srcs = ["transaction.cpp"],
    deps = ["//sedgealgos/date:smart_date"],
)

sedgealgos_cc_test(
    name = "transaction_test",
    srcs = ["transaction_test.cpp"],
    deps = [":transaction"],
)

load("@rules_cc//cc:defs.bzl", "cc_test", "cc_library")


def sedgealgos_cc_test_library(
        name,
        hdrs = [],
        srcs = [],
        deps = []):
    cc_library(
        name = name,
        hdrs = hdrs,
        srcs = srcs,
        deps = deps + ["@com_google_googletest//:gtest_main"],
        visibility = ["//visibility:public"],
    )

def sedgealgos_cc_test(
        name,
        srcs = [],
        deps = []):
    cc_test(
        name = name,
        srcs = srcs,
        deps = deps + ["@com_google_googletest//:gtest_main"],
    )


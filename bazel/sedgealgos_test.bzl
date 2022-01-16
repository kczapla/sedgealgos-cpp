load("@rules_cc//cc:defs.bzl", "cc_test")

def sedgealgos_cc_test(
        name,
        srcs = [],
        deps = []):
    cc_test(
        name = name,
        srcs = srcs,
        deps = deps + ["@com_google_googletest//:gtest_main"],
    )


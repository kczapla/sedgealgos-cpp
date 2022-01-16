load("@rules_cc//cc:defs.bzl", "cc_library")

def sedgealgos_cc_library(
        name,
        hdrs = [],
        srcs = [],
        deps = []):
    cc_library(
        name = name,
        hdrs = hdrs,
        srcs = srcs,
        deps = deps,
        visibility = ["//visibility:public"],
    )

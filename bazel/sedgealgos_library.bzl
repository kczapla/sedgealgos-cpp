load(
    "@rules_cc//cc:defs.bzl",
    "cc_binary",
    "cc_library"
)

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

def sedgealgos_cc_binary(
        name,
        srcs = [],
        deps = []):
    cc_binary(
        name = name,
        srcs = srcs,
        deps = deps,
        visibility = ["//visibility:public"],
    )

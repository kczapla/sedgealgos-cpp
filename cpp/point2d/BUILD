cc_library(
    name = "point2d",
    hdrs = ["algos/point2d.hpp"],
    srcs = ["algos/point2d.cpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "point2d-test",
    srcs = ["algos/point2d-test.cpp"],
    deps = [
        ":point2d",
        "@com_google_googletest//:gtest_main",
    ],
)

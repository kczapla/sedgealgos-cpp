cc_library(
    name = "point2d",
    hdrs = ["point2d.hpp"],
    srcs = ["point2d.cpp"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "point2d-test",
    srcs = ["point2d-test.cpp"],
    deps = [
        ":point2d",
        "@com_google_googletest//:gtest_main",
    ],
)

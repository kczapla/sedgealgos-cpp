load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "priority_queue",
    hdrs = ["priority_queue.hpp"],
    srcs = ["priority_queue.cpp"],
)

sedgealgos_cc_library(
    name = "binary_heap_priority_queue",
    hdrs = ["binary_heap_priority_queue.hpp"],
    deps = [
	"//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_test(
    name = "priority_queue_test",
    srcs = ["priority_queue_test.cpp"],
    deps = [
	"//sedgealgos/data_structures/array:array",
	"//sedgealgos/data_structures/priority_queue:binary_heap_priority_queue",
    ],
)


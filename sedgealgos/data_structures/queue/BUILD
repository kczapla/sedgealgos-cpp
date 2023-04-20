load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "resizing_array_queue",
    hdrs = ["resizing_array_queue.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "queue",
    hdrs = ["queue.hpp"],
)

sedgealgos_cc_library(
    name = "cycling_linked_list_queue",
    hdrs = ["cycling_linked_list_queue.hpp"],
)

sedgealgos_cc_test(
    name = "queue_test",
    srcs = ["queue_test.cpp"],
    deps = [
        "queue",
        "resizing_array_queue",
        "cycling_linked_list_queue",
    ],
)

sedgealgos_cc_library(
    name = "random_queue",
    hdrs = ["random_queue.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
        "//sedgealgos/data_structures/linked_list:single_linked_list",
        "//sedgealgos/stack:stack",
        "//sedgealgos/random:std_random",
    ],
)

sedgealgos_cc_test(
    name = "random_queue_test",
    srcs = ["random_queue_test.cpp"],
    deps = [
        "random_queue",
        "//sedgealgos/random:std_random",
    ],
)

sedgealgos_cc_library(
    name = "resizing_array_generalized_queue",
    hdrs = ["resizing_array_generalized_queue.hpp"],
    deps = [
        "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "linked_list_generalized_queue",
    hdrs = ["linked_list_generalized_queue.hpp"],
    deps = [
        "//sedgealgos/data_structures/linked_list:single_linked_list",
    ],
)

sedgealgos_cc_test(
    name = "generalized_queue_test",
    srcs = ["generalized_queue_test.cpp"],
    deps = [
        "linked_list_generalized_queue",
        "resizing_array_generalized_queue",
    ],
)

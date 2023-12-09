load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
)

sedgealgos_cc_library(
    name = "sequential_search_symbol_table",
    hdrs = ["sequential_search_symbol_table.hpp"],
    deps = [
	    "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "ordered_binary_search_symbol_table",
    hdrs = ["ordered_binary_search_symbol_table.hpp"],
    deps = [
	    "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_library(
    name = "binary_search_tree",
    hdrs = ["binary_search_tree.hpp"],
    deps = [
	    "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_test(
    name = "symbol_table_test",
    srcs = ["symbol_table_test.cpp"],
    deps = [
	    "ordered_binary_search_symbol_table",
	    "sequential_search_symbol_table",
	    "binary_search_tree",
    ],
)


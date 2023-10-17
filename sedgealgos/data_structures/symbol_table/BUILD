load(
    "@sedgealgos-cpp//bazel:sedgealgos_build_system.bzl",
    "sedgealgos_cc_library",
    "sedgealgos_cc_test",
    "sedgealgos_cc_test_library",
)

sedgealgos_cc_library(
    name = "sequential_search_symbol_table",
    hdrs = ["sequential_search_symbol_table.hpp"],
    deps = [
	    "//sedgealgos/data_structures/array:array",
    ],
)

sedgealgos_cc_test(
    name = "sequential_search_symbol_table_test",
    srcs = ["sequential_search_symbol_table_test.cpp"],
    deps = [
	    "sequential_search_symbol_table",
	    "symbol_table_test",
    ],
)

sedgealgos_cc_test_library(
    name = "symbol_table_test",
    hdrs = ["symbol_table_test.hpp"],
)


load(
    ":sedgealgos_test.bzl",
    _sedgealgos_cc_test = "sedgealgos_cc_test",
)

load(
    ":sedgealgos_library.bzl",
    _sedgealgos_cc_library = "sedgealgos_cc_library",
)

load(
    ":sedgealgos_library.bzl",
    _sedgealgos_cc_binary = "sedgealgos_cc_binary",
)

sedgealgos_cc_test = _sedgealgos_cc_test
sedgealgos_cc_binary = _sedgealgos_cc_binary
sedgealgos_cc_library = _sedgealgos_cc_library

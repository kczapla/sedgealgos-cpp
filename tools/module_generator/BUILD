sh_binary(
    name = "module_generator",
    srcs = ["module_generator.sh"],
)

sh_test(
    name = "module_generator_test",
    srcs = ["module_generator_test.sh"],
    data = [
        ":module_generator",
    ],
    args = [
        "$(location :module_generator)",
    ],
)


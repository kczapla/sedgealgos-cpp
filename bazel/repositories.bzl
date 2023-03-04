load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def sedgealgos_cpp_repositories():
    git_repository(
        name="com_google_googletest",
        branch="main",
        remote="https://github.com/google/googletest"
    )

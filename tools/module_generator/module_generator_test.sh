#!/bin/bash

set -e


mkdir test_workspace && cd test_workspace/

echo "
load(\"@bazel_tools//tools/build_defs/repo:git.bzl\", \"git_repository\")

git_repository(
    name = \"sedgealgos-cpp\",
    branch = \"master\",
    remote = \"https://github.com/kczapla/sedgealgos-cpp\",
)

load(\"@sedgealgos-cpp//bazel:repositories.bzl\", \"sedgealgos_cpp_repositories\")

sedgealgos_cpp_repositories()
" > WORKSPACE

module_generator_path=$1
../$module_generator_path -n test/module

bazel test --cxxopt=-std=c++20 //test/module:module_test

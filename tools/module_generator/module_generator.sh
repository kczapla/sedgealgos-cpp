#!/bin/bash

while getopts d:n: flag
do
    case "${flag}" in
        n) name=${OPTARG};;
    esac
done

mkdir -p $name

module_path="$name"
cpp_namespace=`echo $module_path | sed -r 's/[\/]/::/g'`
module_name=`basename ${module_path}`

if [[ "$module_name" == *"_"* ]]; then
    class_name=`echo ${module_name} | sed 's/\(^[a-z]\)\(.*\)\(_\)\([a-z]\)\(.*\)/\u\1\2\u\4\5/g'`
else
class_name=`echo ${module_name} | sed 's/\(.\)\(.*\)/\u\1\2/g'`
fi

echo $module_path
echo $cpp_namespace
echo $class_name

echo "load(
    \"//bazel:sedgealgos_build_system.bzl\",
    \"sedgealgos_cc_library\",
    \"sedgealgos_cc_test\",
)

sedgealgos_cc_library(
    name = \"$module_name\",
    hdrs = [\"$module_name.hpp\"],
    srcs = [\"$module_name.cpp\"],
)

sedgealgos_cc_test(
    name = \"${module_name}_test\",
    srcs = [\"${module_name}_test.cpp\"],
    deps = [
        \"${module_name}\",
    ],
)
" > "${name}/BUILD"

echo "#pragma once

namespace $cpp_namespace {
class $class_name {
};
}
" > "${module_path}/${module_name}.hpp"

echo "#include \"${module_path}/${module_name}.hpp\"
namespace $cpp_namespace {
}
" > "${module_path}/${module_name}.cpp"

echo "#include \"${module_path}/${module_name}.hpp\"

#include <gtest/gtest.h>

namespace {
TEST(${class_name}Test, TestCase1) {
}
}
" > "${module_path}/${module_name}_test.cpp"

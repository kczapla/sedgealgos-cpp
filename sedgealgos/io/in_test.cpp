#include "sedgealgos/io/in.hpp"

#include <string>
#include <fstream>
#include <filesystem>

#include <gtest/gtest.h>

namespace {
    using namespace ::testing;
    using namespace sedgealgos::io;

    class InTest : public Test {
    protected:
        void SetUp() override {
            std::ofstream ef{};

            std::ofstream fwi{file_with_ints};
            fwi << "1 2 3 4 5 6 7";

            std::ofstream fwd{file_with_doubles};
            fwd << "1.1 2.2 3.3 4.4";
        }

        void TearDown() override {
            std::filesystem::remove(empty_file);
            std::filesystem::remove(file_with_ints);
            std::filesystem::remove(file_with_doubles);
        }
    
        std::filesystem::path empty_file{std::filesystem::temp_directory_path() / "empty_file.txt"};
        std::filesystem::path file_with_ints{std::filesystem::temp_directory_path() / "file_with_ints.txt"};
        std::filesystem::path file_with_doubles{std::filesystem::temp_directory_path() / "file_with_doubles.txt"};

    };

    TEST_F(InTest, ReturnsTrueIfFileHasNotData) {
       In in{empty_file.string()};
       EXPECT_TRUE(in.is_empty());
    }

    TEST_F(InTest, ReturnsFalseIfFileHasData) {
       In in{file_with_ints.string()};
       EXPECT_FALSE(in.is_empty());
    }
}

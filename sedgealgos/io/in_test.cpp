#include "sedgealgos/io/in.hpp"

#include <string>
#include <fstream>
#include <filesystem>

#include <gmock/gmock.h>

namespace {
    using namespace ::testing;
    using namespace sedgealgos::io;

    class InTest : public Test {
    protected:
        void SetUp() override {
            std::ofstream empty_file_in{empty_file};

            std::ofstream fwi{file_with_ints, std::ofstream::out};
            fwi << "1 2 3 4 5 6 7";
            fwi.close();

            std::ofstream fwd{file_with_doubles, std::ofstream::out};
            fwd << "1.1 2.2 3.3 4.4";
            fwd.close();
        }

        void TearDown() override {
            std::filesystem::remove(empty_file);
            std::filesystem::remove(file_with_ints);
            std::filesystem::remove(file_with_doubles);
        }

        std::vector<int> get_ints(In& in) {
           std::vector<int> ints{};
           while(!in.is_empty()) {
              ints.push_back(in.readInt());
           }
           return ints;
        }

        std::vector<double> get_doubles(In& in) {
           std::vector<double> doubles{};
           while(!in.is_empty()) {
              doubles.push_back(in.readDouble());
           }
           return doubles;
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

    TEST_F(InTest, ReturnsIntsFromFileWithSpaceSeparatedInts) {
       In in{file_with_ints};
       EXPECT_THAT(get_ints(in), ElementsAre(1, 2, 3, 4, 5, 6, 7));
    }

    TEST_F(InTest, ReturnsIntsFromFileWithSpaceSeparatedDoubles) {
       GTEST_SKIP();
       In in{file_with_doubles};
       EXPECT_THAT(get_ints(in), ElementsAre(1, 2, 3, 4));
    }

    TEST_F(InTest, ReturnsDoublesFromFileWithSpaceSeparatedDoubles) {
       In in{file_with_doubles};
       EXPECT_THAT(get_doubles(in), ElementsAre(1.1, 2.2, 3.3, 4.4));
    }

    TEST_F(InTest, ReadDoubleThrowsExceptionWhenReadingFromEmptyStream) {
        In in{file_with_doubles};
        [[ maybe_unused ]] auto doubles{get_doubles(in)};
        EXPECT_THROW({[[ maybe_unused ]] auto d{in.readDouble()};}, InException);
    }

    TEST_F(InTest, ReadIntThrowsExceptionWhenReadingFromEmptyStream) {
        In in{file_with_ints};
        [[ maybe_unused ]] auto ints{get_ints(in)};
        EXPECT_THROW({[[ maybe_unused ]] auto i{in.readInt()};}, InException);
    }
}

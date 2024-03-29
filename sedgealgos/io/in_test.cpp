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

            std::ofstream fwni{file_with_new_line_ints, std::ofstream::out};
            fwni << "1\n2\n3\n4\n5\n6\n7";
            fwni.close();

            std::ofstream fwd{file_with_doubles, std::ofstream::out};
            fwd << "1.1 2.2 3.3 4.4";
            fwd.close();

            std::ofstream fwc{file_with_chars, std::ofstream::out};
            fwc << "a b c 1 d e f gh";
            fwc.close();

	    std::ofstream fws{file_with_strings, std::ofstream::out};
	    fws << "Lorem ipsum dolor sit amet,\nconsectetur adipiscing elit,\n";
	    fws.close();
        }

        void TearDown() override {
            std::filesystem::remove(empty_file);
            std::filesystem::remove(file_with_ints);
            std::filesystem::remove(file_with_new_line_ints);
            std::filesystem::remove(file_with_doubles);
            std::filesystem::remove(file_with_chars);
            std::filesystem::remove(file_with_strings);
        }

        std::vector<int> get_ints(In& in) {
           std::vector<int> ints{};
           while(!in.is_empty()) {
              ints.push_back(in.read_int());
           }
           return ints;
        }

        std::vector<double> get_doubles(In& in) {
           std::vector<double> doubles{};
           while(!in.is_empty()) {
              doubles.push_back(in.read_double());
           }
           return doubles;
        }

        std::vector<char> get_chars(In& in) {
           std::vector<char> chars{};
           while(!in.is_empty()) {
              chars.push_back(in.read_char());
           }
           return chars;
        }
    
        std::filesystem::path empty_file{std::filesystem::temp_directory_path() / "empty_file.txt"};
        std::filesystem::path file_with_ints{std::filesystem::temp_directory_path() / "file_with_ints.txt"};
        std::filesystem::path file_with_new_line_ints{std::filesystem::temp_directory_path() / "file_with_new_line_ints.txt"};
        std::filesystem::path file_with_doubles{std::filesystem::temp_directory_path() / "file_with_doubles.txt"};
        std::filesystem::path file_with_chars{std::filesystem::temp_directory_path() / "file_with_chars.txt"};
        std::filesystem::path file_with_strings{std::filesystem::temp_directory_path() / "file_with_strings.txt"};
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

    TEST_F(InTest, ReturnChars) {
       In in{file_with_chars};
       EXPECT_THAT(get_chars(in), ElementsAre('a', 'b', 'c', '1', 'd', 'e', 'f', 'g', 'h'));
    }

    TEST_F(InTest, ReadDoubleThrowsExceptionWhenReadingFromEmptyStream) {
        In in{file_with_doubles};
        [[ maybe_unused ]] auto doubles{get_doubles(in)};
        EXPECT_THROW({[[ maybe_unused ]] auto d{in.read_double()};}, InException);
    }

    TEST_F(InTest, ReadIntThrowsExceptionWhenReadingFromEmptyStream) {
        In in{file_with_ints};
        [[ maybe_unused ]] auto ints{get_ints(in)};
        EXPECT_THROW({[[ maybe_unused ]] auto i{in.read_int()};}, InException);
    }

    TEST_F(InTest, ReadCharThrowsExceptionWhenReadingFromEmptyStream) {
        In in{file_with_chars};
        [[ maybe_unused ]] auto ints{get_chars(in)};
        EXPECT_THROW({[[ maybe_unused ]] auto i{in.read_char()};}, InException);
    }

TEST_F(InTest, ReadsAll) {
    In in{file_with_ints};
    EXPECT_EQ(in.reads_all(), "1 2 3 4 5 6 7");
}

TEST_F(InTest, ReadInts) {
    EXPECT_THAT(read_ints(file_with_ints), ElementsAre(1, 2, 3, 4, 5, 6, 7));
}

TEST_F(InTest, ReadsIntsIntoArray) {
    In in{file_with_ints};
    EXPECT_THAT(in.read_ints(), ElementsAre(1, 2, 3, 4, 5, 6, 7));
}

TEST_F(InTest, ReadStringReturnsStringsSeparatedByWhiteSpaces) {
    In in{file_with_strings};
    EXPECT_THAT(in.read_strings(), ElementsAre("Lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit,"));
}
}

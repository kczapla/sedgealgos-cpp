#include "sedgealgos/io/std_out.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <filesystem>

#include <gmock/gmock.h>

namespace {
using namespace ::testing;
using namespace ::sedgealgos::io;

class StdOutTest : public Test {
protected:

    using Lines = std::vector<std::string>;

    void TearDown() override {
        std::filesystem::remove(somefile);
    }

    Lines get_lines_from_somefile() {
        std::ifstream f{somefile};
        Lines lines;
        for (std::string line; std::getline(f, line);) {
            lines.push_back(std::move(line));
        }
        
        return lines;
    }

    std::filesystem::path somefile{std::filesystem::temp_directory_path() / "somefile.txt"};
    StdOut std_out{somefile.string()};
};

TEST_F(StdOutTest, PrintsWithoutNewLine) {
    std_out.print("te");
    std_out.print("st");
    std_out.close();
    
    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("test"));
}

TEST_F(StdOutTest, PrintsLines) {
    std_out.println("test1");
    std_out.println("test2");
    std_out.close();

    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("test1", "test2"));
}

TEST_F(StdOutTest, PrintsNewLine) {
    std_out.print("test1");
    std_out.println();
    std_out.print("test2");
    std_out.close();

    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("test1", "test2"));
}

TEST_F(StdOutTest, PrintsFormattedStringWithString) {
    std_out.printf(
            "%s is formatted %s",
            std::string{"this"},
            std::string{"string"}
    );
    std_out.close();

    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("this is formatted string"));
}

TEST_F(StdOutTest, PrintsFormattedStringWithNumbers) {
    std_out.printf("%d - %d = %d", 1, 2.5, -1.5);
    std_out.close();

    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("1 - 2.500000 = -1.500000"));
}

TEST_F(StdOutTest, PrintsFormattedStringWithStringsAndNumbers) {
    std_out.printf("today is %d/%d/%d, %s", 11, 10, 1905, std::string{"cool"});
    std_out.close();

    EXPECT_THAT(get_lines_from_somefile(), ElementsAre("today is 11/10/1905, cool"));
}
}

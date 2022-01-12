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
        std::copy(
                std::istream_iterator<std::string>(f),
                std::istream_iterator<std::string>(),
                std::back_inserter(lines)
        );
        
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
}

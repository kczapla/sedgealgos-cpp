#pragma once

#include <string>
#include <fstream>
#include <ostream>

namespace sedgealgos::io {
  class StdOut {
  public:
    StdOut();
    StdOut(std::string);

    void print(std::string const&);
    void println();
    void println(std::string const&);

    void close();

  protected:
    std::ofstream ofs;
    std::ostream& os;
  };
}

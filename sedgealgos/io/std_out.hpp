#pragma once

#include "sedgealgos/io/out_exception.hpp"

#include <string>
#include <fstream>
#include <iostream>
#include <ostream>
#include <type_traits>

namespace sedgealgos::io {
  class StdOut {
  public:
    StdOut();
    StdOut(std::string);

    void print(std::string const&);
    void println();
    void println(std::string const&);

    void printf(std::string);

    template <typename T, typename... U>
    void printf(std::string, T, U...);

    void close();

  protected:
    std::ofstream ofs;
    std::ostream& os;
  };


  template <typename T, typename... U>
  void StdOut::printf(std::string s, T t, U... u) {
      auto const pos{s.find_first_of('%')};

      this->print(s.substr(0, pos));

      auto const type{s[pos + 1]};
      switch(type) {
          case 's':
              if constexpr (std::is_same_v<T, std::string>) {
                  this->print(t);
              }
              break;
          case 'd':
              if constexpr (std::is_arithmetic_v<T>) {
                  this->print(std::to_string(t));
              }
              break;
          default:
              throw OutException{"unknow format token"};
      }

      this->printf(s.substr(pos + 2), u...);
  }
}

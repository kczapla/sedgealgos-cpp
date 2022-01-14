#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/date/date_exception.hpp"

#include <string>

namespace sedgealgos::date {

bool is_leap_year(int const y) {
  auto year_is_leap_year{false};
  year_is_leap_year |= (y % 4 == 0) && (y % 100 != 0);
  year_is_leap_year |= y % 400 == 0;

  return year_is_leap_year;
}

void onFebruary(int m) {
    
}

SmartDate::SmartDate(int m, int d, int y) : m_{m}, d_{d}, y_{y} {
   if (m_ == 2) {
       if (!is_leap_year(y_)) {
           if (28 < d_) {
             throw DateException{"February has maximum 28 days"};
           }
       }
       if (29 < d_) {
           throw DateException{"February has maximum 29 days on leap year"};
       }
   }
}

int SmartDate::month() const {
    return m_;
}

int SmartDate::day() const {
    return d_;
}

int SmartDate::year() const {
    return y_;
}
}

#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/date/date_exception.hpp"

#include <cmath>
#include <string>
#include <sstream>

namespace {
    sedgealgos::date::SmartDate MONDAY_DATE{6, 15, 1992};

    bool is_leap_year(int const y) {
        auto year_is_leap_year{false};
        year_is_leap_year |= (y % 4 == 0) && (y % 100 != 0);
        year_is_leap_year |= y % 400 == 0;
    
        return year_is_leap_year;
    }

    std::string convert_weekday_no_to_string(int i) {
        switch(i) {
            case 0:
                return "Monday";
            case 1:
                return "Tuesday";
            case 2:
                return "Wednesday";
            case 3:
                return "Thursday";
            case 4:
                return "Friday";
            case 5:
                return "Saturday";
            case 6:
                return "Sunday";
            default:
                return "uuu";
        }
    }

    int convert_month_no_to_day_no(int i, int year) {
        switch(i) {
            case 1:
                return 31;
            case 2:
                return is_leap_year(year) ? 29 : 28;
            case 3:
                return 31;
            case 4:
                return 30;
            case 5:
                return 31;

            case 6:
                return 30;
            case 7:
                return 31;
            case 8:
                return 31;
            case 9:
                return 30;
            case 10:
                return 31;
            case 11:
                return 30;
            case 12:
                return 31;
            default:
                return -1;
        }
    }
}

namespace sedgealgos::date {



void onFebruary(int m) {
    
}

SmartDate::SmartDate(int m, int d, int y) : m_{m}, d_{d}, y_{y} {
   if (d_ < 1) {
       throw DateException{"Minimum day number for month is 1"};
   }

   if (m_ < 1 || 12 < m_) {
       throw DateException{"Month number must be in range from 1 to 12"};
   }

   if (m_ == 2) {
       if (!::is_leap_year(y_)) {
           if (28 < d_) {
             throw DateException{"February has maximum 28 days"};
           }
       }
       if (29 < d_) {
           throw DateException{"February has maximum 29 days on leap year"};
       }
   }

   if ((m_ % 2 == 0) && (m_ != 8)) {
       if (30 < d_) {
           throw DateException{"Maximum day number for this month is 30"};
       }
   }

   if (31 < d_) {
       throw DateException{"Maximum day number for this month is 31"};
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

std::string SmartDate::day_of_the_week() const {
    auto days_no{0};
    if (MONDAY_DATE.month() == month() && MONDAY_DATE.year() == year()) {
        days_no = std::abs(day() - MONDAY_DATE.day());
    } else if(MONDAY_DATE.month() < month() && MONDAY_DATE.year() == year()) {
        auto const days_remain_in_monday_month{
            convert_month_no_to_day_no(MONDAY_DATE.month(), MONDAY_DATE.year()) - MONDAY_DATE.day()
        };
        days_no = days_remain_in_monday_month + day();
    }

    auto const weekday_no{days_no % 7};
    return ::convert_weekday_no_to_string(weekday_no);
}

std::string SmartDate::to_string() const {
    std::stringstream ss;
    ss << month() << "/" << day() << "/" << year();

    return ss.str();
}
}

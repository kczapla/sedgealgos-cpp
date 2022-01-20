#include "sedgealgos/date/smart_date.hpp"
#include "sedgealgos/date/date_exception.hpp"

#include <cmath>
#include <string>
#include <vector>
#include <numeric>
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
    if (day() < MONDAY_DATE.day() && MONDAY_DATE.month() == month() && MONDAY_DATE.year() == year()) {
        auto const day_diff{MONDAY_DATE.day() - day()};
        auto const ramaining_days_in_the_start_week{day_diff % 7};
        auto const weekday_no{7 - ramaining_days_in_the_start_week};
        return ::convert_weekday_no_to_string(weekday_no);
    } else if (month() < MONDAY_DATE.month() && MONDAY_DATE.year() == year()) {
        auto const days_passed_in_monday_month{MONDAY_DATE.day()};
        std::vector<int> months_in_between(MONDAY_DATE.month() - month() - 1);
        std::iota(months_in_between.begin(), months_in_between.end(), month() + 1);
        auto const days_passed_in_months_in_between{
            std::accumulate(
                months_in_between.begin(),
                months_in_between.end(), 0,
                [year = year()](auto const& a, auto const& b){return a + ::convert_month_no_to_day_no(b, year);}
            )
        };
        auto const days_passed_in_current_month{::convert_month_no_to_day_no(month(), year()) - day()};
        auto const days{days_passed_in_monday_month + days_passed_in_months_in_between + days_passed_in_current_month};
        auto const ramaining_days_in_the_start_week{days % 7};
        auto const weekday_no{7 - ramaining_days_in_the_start_week};

        return ::convert_weekday_no_to_string(weekday_no);
    } else if (year() < MONDAY_DATE.year()) {
        auto const days_passed_in_monday_month{MONDAY_DATE.day()};
        std::vector<int> months_passed_in_monday_year(MONDAY_DATE.month() - 1);
        std::iota(months_passed_in_monday_year.begin(), months_passed_in_monday_year.end(), 1);
        auto const days_passed_in_monday_year{
            std::accumulate(
                months_passed_in_monday_year.begin(),
                months_passed_in_monday_year.end(), 0,
                [year = MONDAY_DATE.year()](auto const& a, auto const& b) { return a + ::convert_month_no_to_day_no(b, year);}
            )
        };
        std::vector<int> years_in_between(MONDAY_DATE.year() - year() - 1);
        std::iota(years_in_between.begin(), years_in_between.end(), year() + 1);
        auto days_in_year_in_between{0};
        for (auto&& y : years_in_between) {
            std::vector<int> months(12);
            std::iota(months.begin(), months.end(), 1);
            auto days_in_year{0};
            for (auto&& m : months) {
                days_in_year += ::convert_month_no_to_day_no(m, y);
            }
            days_in_year_in_between += days_in_year; 
        }


        std::vector<int> months_passed_in_current_year(12 - month());
        std::iota(months_passed_in_current_year.begin(), months_passed_in_current_year.end(), month() + 1);
        auto const days_in_months_passed_in_current_year{
            std::accumulate(
                months_passed_in_current_year.begin(),
                months_passed_in_current_year.end(),
                0,
                [year = year()](auto const& a, auto const& b) {return a + ::convert_month_no_to_day_no(b, year);}
            )
        };

        auto const days_passed_in_current_month{::convert_month_no_to_day_no(month(), year()) - day()};
        auto const days{days_passed_in_monday_month + days_passed_in_monday_year + days_in_year_in_between + days_in_months_passed_in_current_year + days_passed_in_current_month};

        auto const ramaining_days_in_the_start_week{days % 7};
        auto const weekday_no{7 - ramaining_days_in_the_start_week};

        return ::convert_weekday_no_to_string(weekday_no);
    } else if (MONDAY_DATE.month() == month() && MONDAY_DATE.year() == year()) {
        days_no = std::abs(day() - MONDAY_DATE.day());
    } else if(MONDAY_DATE.month() < month() && MONDAY_DATE.year() == year()) {
        auto const days_remain_in_monday_month{
            convert_month_no_to_day_no(MONDAY_DATE.month(), MONDAY_DATE.year()) - MONDAY_DATE.day()
        };

        std::vector<int> months_in_between(month() - MONDAY_DATE.month() - 1);
        std::iota(months_in_between.begin(), months_in_between.end(), MONDAY_DATE.month() + 1);
        auto const days_between_dates{std::accumulate(
            months_in_between.begin(),
            months_in_between.end(), 0,
            [year = year()](auto const& a, auto const& b){ return a + ::convert_month_no_to_day_no(b, year); })};

        days_no += days_remain_in_monday_month;
        days_no += days_between_dates;
        days_no += day();
    } else if(MONDAY_DATE.year() < year()) {
        auto const days_remain_in_monday_month{
            convert_month_no_to_day_no(MONDAY_DATE.month(), MONDAY_DATE.year()) - MONDAY_DATE.day()
        };
        std::vector<int> months_in_monday_year(12 - MONDAY_DATE.month());
        std::iota(months_in_monday_year.begin(), months_in_monday_year.end(), MONDAY_DATE.month() + 1);
        auto const days_in_monday_year{
            std::accumulate(
                months_in_monday_year.begin(),
                months_in_monday_year.end(), 0,
                [year = year()](auto const& a, auto const& b){ return a + ::convert_month_no_to_day_no(b, year); }
            )
        };


        std::vector<int> years_between_dates(year() - MONDAY_DATE.year() - 1);
        std::iota(years_between_dates.begin(), years_between_dates.end(), MONDAY_DATE.year() + 1);
        auto days_is_years_between_dates{0};
        for (auto&& year : years_between_dates) {
            std::vector<int> months(12);
            std::iota(months.begin(), months.end(), 1);
            auto const days_in_year{std::accumulate(months.begin(), months.end(), 0, [year](auto const& a, auto const& b){return a + ::convert_month_no_to_day_no(b, year);})};
            days_is_years_between_dates += days_in_year;

        }

        std::vector<int> months_in_current_year(month() - 1);
        std::iota(months_in_current_year.begin(), months_in_current_year.end(), 1);
        auto days_in_current_year{std::accumulate(months_in_current_year.begin(), months_in_current_year.end(), 0, [year = year()](auto const& a, auto const& b){ return a + ::convert_month_no_to_day_no(b, year);})};

        days_in_current_year += day();

        days_no += days_remain_in_monday_month + days_in_monday_year + days_is_years_between_dates + days_in_current_year;
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

#pragma once

namespace sedgealgos::algorithms::three_sum::overflow_detection {
bool will_sum_overflow_negatively(int a, int b);
bool will_sum_overflow_positively(int a, int b);
bool will_sum_overflow_negatively(int a, int b, int c);
bool will_sum_overflow_positively(int a, int b, int c);
}

#pragma once

namespace sedgealgos::data_structures::text_buffer {
class TextBuffer {
public:
    using Size = long unsigned int;

    void insert(char c);
    char remove();

    Size size() const;

private:
    Size no_elements{0};
};
}


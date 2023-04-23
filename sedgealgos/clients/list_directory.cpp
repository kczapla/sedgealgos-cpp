#include "sedgealgos/data_structures/queue/queue.hpp"

#include "sedgealgos/io/in.hpp"
#include "sedgealgos/io/std_out.hpp"

#include <filesystem>

using namespace sedgealgos::data_structures::queue;
using namespace sedgealgos::io;

void read_path(Queue<std::filesystem::path>& q, std::filesystem::path p) {
    q.enqueue(p);
    if (std::filesystem::is_directory(p)) {
        for (auto const& dir_entry : std::filesystem::directory_iterator{p}) {
            read_path(q, dir_entry.path());
        }
    }
}

int main(int argc, char** argv) {
    StdOut std_out{};

    if (argc < 2) {
        std_out.println("please provide directory name");
        return 1;
    }

    std::filesystem::path path{argv[1]};

    if (!std::filesystem::is_directory(path)) {
        std_out.println("path is not directory");
        return 1;
    }

    Queue<std::filesystem::path> paths;
    read_path(paths, path);

    std_out.printf("size is %d\n", paths.size());

    while(!paths.is_empty()) {
        std_out.printf("%s\n", paths.dequeue().string());
    }


    return 0;
}

#pragma once
#include "../../scheduler/processer.h"

namespace co {

class Reactor
{
public:
    static Reactor& Select(int fd);

    struct Entry {
        Processer::SuspendEntry suspendEntry_;
        std::shared_ptr<short int> revents_;
        int idx_;

        Entry() {}
        Entry(Processer::SuspendEntry const& suspendEntry,
                std::shared_ptr<short int> const& revents,
                int idx)
            : suspendEntry_(suspendEntry), revents_(revents), idx_(idx)
        {}
    };

    // @returns: 0 or errno
    int Add(int fd, short int pollEvent, Entry const& entry);

    void Run();
};

} // namespace co

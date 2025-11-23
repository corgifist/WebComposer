#pragma once

#ifdef WEBCOMPOSER_LOG_RELEASABLE
    #include <fmt/core.h>
#endif

namespace WebComposer {

struct IReleasable {
    virtual void Release() = 0;
};

class ReleasableDeleter {
public:
    void operator()(IReleasable *releasable) {
        if (releasable) releasable->Release();
#ifdef WEBCOMPOSER_LOG_RELEASABLE
        fmt::println("{} was released", fmt::ptr(releasable));
#endif
    }

    static ReleasableDeleter &Get(); 
private:
    ReleasableDeleter() {}
};

} // namespace WebComposer
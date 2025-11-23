#include "Releasable.h"

namespace WebComposer {

ReleasableDeleter &ReleasableDeleter::Get() {
    static ReleasableDeleter deleter;
    return deleter;
}

} // namespace WebComposer
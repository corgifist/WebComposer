#include "Greet.h"
#include "Platform.h"
#include "Feature.h"

namespace WebComposer {

WEBCOMPOSER_API void Greet(std::string t_name) {
    std::cout << "Hello, " << t_name << "!" << std::endl;
#if ENABLED(TEST)
    std::cout << "Test feature activated" << std::endl;
#endif
}

} // namespace WebComposer
#include "Greet.h"
#include "Platform.h"

namespace WEBCOMPOSER_NAMESPACE {
    WEBCOMPOSER_API void Greet(std::string t_name) {
        std::cout << "Hello, " << t_name << "!" << std::endl;
    }
}
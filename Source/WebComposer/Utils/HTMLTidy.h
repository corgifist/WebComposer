#pragma once

#include "Common.h"
#include <memory>

namespace WebComposer {

class HTMLTidy {
public:
    HTMLTidy();
    ~HTMLTidy();

    HTMLTidy operator=(const HTMLTidy& tidy) = delete;

    bool Parse(const std::string &input);

    std::string GetOutput();
    std::string GetErrorOutput();

private:
    // Pointer to the internal structures of HTMLTidy.
    // For example, if WebComposer::HTMLTidy uses libtidy-html5 under the hood
    // m_data may point to a TidyDoc instance.
    void *m_data;
};

using HTMLTidyPtr = std::unique_ptr<HTMLTidy>;

} // namespace WebComposer
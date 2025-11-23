#pragma once

#include "Common.h"
#include "Releasable.h"
#include "Utils/Releasable.h"

namespace WebComposer {

class HTMLTidy : public IReleasable {
public:
    enum class Flags {
        None = 0, // Empty flag.
        XHTMLOut, // Convert HTML to XHTML.
        HTMLOut, // Convert XHTML to HTML.
        ForceOutput // Return some result from GetOutput() even if converting failed.
    };
    
    HTMLTidy();
    
    bool Parse(std::string_view input);
    bool Tidy();
    bool RunDiagnostics();
    bool SetFlag(Flags flag, bool value);

    std::string GetOutput();
    std::string GetErrorOutput();

    // Release all internal structures.
    void Release() override;

    using Ptr = std::unique_ptr<HTMLTidy, ReleasableDeleter>;

    template<typename ...Args>
    static inline Ptr New(Args &&...args) {
        return Ptr(
            new HTMLTidy(std::forward<Args>(args)...),
            ReleasableDeleter::Get()
        );
    }

private:
    // Pointer to the internal structures of HTMLTidy.
    // For example, if WebComposer::HTMLTidy uses libtidy-html5 under the hood
    // m_data may point to a TidyDoc instance.
    void *m_data;
};

using HTMLTidyPtr = HTMLTidy::Ptr;

} // namespace WebComposer
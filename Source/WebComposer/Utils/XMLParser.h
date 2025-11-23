#pragma once

/*
    XMLParser.h - utilities for reading XML files
*/

#include "Common.h"
#include "Utils/Releasable.h"

namespace WebComposer {

using XMLStartElementHandler = void(void*, const char*, const char**);
using XMLCharacterDataHandler = void(void*, const char*, int);
using XMLEndElementHandler = void(void*, const char*);

/*
    XMLParser - stream-oriented parser
    currently backed by libexpat, but that may change in the future
*/
struct XMLParser : public IReleasable {
public:
    XMLParser();

    void SetUserData(void *data);
    bool Parse(std::string_view input);

    void SetStartElementHandler(XMLStartElementHandler handler);
    void SetCharacterDataHandler(XMLCharacterDataHandler handler);
    void SetEndElementHandler(XMLEndElementHandler handler);

    void Release() override;

    using Ptr = std::unique_ptr<XMLParser, ReleasableDeleter>;

    template<typename ...Args>
    static inline Ptr New(Args &&...args) {
        return Ptr(
            new XMLParser(std::forward<Args...>(args)...),
            ReleasableDeleter::Get()
        );
    }

private:
    // Pointer to the internal structures. (e.g. XMLInternalData)
    void *m_data;
};

} // namespace WebComposer
#include "HTMLTidy.h"
#include "Platform.h"

#include "tidy/tidy.h"
#include "tidy/buffio.h"

namespace WebComposer {

struct HTMLTidyInternalData {
    TidyDoc doc;
    TidyBuffer out, err;
};

#define INTERNAL(PTR) ((HTMLTidyInternalData*) (PTR))

HTMLTidy::HTMLTidy() : m_data(new HTMLTidyInternalData()) {
    auto data = INTERNAL(m_data);
    data->doc = tidyCreate();
    data->out = { 0 };
    data->err = { 0 };
    std::cout << "constructor" << std::endl;
}

HTMLTidy::~HTMLTidy() {
    auto data = INTERNAL(m_data);
    if (data->out.bp) tidyBufFree(&data->out);
    if (data->err.bp) tidyBufFree(&data->err);
    tidyRelease(data->doc);
    delete data;
    m_data = nullptr;
    std::cout << "release" << std::endl;
}

} // namespace WebComposer
#include "HTMLTidy.h"

#include <tidy.h>
#include <tidybuffio.h>
#include <string_view>
#include <tidy/tidyenum.h>

#define INTERNAL(PTR) ((HTMLTidyInternalData*) (PTR))

struct HTMLTidyInternalData {
    TidyDoc doc;
    TidyBuffer out, err;

    HTMLTidyInternalData() {
        this->doc = tidyCreate();
        this->out = { 0 };
        this->err = { 0 };
    }
};
namespace WebComposer {

HTMLTidy::HTMLTidy() : m_data(new HTMLTidyInternalData()) {
    // We don't want libtidy-html5 to clutter our HTML files
    tidyOptSetBool(INTERNAL(m_data)->doc, TidyMark, no); 

    tidySetErrorBuffer(INTERNAL(m_data)->doc, &INTERNAL(m_data)->err);
}

bool HTMLTidy::Parse(std::string_view t_input) {
    std::cout << t_input.data() << std::endl;
    return tidyParseString(INTERNAL(m_data)->doc, t_input.data()) >= 0;
}

bool HTMLTidy::Tidy() {
    return tidyCleanAndRepair(INTERNAL(m_data)->doc) >= 0;
}

bool HTMLTidy::RunDiagnostics() {
    return tidyRunDiagnostics(INTERNAL(m_data)->doc)  <= 1;
}

bool HTMLTidy::SetFlag(Flags t_flag, bool t_value) {
    auto data = INTERNAL(m_data);
    switch (t_flag) {
    case Flags::None:
        return true;
    case Flags::XHTMLOut:
        return tidyOptSetBool(data->doc, TidyXhtmlOut, t_value ? yes : no) >= 0;
    case Flags::HTMLOut:
        return tidyOptSetBool(data->doc, TidyHtmlOut, t_value ? yes : no) >= 0;
    case Flags::ForceOutput:
        return tidyOptSetBool(data->doc, TidyForceOutput, t_value ? yes : no) >= 0;
    }
}

std::string HTMLTidy::GetOutput() {
    auto data = INTERNAL(m_data);
    if (tidySaveBuffer(data->doc, &data->out) < 0) return "";
    return data->out.bp ? (const char*) data->out.bp : "";
}

std::string HTMLTidy::GetErrorOutput() {
    auto data = INTERNAL(m_data);
    return data->err.bp ? (const char*) data->err.bp : "";
}

void HTMLTidy::Release() {
    auto data = INTERNAL(m_data);
    if (data->out.bp) tidyBufFree(&data->out);
    if (data->err.bp) tidyBufFree(&data->err);
    tidyRelease(data->doc);
    delete data;
    m_data = nullptr;
}

} // namespace WebComposer
#include "XMLParser.h"

#include <expat.h>

#define INTERNAL(PTR) ((XMLInternalData*) (PTR))

struct XMLInternalData {
    XML_Parser parser;
};

namespace WebComposer {

XMLParser::XMLParser() : m_data(new XMLInternalData()) {
    auto data = INTERNAL(m_data);
    data->parser = XML_ParserCreate(nullptr);
}

void XMLParser::SetUserData(void *t_data) {
    XML_SetUserData(INTERNAL(m_data)->parser, t_data);
}

bool XMLParser::Parse(std::string_view input) {
    return XML_Parse(INTERNAL(m_data)->parser, input.data(), input.length(), XML_TRUE);
}

void XMLParser::SetStartElementHandler(XMLStartElementHandler t_handler) {
    XML_SetStartElementHandler(INTERNAL(m_data)->parser, t_handler);
}

void XMLParser::SetCharacterDataHandler(XMLCharacterDataHandler t_handler) {
    XML_SetCharacterDataHandler(INTERNAL(m_data)->parser, t_handler);
}

void XMLParser::SetEndElementHandler(XMLEndElementHandler t_handler) {
    XML_SetEndElementHandler(INTERNAL(m_data)->parser, t_handler);
}

void XMLParser::Release() {
    auto data = INTERNAL(m_data);
    XML_ParserFree(data->parser);
}

} // namespace WebComposer
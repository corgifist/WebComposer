#define WEBCOMPOSER_LOG_RELEASABLE
#include "Utils/HTMLTidy.h"
#include "Utils/XMLParser.h"

using namespace WebComposer;

void StartElement(void *t_data, const char *t_name, const char **t_attributes) {
    fmt::println("start element {}", t_name);
}

void CharacterData(void *t_data, const char* t_string, int t_length) {
    fmt::println("{}", std::string(t_string, t_string + t_length));
}

void EndElement(void *t_data, const char *t_name) {
    fmt::println("end element: {}", t_name);
}

int main(int argc, char **argv) { 
    auto html = HTMLTidy::New();
    html->Parse("<title>Hello, WebComposer<title><p>Hello, World!");
    html->Tidy();
    
    auto parser = XMLParser::New();
    parser->SetStartElementHandler(StartElement);
    parser->SetCharacterDataHandler(CharacterData);
    parser->SetEndElementHandler(EndElement);
    parser->Parse(html->GetOutput());
    return 0; 
}
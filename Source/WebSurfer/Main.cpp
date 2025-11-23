#define WEBCOMPOSER_LOG_RELEASABLE
#include "Utils/HTMLTidy.h"

using namespace WebComposer;

int main(int argc, char **argv) { 
    auto html = HTMLTidy::New();
    html->Parse("<title>Hello, WebComposer<title><p>Hello, World!");
    html->Tidy();
    std::cout << html->GetOutput() << std::endl;
    return 0; 
}
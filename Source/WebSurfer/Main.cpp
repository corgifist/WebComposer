#include <iostream>
#include "Greet.h"
#include "Utils/HTMLTidy.h"

int main(int argc, char **argv) {
    auto html = WebComposer::HTMLTidy();
    WebComposer::Greet("WebComposer");
    return 0;
}
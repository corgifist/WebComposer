find_package(unofficial-tidy-html5 CONFIG REQUIRED)

set(WebComposer_Sources
    Greet.cpp
)

set(WebComposer_Headers
    Common.h
    Greet.h
    Platform.h
)

add_subdirectory(Utils)

add_library(WebComposer ${WebComposer_Sources} ${WebComposer_Headers})
target_include_directories(WebComposer PUBLIC .)
target_link_libraries(WebComposer PRIVATE unofficial::tidy-html5::tidy)
target_compile_definitions(WebComposer PUBLIC WEBCOMPOSER_TEST_ENABLED=1)

set_target_properties(
    WebComposer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
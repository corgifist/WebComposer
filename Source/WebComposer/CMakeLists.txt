find_package(unofficial-tidy-html5 CONFIG REQUIRED)
find_package(expat CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

set(WebComposer_Sources
    Greet.cpp
    Utils/HTMLTidy.cpp
    Utils/Releasable.cpp
)

set(WebComposer_Headers
    Common.h
    Greet.h
    Platform.h
)

add_subdirectory(Utils)

add_library(WebComposer ${WebComposer_Sources} ${WebComposer_Headers})
target_include_directories(WebComposer PUBLIC .)
target_link_libraries(WebComposer 
    PUBLIC unofficial::tidy-html5::tidy
    PUBLIC expat::expat
    PUBLIC fmt::fmt-header-only
)
target_compile_definitions(WebComposer PUBLIC WEBCOMPOSER_TEST_ENABLED=1)

set_target_properties(
    WebComposer PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
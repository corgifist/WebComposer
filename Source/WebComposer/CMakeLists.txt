set(WebComposer_Sources
    Greet.cpp
)

set(WebComposer_Headers
    Common.h
    Greet.h
    Platform.h
)

add_library(WebComposer ${WebComposer_Sources} ${WebComposer_Headers})
target_include_directories(WebComposer PUBLIC .)
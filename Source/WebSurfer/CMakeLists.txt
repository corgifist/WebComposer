find_package(unofficial-tidy-html5 CONFIG REQUIRED)
find_package(expat CONFIG REQUIRED)

set(WebSurfer_Sources
    Main.cpp
)

add_executable(WebSurfer ${WebSurfer_Sources})
target_link_libraries(WebSurfer
    PRIVATE WebComposer
)
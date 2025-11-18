set(WebSurfer_Sources
    Main.cpp
)

add_executable(WebSurfer ${WebSurfer_Sources})
target_link_libraries(WebSurfer PRIVATE WebComposer)
#pragma once

/*
    Platform.h - macros for detecting host operating system
*/

#define PLATFORM(NAME) WEBCOMPOSER_PLTFORM_ ## NAME

#ifdef __APPLE__
    #include <TargetConditionals.h>
    #define WEBCOMPOSER_PLATFORM_DARWIN 1
#endif

#ifdef _WIN32
    #define WEBCOMPOSER_PLATFORM_WINDOWS 1
#endif

#ifdef __linux__
    #define WEBCOMPOSER_PLATFORM_LINUX 1
#endif

#ifdef WEBCOMPOSER_PLATFORM_DARWIN
    #ifdef TARGET_OS_MAC
        #define WEBCOMPOSER_PLATFORM_MACOS 1
    #endif
#endif

#ifndef WEBCOMPOSER_PLATFORM_WINDOWS
    #define WEBCOMPOSER_PLATFORM_WINDOWS 0
#endif

#ifndef WEBCOMPOSER_PLATFORM_LINUX
    #define WEBCOMPOSER_PLATFORM_LINUX 0
#endif

#ifndef WEBCOMPOSER_PLATFORM_DARWIN
    #define WEBCOMPOSER_PLATFORM_DARWIN 0
#endif

#ifndef WEBCOMPOSER_PLATFORM_MACOS
    #define WEBCOMPOSER_PLATFORM_MACOS 0
#endif

#ifdef __cplusplus
    #define WEBCOMPOSER_EXTERN_C extern "C"
#else
    #define WEBCOMPOSER_EXTERN_C
#endif

#if PLATFORM(WINDOWS)
    #ifdef WEBCOMPOSER_EXPORT_SYMBOLS
        #define WEBCOMPOSER_API __declspec(dllexport)
    #else
        #define WEBCOMPOSER_API __declspec(dllimport)
    #endif
#else
    #define WEBCOMPOSER_API
#endif

#define WEBCOMPOSER_C_API WEBCOMPOSER_EXTERN_C WEBCOMPOSER_API
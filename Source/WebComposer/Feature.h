#pragma once

/*
    Feature.h - provides info about available features
*/

#define ENABLED(NAME) WEBCOMPOSER_ ## NAME ## _ENABLED

#ifndef WEBCOMPOSER_TEST_ENABLED
    #define WEBCOMPOSER_TEST_ENABLED 0
#endif
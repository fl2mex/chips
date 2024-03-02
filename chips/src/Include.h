#pragma once

#include "SDL.h"

#include <iostream>
#include <cmath>

// Macros
#define DEBUG_ON true
#define DEBUG_OFF false

// Debug Logger helper func
#define log(str) \
    do { \
        if (isDebug) { \
            std::cout << str << "\n"; \
        } \
    } while(0)
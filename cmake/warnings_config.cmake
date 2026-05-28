# ==========================================
# @file /cmake/warnings_config.cmake
# Compiler warnings configuration
# ==========================================

message(STATUS "")
message(STATUS ">>>>> CONFIGURING COMPILER WARNINGS <<<<<")

if(MSVC)
    foreach(flags
            CMAKE_C_FLAGS
            CMAKE_CXX_FLAGS
            CMAKE_C_FLAGS_DEBUG
            CMAKE_CXX_FLAGS_DEBUG
            CMAKE_C_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_RELEASE
            CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS_MINSIZEREL
            CMAKE_CXX_FLAGS_MINSIZEREL)
        string(REGEX REPLACE "/W[0-4]" "" ${flags} "${${flags}}")
    endforeach()

    set(WARN_FLAGS
        /W4
        /permissive-
    )
else()
    set(WARN_FLAGS
        -Wall
        -Wextra
        -Wswitch-enum
    )
endif()

# ---- Включение pedantic-предупреждения ----
option(ENABLE_PEDANTIC_WARNINGS "Enable pedantic compiler warnings" ON)
# GCC < 4.8 не поддерживает -Wpedantic, используется -pedantic
if(ENABLE_PEDANTIC_WARNINGS AND NOT MSVC)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
            list(APPEND WARN_FLAGS -pedantic)
        else()
            list(APPEND WARN_FLAGS -Wpedantic)
        endif()
    endif()
endif()

message(STATUS "  Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Warnings: ${WARN_FLAGS}")

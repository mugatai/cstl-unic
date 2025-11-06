cmake_minimum_required(VERSION 3.25)

project(unicode_handler VERSION 0.1.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build Shared Library" ON)

add_library(unicode_handler SHARED src/create_uchar.c)
add_library(cstl::unic ALIAS unicode_handler)

target_include_directories(unicode_handler
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

set_target_properties(unicode_handler PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 99
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
)

if(WIN32 AND BUILD_SHARED_LIBS)
    set_target_properties(unicode_handler PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
    )
endif()

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(unicode_handler PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(unicode_handler PRIVATE /W4)
endif()

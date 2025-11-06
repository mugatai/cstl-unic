cmake_minimum_required(VERSION 3.25)

project(unicode_handler VERSION 0.1.0 LANGUAGES C)

option(BUILD_SHARED_LIBS "Build Shared Library" ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_library(unicode_handler src/create_uchar.c)
add_library(cstl::unic ALIAS unicode_handler)

add_executable(unic
    src/main.c
    src/create_uchar.c
)

target_include_directories(unicode_handler
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_include_directories(unic PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(unicode_handler PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 0
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 99
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS NO
    OUTPUT_NAME "cstl_unic"
)

set_target_properties(unic PROPERTIES
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
    target_compile_options(unicode_handler PRIVATE -Wall -Wextra -Wpedantic -Werror)
    target_compile_options(unic PRIVATE -Wall -Wextra -Wpedantic -Werror)
elseif(MSVC)
    target_compile_options(unicode_handler PRIVATE /W4)
    target_compile_options(unic PRIVATE /W4)
endif()

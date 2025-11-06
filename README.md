
░█─░█ █▀▀▄ ─▀─ █▀▀ █▀▀█ █▀▀▄ █▀▀ 　 ░█─░█ █▀▀█ █▀▀▄ █▀▀▄ █── █▀▀ █▀▀█ 
░█─░█ █──█ ▀█▀ █── █──█ █──█ █▀▀ 　 ░█▀▀█ █▄▄█ █──█ █──█ █── █▀▀ █▄▄▀ 
─▀▄▄▀ ▀──▀ ▀▀▀ ▀▀▀ ▀▀▀▀ ▀▀▀─ ▀▀▀ 　 ░█─░█ ▀──▀ ▀──▀ ▀▀▀─ ▀▀▀ ▀▀▀ ▀─▀▀

<svg role="img" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg"><title>C</title><path d="M16.5921 9.1962s-.354-3.298-3.627-3.39c-3.2741-.09-4.9552 2.474-4.9552 6.14 0 3.6651 1.858 6.5972 5.0451 6.5972 3.184 0 3.5381-3.665 3.5381-3.665l6.1041.365s.36 3.31-2.196 5.836c-2.552 2.5241-5.6901 2.9371-7.8762 2.9201-2.19-.017-5.2261.034-8.1602-2.97-2.938-3.0101-3.436-5.9302-3.436-8.8002 0-2.8701.556-6.6702 4.047-9.5502C7.444.72 9.849 0 12.254 0c10.0422 0 10.7172 9.2602 10.7172 9.2602z"/></svg>

## A unicode handing library written in c99

### Seamlessly read/write/encode/decode unicode characters

### Usage instructions

---

### CMake users ::

#### Option 1 :: Using CMake-Fetchcontent (Recommended)

#### Step 1 : Add this to your CMakeLists.txt

```cmake

    include(FetchContent)

    FetchContent_Declare(
        unicode_handler
        GIT_REPOSITORY https://github.com/mugatai/cstl-unic.git
        GIT_TAG        v0.1.0
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE  # Shows download progress
    )

    FetchContent_MakeAvailable(unicode_handler)

    # your targets

    target_link_libraries(<your target name> PRIVATE cstl::unic)

```


#### Option 2 :: Using git-submodule
    
#### Step 1: create a vendor dir if not already there

```bash
    
    # Clone or copy into <project root>/vendor/
    mkdir -p vendor
    cd vendor
    git clone https://github.com/mugatai/cstl-unic.git cstl_unic

    cd ..

    # Build
    cmake -B build
    cmake --build build

    # Run
    ./build/myapp
```

Make sure the CmakeLists.txt file of your project is on same directory level as vendor


    #### Step 2: Link to your targets
    
```cmake

    add_subdirectory(vendor/cstl_unic)

    # Declare your targets

    target_link_libraries(<your target name> PRIVATE cstl::unic)
```



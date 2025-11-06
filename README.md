
░▒█░▒█░▒█▄░▒█░▀█▀░▒█▀▀▄░▒█▀▀▀█░▒█▀▀▄░▒█▀▀▀░░░▒█░▒█░█▀▀▄░▒█▄░▒█░▒█▀▀▄░▒█░░░░▒█▀▀▀░▒█▀▀▄
░▒█░▒█░▒█▒█▒█░▒█░░▒█░░░░▒█░░▒█░▒█░▒█░▒█▀▀▀░░░▒█▀▀█▒█▄▄█░▒█▒█▒█░▒█░▒█░▒█░░░░▒█▀▀▀░▒█▄▄▀
░░▀▄▄▀░▒█░░▀█░▄█▄░▒█▄▄▀░▒█▄▄▄█░▒█▄▄█░▒█▄▄▄░░░▒█░▒█▒█░▒█░▒█░░▀█░▒█▄▄█░▒█▄▄█░▒█▄▄▄░▒█░▒█
                                                                                                  

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
        GIT_REPOSITORY https://github.com/you/unicode_handler.git
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
    git clone https://github.com/you/unicode_handler.git
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

    add_subdirectory(vendor/unicode_handler)

    # Declare your targets

    target_link_libraries(<your target name> PRIVATE cstl::unic)
```



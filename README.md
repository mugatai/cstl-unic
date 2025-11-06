
![Banner Text](readmeart.png)

## A unicode hanlding library written in C99

### Seamlessly read/write/encode/decode unicode characters

### Usage instructions ::

---
### Get the Libray ::

### CMake users ::

### Option 1 :: Using CMake-Fetchcontent (Recommended)

#### Step 1 : Add this to your CMakeLists.txt

```cmake

    include(FetchContent)

    FetchContent_Declare(
        cstl_unic
        GIT_REPOSITORY https://github.com/mugatai/cstl-unic.git
        GIT_TAG        v0.1.2
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE  # Shows download progress
        SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/cstl_unic
    )

    FetchContent_MakeAvailable(cstl_unic)

    # your targets

    target_link_libraries(<your target name> PRIVATE cstl::unic)

```


### Option 2 :: Using git-submodule
    
#### Step 1: create a vendor dir if not already there

```bash
    
    # Clone or copy into <project root>/vendor/
    mkdir -p vendor
    cd vendor
    git clone https://github.com/mugatai/cstl-unic.git cstl_unic

    ```

Make sure the CmakeLists.txt file of your project is on same directory level as vendor


#### Step 2: Link to your targets
    
```cmake

    add_subdirectory(vendor/cstl_unic)

    # Declare your targets

    target_link_libraries(<your target name> PRIVATE cstl::unic)
```


### How to Use

```c
    
    #include <cstl_unic.h>
    // Include this header to access the functions

```

```c

    res_uchar create_unicode(uint32_t hex);    // returns a res_uchar type value
    uint8_t print_unicode(res_uchar data);     // retruns how many bytes of character was printed
```


```c
    // res_uchar is a structure that contains two types.
    // First member is err (unichar_err enum type) that contains the state of the res_uchar type variable.
    // Second memeber is unichar struct that has two members (char array) chr and (unsigned 1 byte int) byte
    // You can directly access those but it is recommended that you use utilities given in the library

```

### Future plans 
[ ] v0.3.0
    - [ ] update_unicode // To update value of a variable with correct encoding

[ ] v0.4.0 
    - [ ] decode_unicode from a res_unichar type // Should return a hex value
    - [ ] decode unichar from a unicode literal // Same as above

[ ] v1.0.0 Start Static lib distribution of first stable release

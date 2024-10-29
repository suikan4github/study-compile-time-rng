

# GCOV settings
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage") 
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage") 


# List all test file in this directory
file(GLOB TEST_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# Test executable and library name
set(TEST_EXECUTABLE_NAME test_${PROJECT_NAME})

# Add the executable for the testcase which is using googletest
add_executable(${TEST_EXECUTABLE_NAME} ${TEST_SRC})

    # Add the library under test.
    target_link_libraries(${TEST_EXECUTABLE_NAME}  
                            "gtest_main"
                            lib
                            )

# Find and integrate the Google Test package

# Load the FetchContent module
# New in CMake 3.11
include("FetchContent")

# Declaration of googletest as content
FetchContent_Declare(
  	"googletest"
  	GIT_REPOSITORY "https://github.com/google/googletest.git"
  	GIT_TAG "v1.15.2"
)

# Fetch the googletest
FetchContent_MakeAvailable("googletest")

# Include the GoogleTest
include("GoogleTest")

# Enable CTest
# This command automatically run the enable_test() command.
# And the CMake specification requires to place the enable_test() at the
# root of the project, to run the ctest correctly. 
# Thus, place this command at the root of project.
include("CTest")


# Search test cases and link 
# New in CMake 3.10
gtest_discover_tests(${TEST_EXECUTABLE_NAME})
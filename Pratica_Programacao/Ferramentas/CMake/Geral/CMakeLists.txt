cmake_minimum_required(VERSION 3.23)


# Project name, desc, lang, etc...
project(example
  DESCRIPTION "Example CMake Template"
  LANGUAGES CXX C
)


###############################################################################
################################### Options ###################################
###############################################################################

# Options to define how to compile the code
# Need to run with -D{option-name}=ON/OFF
# ex: cmake -DINSTALLATION=ON ..

message("To compile your code with address sanitizer, run cmake -DSANITIZE ..")
option(SANITIZE "Run Address sanitizer (Default ON)" ON)

message("To compile your code to a library, run cmake -DLIBR ..")
option(LIBR "Makes the code into a library" OFF)

message("To install the package/lib, run cmake -DINSTALLATION ..")
option(INSTALLATION "Installs the executable/lib to the default folder" OFF)

message("To compile C code, run cmake -DLANG_C .. DEFAULTS TO C++")
option(LANG_C "Compile C code instead of C++" OFF)

###############################################################################


###############################################################################
######################### Variables and other options #########################
###############################################################################

# Default binary directory (Linux)
set(installBinDir bin)

# Default library directory (Linux)
set(installLibDir lib)

# Default header directory (Linux)
set(installHeaderDir include)

# Option to export the compilation command to a .json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add compiler flags to compilation.
add_compile_options(-Wall -Wextra)
if(SANITIZE)
  add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g -O1)
  add_link_options(-fsanitize=address)
else()
  add_compile_options(-O3)
endif()

###############################################################################


###############################################################################
################################ file globbing ################################
###############################################################################

# These instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables 
file(GLOB_RECURSE headers      src/*.h)
if(LANG_C)
  file(GLOB_RECURSE code      src/*.c)
else()
  file(GLOB_RECURSE code      src/*.cpp)
endif()

###############################################################################


###############################################################################
############################# target definitions ##############################
###############################################################################

# Library compilation 
if(LIBR)
  message("Creating Library")
  add_library(${PROJECT_NAME} ${code} ${headers})
  # option to get the .h headers (necessary to install the lib)
  set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER src/${PROJECT_NAME}.h)

# Binary compilation
else()
  message("Creating Executable")
  add_executable(${PROJECT_NAME} ${code} ${headers})
endif()

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(${PROJECT_NAME} PUBLIC Includes)
target_link_directories(${PROJECT_NAME} PUBLIC Includes)

###############################################################################


###############################################################################
################################ dependencies #################################
###############################################################################

# This defines the variables OpenCV_LIBRARIES that containts all library names
# that we need to link into the program.
find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc videoio)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${OpenCV_LIBRARIES}
  # here you can add any library dependencies
)

###############################################################################


###############################################################################
################################# packaging ###################################
###############################################################################

if(INSTALLATION)
  # Installs the package to the default folder
  if(LIBR) 
    install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${installLibDir}
            PUBLIC_HEADER DESTINATION ${installHeaderDir})
  else()
    install(TARGETS ${PROJECT_NAME} DESTINATION ${installBinDir})
  endif()
endif()

cmake_minimum_required(VERSION 3.23)

project(boost_practice
  DESCRIPTION "Example CMake Template"
  LANGUAGES CXX C
)

message("To compile your code to a library, run cmake -DLIBR ..")
option(LIBR "Makes the code into a library" OFF)

message("To install the package/lib, run cmake -DINSTALLATION ..")
option(INSTALLATION "Installs the executable/lib to the default folder" OFF)

message("To compile C code, run cmake -DLANG_C .. DEFAULTS TO C++")
option(LANG_C "Compile C code instead of C++" OFF)


set(installBinDir bin)
set(installLibDir lib)
set(installHeaderDir include)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Just for example add some compiler flags.
add_compile_options(-Wall -Wextra)

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
############################# target definitions ##############################
###############################################################################

# The data is just added to the executable
if(LIBR)
  message("Creating Library")
  add_library(${PROJECT_NAME} ${code} ${headers})
  set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER src/${PROJECT_NAME}.h)
else()
  message("Creating Executable")
  add_executable(${PROJECT_NAME} ${code} ${headers})
endif()

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(${PROJECT_NAME} PUBLIC Includes)
target_link_directories(${PROJECT_NAME} PUBLIC Includes)

###############################################################################
################################ dependencies #################################
###############################################################################

# This defines the variables _LIBRARIES that containts all library names
# that we need to link into the program.
find_package(Boost REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC
  ${Boost_LIBRARIES}
  # here you can add any library dependencies
)

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

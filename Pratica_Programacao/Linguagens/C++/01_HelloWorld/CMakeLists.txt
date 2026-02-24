cmake_minimum_required(VERSION 4.2.1)

project(example
  DESCRIPTION "Example CMake Template"
  HOMEPAGE_URL "https://www.example.org/"
  LANGUAGES CXX
)

message("To install the package to bin, run cmake -DINSTALL_BIN ..")
option(INSTALL_BIN "Installs the executable to the default bin folder" OFF)
set(installBinDir bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


###############################################################################
################################ file globbing ################################
###############################################################################

# These instructions search the directory tree when cmake is
# invoked and put all files that match the pattern in the variables 
file(GLOB_RECURSE main      src/*.cpp src/*.h)
message("Files found in src/: ${main}")

###############################################################################
############################# target definitions ##############################
###############################################################################

# The data is just added to the executable
message("Creating Executable")
add_executable(${PROJECT_NAME} ${main})

# Just for example add some compiler flags.
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Wextra)

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(${PROJECT_NAME} PUBLIC Includes)
target_link_directories(${PROJECT_NAME} PRIVATE Includes)

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
################################# packaging ###################################
###############################################################################

if(INSTALL_BIN)
    # Installs the binary (or executable) in the bins folder
    install(TARGETS ${PROJECT_NAME} DESTINATION ${installBinDir})
endif()

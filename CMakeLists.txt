cmake_minimum_required(VERSION 3.2)
project(FinalFantasyFootball C)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
message (STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")

# Find SDL2 library
if(WIN32)
	include_directories("external/windows/sdl2/include")
else(WIN32)
    find_package(SDL2 REQUIRED)
    #find_package(SDL2_image REQUIRED)
    #find_package(SDL2_ttf REQUIRED)
    include_directories(${SDL2_INCLUDE_DIR}
        #${SDL2_IMAGE_INCLUDE_DIR}
        #${SDL2_TTF_INCLUDE_DIR}
        )
endif(WIN32)


# bring the headers into the project
include_directories("src")
# Add sources
file(GLOB SOURCES "src/*.c")

# Create executable
add_executable(FinalFantasyFootball ${SOURCES})
# include SDL2 library
if(WIN32)
	target_link_libraries(FinalFantasyFootball 
	"${CMAKE_CURRENT_SOURCE_DIR}/external/windows/sdl2/lib/x86/SDL2.lib" 
	"${CMAKE_CURRENT_SOURCE_DIR}/external/windows/sdl2/lib/x86/SDL2main.lib")
else(WIN32)
    target_link_libraries(FinalFantasyFootball ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})
endif(WIN32)

# Copy runtime DLLs
if(WIN32)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/external/windows/sdl2/lib/x86/SDL2.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif(WIN32)

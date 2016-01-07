cmake_minimum_required(VERSION 2.8.9)
project(FinalFantasyFootball C)

# Find SDL2 library
if(WIN32)
	include_directories("external/windows/sdl2/include")
else(WIN32)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
	include_directories(${SDL2_INCLUDE_DIRS})
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
	target_link_libraries(FinalFantasyFootball ${SDL2_LIBRARY})
endif(WIN32)

# Copy runtime DLLs
if(WIN32)
	file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/external/windows/sdl2/lib/x86/SDL2.dll" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif(WIN32)

cmake_minimum_required(VERSION 2.8.9)
project(FinalFantasyFootball)

# bring the headers into the project
# include_directories(include)

# Add sources
file(GLOB SOURCES "src/*.c" "src/*.cpp")

add_executable(FinalFantasyFootball ${SOURCES})

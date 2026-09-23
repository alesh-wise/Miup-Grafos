cmake_minimum_required(VERSION 4.3)
project(Miup)

set(CMAKE_CXX_STANDARD 20)

add_executable(countingRooms countingRooms.cpp)

add_executable(labyrinth labyrinth.cpp)


add_executable(buildingRoads  buildingRoads.cpp
        roundTrip.cpp)

add_executable(messageRoute messageRoute.cpp)

add_executable(buildingTeams buildingTeams.cpp)
add_executable(roundTrip roundTrip.cpp)
add_executable(monsters monsters.cpp)
add_executable(shortestRoute1 shortestRoute1.cpp)
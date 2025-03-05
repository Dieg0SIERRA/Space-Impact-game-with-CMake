cmake_minimum_required(VERSION 3.8)

project(Space_Impact_CMake)
set(SRCS
    src/asteroid.cpp
    src/gameObject.cpp
    src/bullet.cpp
    src/screen.cpp
    src/spaceShip.cpp
    src/tools.cpp
    src/game.cpp
    src/enemies.cpp
)
    
set(HEADERS
    inc/asteroid.h
    inc/gameObject.h
    inc/bullet.h
    inc/screen.h
    inc/spaceShip.h
    inc/tools.h
    inc/game.h
    inc/enemies.h
    inc/factoryEnemies.h
    inc/animations.h
    inc/difficultyLevel.h
)

add_library(game ${SRCS} ${HEADERS})

target_include_directories(game PUBLIC 
    ${CMAKE_CURRENT_LIST_DIR}/inc    
    ${CMAKE_CURRENT_LIST_DIR}/src
)

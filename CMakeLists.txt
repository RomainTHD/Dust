set(DEBUG)
# set(RELEASE)
# set(ASM_PRE)

########################################################################################################################

cmake_minimum_required(VERSION 3.10)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")

if (RELEASE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -O3 -s")
elseif (DEBUG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
endif()

if (ASM_PRE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -save-temps")
endif()

########################################################################################################################

project(Dust)

include_directories("${PROJECT_BINARY_DIR}")

include_directories(./include)

set(SOURCE_FILES
        src/game/Game.cpp
        src/game/Map.cpp

        src/particles/Particle.cpp
        src/particles/ParticleType.cpp
        src/particles/SandParticle.cpp

        src/util/Observable.cpp
        src/util/Observer.cpp
        src/util/Types.cpp

        src/view/Color.cpp
        src/view/Console.cpp
        src/view/Window.cpp

        src/Main.cpp)

set(HEADER_FILES
        include/game/Game.h
        include/game/Map.fwd.h
        include/game/Map.h

        include/particles/Particle.fwd.h
        include/particles/Particle.h
        include/particles/ParticleType.h
        include/particles/SandParticle.h

        include/util/Observable.fwd.h
        include/util/Observable.h
        include/util/Observer.fwd.h
        include/util/Observer.h
        include/util/Types.h

        include/view/Color.h
        include/view/Console.h
        include/view/GenericView.h
        include/view/Window.h

        include/Config.h
        include/Main.h)

set(EXECUTABLE_NAME "Dust")

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES} ${HEADER_FILES})

########################################################################################################################

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED network audio graphics window system)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
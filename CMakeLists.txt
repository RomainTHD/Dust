cmake_minimum_required(VERSION 3.10)
project(Dust)

include_directories(./include)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/map/Map.cpp

        src/particles/Particle.cpp
        src/particles/ParticleType.cpp
        src/particles/SandParticle.cpp

        src/util/Observable.cpp
        src/util/Observer.cpp

        src/Main.cpp
)

set(HEADER_FILES
        include/map/Map.fwd.h
        include/map/Map.h

        include/particles/Particle.fwd.h
        include/particles/Particle.h
        include/particles/ParticleType.h
        include/particles/SandParticle.h

        include/util/Observable.fwd.h
        include/util/Observable.h
        include/util/Observer.fwd.h
        include/util/Observer.h

        include/main.h
)

add_executable(Dust ${SOURCE_FILES} ${HEADER_FILES})
cmake_minimum_required (VERSION 3.24)

project (PO23_SR17_252241)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -pedantic -Werror=return-type -Werror=parentheses -Werror=vla -Werror=array-bounds -Wcast-qual -Wmaybe-uninitialized )

IF (WIN32)
    set(SFML_DIR "E:/SFML-2.5.1/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
ENDIF()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(zelda main.cpp Game.cpp Game.h Player.cpp Player.h Wall.cpp Wall.h WorldMap.cpp WorldMap.h Floor.cpp Floor.h Items/Item.cpp Items/Item.h Items/Sword.cpp Items/Sword.h Teleport.h Teleport.cpp Ui.cpp Ui.h Items/Ruppes.cpp Items/Ruppes.h Items/HealHeart.cpp Items/HealHeart.h Items/MaxHeart.cpp Items/MaxHeart.h Enemy/Enemy.cpp Enemy/Enemy.h)
target_link_libraries(zelda sfml-graphics)
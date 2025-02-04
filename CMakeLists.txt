cmake_minimum_required(VERSION 3.10)

project(GameEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

include_directories("libs/include")
include_directories("C:/Users/lena/freetype/include")
link_directories("libs/lib/")

add_executable(GameEngine 
    src/main.cpp
    src/stb.cpp
    src/Math/Rectangle.cpp
    src/Math/Vector2.cpp
    src/Texture.cpp
    src/TextureLoader.cpp
    src/Camera2D.cpp
    src/Block.cpp
    src/Player.cpp
    src/SceneManager.cpp
    src/RoomGenerator.cpp
    src/GameScene.cpp
    src/FontLoader.cpp
    src/MenuScene.cpp
)

target_link_libraries(GameEngine OpenGL::GL)
target_link_libraries(GameEngine "libs/lib/glfw3dll")
target_link_libraries(GameEngine freetype)
cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME Chess)
project(${PROJECT_NAME} VERSION 1.0)

set(FILES_SRC libraries/Chessboard.cpp libraries/Computer.cpp libraries/Log.cpp libraries/Position.cpp libraries/pieces/Bishop.cpp libraries/pieces/Horse.cpp libraries/pieces/King.cpp libraries/pieces/Pawn.cpp libraries/pieces/Queen.cpp libraries/pieces/Rook.cpp libraries/pieces/Space.cpp )
set(FILES_HEADER include/Chessboard.h include/Computer.h include/Log.h include/Position.h include/pieces/Bishop.h include/pieces/Horse.h include/pieces/King.h include/pieces/Pawn.h include/pieces/Piece.h include/pieces/Queen.h include/pieces/Rook.h include/pieces/Space.h )
SET(GCC_COVERAGE_COMPILE_FLAGS "-g")

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

include_directories(include libraries include/pieces libraries/pieces)

add_library(
    ChessLib
    ${FILES_SRC} 
    ${FILES_HEADER}
)

add_executable(scacchiera src/Scacchiera.cpp)
add_executable(replay src/Replay.cpp)

target_link_libraries(scacchiera ChessLib)
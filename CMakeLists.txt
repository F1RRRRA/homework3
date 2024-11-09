cmake_minimum_required(VERSION 3.12)

project(03.check_value)

add_executable(
	check_value
	check_value.cpp
)

add_executable(
	random_value
	random_value.cpp
)

add_executable(
	game
	src/game.cpp
	src/main.cpp
)
add_executable(fourier
	"main.cpp"
	"RenderWindow.cpp"
  "Screen.cpp" "screens/DummyScreen.cpp")

target_include_directories(fourier PRIVATE
	${CMAKE_SOURCE_DIR}/include
	external/SDL/include
)

target_link_libraries(fourier PRIVATE
	SDL2
	SDL2main
)

if(WIN32)
	add_custom_command(TARGET fourier POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:SDL2> $<TARGET_FILE_DIR:fourier>
	)
endif()
add_executable(fourier
	"main.cpp"
)

target_include_directories(fourier PRIVATE
	${CMAKE_SOURCE_DIR}/include
)
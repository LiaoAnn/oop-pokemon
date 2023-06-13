cmake_minimum_required(VERSION 3.12)
project(MyProject)

# 指定 Boost 庫的位置
set(Boost_INCLUDE_DIR
	"path/to/boost/root/dir"
	"C:/local/boost_1_82_0"
	# Add your own Boost include path here
)
set(Boost_LIBRARY_DIR 
	"path/to/boost/libs/dir"
	"C:/local/boost_1_82_0/stage/lib"
	# Add your own Boost library path here
)
set(WebSocketpp
	"path/to/websocketpp/root/dir"
	"C:/local/websocketpp-0.8.2"
	# Add your own WebSocketpp include path here

set(Lib
	${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# 添加 Boost 的庫和頭文件的搜索路徑
link_directories(${Boost_LIBRARY_DIR})
include_directories(${Boost_INCLUDE_DIR})
include_directories(${WebSocketpp})
include_directories(${Lib})

# 設置項目的可執行文件
add_executable(myapp "")

# 遞歸搜索並收集所有 .cpp 和 .h 文件
file(GLOB_RECURSE CPP_SOURCES "src/*.cpp")
# file(GLOB_RECURSE HEADER_FILES "include/*.h")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 添加所有的 .cpp 和 .h 文件到可執行文件中
target_sources(myapp PRIVATE ${CPP_SOURCES} ${HEADER_FILES})

# 鏈接 Boost 庫
target_link_libraries(myapp PRIVATE ${Boost_LIBRARIES})

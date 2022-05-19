cmake_minimum_required(VERSION 3.16.0)
set(PROJ_NAME app)

add_executable(${PROJ_NAME})

file(GLOB_RECURSE ${PROJ_NAME}_SRC CONFIGURE_DEPENDS "*.cpp")
target_sources(${PROJ_NAME} PRIVATE ${${PROJ_NAME}_SRC})

target_compile_features(${PROJ_NAME} PRIVATE cxx_std_17)
target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# target_link_libraries(${PROJ_NAME} PRIVATE common)
target_link_libraries(${PROJ_NAME} PRIVATE foo)
target_link_libraries(${PROJ_NAME} PRIVATE bar)
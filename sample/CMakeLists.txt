project(Dog-sample)

# =============
# == Sources ==
# =============
file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h)

# ===========
# == Build ==
# ===========
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    DOG::Dog
)

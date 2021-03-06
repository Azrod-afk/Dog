# =============
# == Sources ==
# =============
file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h)

# ===========
# == Build ==
# ===========
add_library(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

add_library(DOG::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
  )

if (BUILD_SHARED_LIBS AND MSVC)
  set_target_properties(${PROJECT_NAME} PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

message(STATUS ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)


target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_options(${PROJECT_NAME} PRIVATE ${STANDARD_WARNINGS})

# ==================
# == Installation ==
# ==================

install(TARGETS ${PROJECT_NAME}
  EXPORT DOG 
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} 
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} 
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  ) 

foreach(FILE ${HEADER_FILES})
  get_filename_component(ABSOLUTE_DIR ${FILE} DIRECTORY)
  string(REPLACE ${CMAKE_CURRENT_LIST_DIR} "" RELATIVE_DIR ${ABSOLUTE_DIR})
  install(FILES ${FILE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${RELATIVE_DIR})
  install(FILES ${FILE} DESTINATION ${CMAKE_INSTALL_DATADIR}/Dog/${RELATIVE_DIR})
endforeach()
cmake_minimum_required(VERSION 3.17)
project(
  Argxx VERSION 0.0
  DESCRIPTION "An objective solution to keyword argumnets in C++"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

add_library(Argxx INTERFACE)

target_include_directories(Argxx INTERFACE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/ArgxxConfigVersion.cmake"
    VERSION 0.1
    COMPATIBILITY AnyNewerVersion
)

install(TARGETS Argxx
    EXPORT ArgxxTargets
    LIBRARY DESTINATION lib COMPONENT Runtime
    ARCHIVE DESTINATION lib COMPONENT Development
    RUNTIME DESTINATION bin COMPONENT Runtime
    PUBLIC_HEADER DESTINATION include COMPONENT Development
    BUNDLE DESTINATION bin COMPONENT Runtime
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/ArgxxConfig.cmake"
    "${PROJECT_BINARY_DIR}/ArgxxConfig.cmake"
    INSTALL_DESTINATION lib/cmake/Argxx
)

install(EXPORT ArgxxTargets DESTINATION lib/cmake/Argxx)
install(FILES "${PROJECT_BINARY_DIR}/ArgxxConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/ArgxxConfig.cmake"
        DESTINATION lib/cmake/Argxx)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)
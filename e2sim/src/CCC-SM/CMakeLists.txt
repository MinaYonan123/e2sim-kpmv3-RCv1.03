# Header-only library for CCC-SM
add_library(e2sm_ccc INTERFACE)

target_include_directories(e2sm_ccc INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include>)

if( DEV_PKG )
  install( FILES
    e2sm_ccc.hpp
    DESTINATION ${install_inc}
    )
endif()
if (LIBJANSSON_INCLUDE_DIR AND LIBJANSSON_LIBRARY)
  set (LIBJANSSON_FOUND TRUE)
else (LIBJANSSON_INCLUDE_DIR AND LIBJANSSON_LIBRARY)
  find_path(LIBJANSSON_INCLUDE_DIR jansson.h)
  find_library(LIBJANSSON_LIBRARY jansson)

  include(FindPackageHandleStandardArgs)

  find_package_handle_standard_args(LibJansson REQUIRED_VARS LIBJANSSON_INCLUDE_DIR LIBJANSSON_LIBRARY)
endif (LIBJANSSON_INCLUDE_DIR AND LIBJANSSON_LIBRARY)

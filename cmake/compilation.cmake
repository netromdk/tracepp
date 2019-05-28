set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic-errors")

  # Certain warnings are promoted to errors.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=unused-variable -Werror=unused-value -Werror=return-type -Werror=shadow")

  # Clang/GCC
  set(REL_OPTS "-pipe -fvisibility=hidden -fvisibility-inlines-hidden -ffast-math -funroll-loops")

  # Clang only
  if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Werror=conversion -Wno-double-promotion -Wno-c++98-compat -Wno-c++98-compat-pedantic -Werror=nonportable-include-path -Werror=pessimizing-move -Werror=infinite-recursion")

    if (EVERY_WARNING)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything")
    endif()
  endif()

  # GCC only
  if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    set(REL_OPTS "${REL_OPTS} -fno-implement-inlines")
  endif()

  set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL} ${REL_OPTS}")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${REL_OPTS}")
  set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${REL_OPTS}")
endif()

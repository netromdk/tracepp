add_executable(
  example
  example.cc
  )

add_executable(
  example2
  example2.cc
  )

add_executable(
  custom
  custom.cc
  )

add_executable(
  print_func
  print_func.cc
  )

add_custom_target(
  run_examples
  COMMAND $<TARGET_FILE:example>
  COMMAND $<TARGET_FILE:example2>
  COMMAND $<TARGET_FILE:custom>
  COMMAND $<TARGET_FILE:print_func>
  USES_TERMINAL
  )

add_dependencies(
  run_examples
  example
  example2
  custom
  print_func
  )

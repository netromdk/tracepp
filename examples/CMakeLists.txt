function(add_example name out_cmds out_targets)
  add_executable(
    ${name}
    ${name}.cc
  )

  list(APPEND ${out_cmds} COMMAND $<TARGET_FILE:${name}>)
  set(${out_cmds} "${${out_cmds}}" PARENT_SCOPE)

  list(APPEND ${out_targets} ${name})
  set(${out_targets} "${${out_targets}}" PARENT_SCOPE)
endfunction()

set(cmds)
set(targets)
add_example(example cmds targets)
add_example(example2 cmds targets)
add_example(custom cmds targets)
add_example(print_func cmds targets)

add_custom_target(run_examples ${cmds} USES_TERMINAL)
add_dependencies(run_examples ${targets})


find_program(STANDARDESE standardese HINTS ${STANDARDESE_ROOT})

if (STANDARDESE)
  message(STATUS "Found standardese for documentation generation")
  file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/doc/standardese)
  add_custom_target(
      standardese
      COMMAND ${STANDARDESE}
      -I${CMAKE_SOURCE_DIR}/include
      --input.blacklist_namespace=detail
      --compilation.comments_in_macro=false
      --output.require_comment_for_full_synopsis=false
      --output.format=html
      ${CMAKE_SOURCE_DIR}/include
      WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/doc/standardese
  )
endif (STANDARDESE)


find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(DOXYGEN_GROUPS_FILE "${CMAKE_BINARY_DIR}/doc/GroupDefs.h")

  set(DOXYGEN_GENERATE_HTML "YES")
  set(DOXYGEN_GENERATE_XML "NO")
  configure_file(
      doc/Doxyfile.in
      ${PROJECT_BINARY_DIR}/doc/DoxyfileHtml @ONLY IMMEDIATE
  )
  # Configure file that contains doxygen groups
  configure_file(doc/GroupDefs.h ${DOXYGEN_GROUPS_FILE})

  add_custom_target(
      doxygen
      COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/doc/DoxyfileHtml 2>&1
      DEPENDS
      ${PROJECT_BINARY_DIR}/doc/DoxyfileHtml
      ${DOXYGEN_GROUPS_FILE}
  )

  set(DOXYGEN_GENERATE_HTML "NO")
  set(DOXYGEN_GENERATE_XML "YES")
  configure_file(
      doc/Doxyfile.in
      ${PROJECT_BINARY_DIR}/doc/DoxyfileXml @ONLY IMMEDIATE
  )
  add_custom_target(
      doxygen-xml
      COMMAND ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/doc/DoxyfileXml
      DEPENDS
      ${PROJECT_BINARY_DIR}/doc/DoxyfileXml
      ${DOXYGEN_GROUPS_FILE}
  )
endif (DOXYGEN_FOUND)

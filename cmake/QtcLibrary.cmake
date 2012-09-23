if(WINDOWS)
    set(QTC_LIBRARY_PATH bin)
else()
    set(QTC_LIBRARY_PATH lib/qtcreator)
endif()

macro(qtc_add_library target)
    add_library(${target} ${ARGN})
    set_target_properties(${target} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${QTC_LIBRARY_PATH}
        RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${QTC_LIBRARY_PATH}
        ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    )
    if(MINGW)
        set_target_properties(${target} PROPERTIES
            PREFIX ""
            IMPORT_SUFFIX ".a"
        )
    endif()
    install(TARGETS ${target}
        LIBRARY DESTINATION ${QTC_LIBRARY_PATH}
        RUNTIME DESTINATION ${QTC_LIBRARY_PATH}
        ARCHIVE DESTINATION lib
    )
endmacro()

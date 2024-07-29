# Adiciona o diretório de includes da biblioteca principal
include_directories(${CMAKE_SOURCE_DIR}/IsothermLib/include)

# Adiciona todas as subpastas de exemplos em TwoParameters
function(add_subdirectories_to_build)
    file(GLOB EXAMPLES_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
    foreach(subdir ${EXAMPLES_SUBDIRS})
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} AND NOT ${subdir} STREQUAL "CMakeLists.txt")
            add_subdirectory(${subdir})
        endif()
    endforeach()
endfunction()

# Adiciona todas as subpastas de exemplo
add_subdirectories_to_build()

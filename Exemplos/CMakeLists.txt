# Adiciona o diretório de includes da biblioteca principal
include_directories(${CMAKE_SOURCE_DIR}/IsothermLib/include)

# Função para adicionar subdiretórios de forma recursiva e compilar exemplos
function(add_subdirectories_to_build)
    file(GLOB EXAMPLES_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
    foreach(subdir ${EXAMPLES_SUBDIRS})
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} AND NOT ${subdir} STREQUAL "CMakeLists.txt")
            add_subdirectory(${subdir})
        endif()
    endforeach()
endfunction()

# Adiciona todas as subpastas em Exemplos
add_subdirectories_to_build()

# Adiciona uma variável para armazenar todos os alvos de exemplo
set(ALL_EXAMPLES "")

# Preenche a lista de alvos de exemplo
function(collect_example_targets)
    file(GLOB EXAMPLES_SUBDIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
    foreach(subdir ${EXAMPLES_SUBDIRS})
        if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${subdir} AND NOT ${subdir} STREQUAL "CMakeLists.txt")
            file(GLOB EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/${subdir}/*.cpp")
            foreach(example ${EXAMPLES})
                get_filename_component(example_name ${example} NAME_WE)
                list(APPEND ALL_EXAMPLES ${example_name})
            endforeach()
        endif()
    endforeach()
endfunction()

# Coleta os alvos de exemplo
collect_example_targets()

# Adiciona um alvo para compilar todos os exemplos
add_custom_target(run_examples
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target ${ALL_EXAMPLES}
    COMMENT "Compilando todos os exemplos"
)

# Adiciona os comandos para executar os exemplos após a construção
foreach(example ${ALL_EXAMPLES})
    add_custom_command(TARGET ${example}
        POST_BUILD
        COMMAND ${example}
        COMMENT "Executando ${example}..."
    )
endforeach()

# Adiciona o alvo customizado para rodar todos os exemplos
add_custom_target(run_all_examples
    COMMAND ${CMAKE_COMMAND} --build . --target run_examples
    DEPENDS run_examples
    COMMENT "Compilando e rodando todos os exemplos"
)

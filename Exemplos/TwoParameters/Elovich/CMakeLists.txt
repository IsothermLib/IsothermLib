# Adiciona o diretório de includes da biblioteca principal
include_directories(${CMAKE_SOURCE_DIR}/IsothermLib/include)

# Adiciona o executável para o exemplo DubininRadushkevich
add_executable(Elovich Elovich.cpp)
target_link_libraries(Elovich PRIVATE IsothermLib)

# Adiciona um alvo para rodar o exemplo
add_custom_target(run_DubininRadushkevich
    COMMAND Elovich
    DEPENDS Elovich
    COMMENT "Executando Elovich ..."
)

# Adiciona o exemplo à lista de alvos
list(APPEND ALL_EXAMPLES Elovich)

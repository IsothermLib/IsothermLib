# Adiciona o diretório de includes da biblioteca principal
include_directories(${CMAKE_SOURCE_DIR}/IsothermLib/include)

# Adiciona o executável para o exemplo DubininRadushkevich
add_executable(DubininRadushkevich DubininRadushkevich.cpp)
target_link_libraries(DubininRadushkevich PRIVATE IsothermLib)

# Adiciona um alvo para rodar o exemplo
add_custom_target(run_DubininRadushkevich
    COMMAND DubininRadushkevich
    DEPENDS DubininRadushkevich
    COMMENT "Executando DubininRadushkevich..."
)

# Adiciona o exemplo à lista de alvos
list(APPEND ALL_EXAMPLES DubininRadushkevich)

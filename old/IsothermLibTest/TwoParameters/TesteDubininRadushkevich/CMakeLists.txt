# Define o nome do execut�vel e do arquivo de teste
set(IsothermExe "TesteDubininRadushkevich")
set(IsothermFile "${IsothermExe}.cpp")

# Configura o diret�rio de sa�da para o execut�vel do teste
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}")

# Adiciona o execut�vel do teste usando a fun��o customizada
add_test_executable(${IsothermExe} ${IsothermFile})

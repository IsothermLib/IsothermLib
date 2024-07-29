# Isotherm
 
 IsothermLib é uma biblioteca desenvolvida em C++20 em que se modelou diversas funções de isotermas de adsorção.
 
 
- A biblioteca foi desenvolvida no Instituto Politécnico da UERJ, campus de Nova Friburgo, Rio de Janeiro.
- Especialmente indicada para quem desenvolve modelos de fenômenos de transporte envolvendo processos de adsorção/desorção.


# Instalação

Nesta versão a biblioteca foi testada e preparada para ser utilizada em ambiente Linux. Contudo, como usa somente os recursos do C++20 padrão, com alguns pequenos ajustes, ela poderá ser utilizada em outros sistemas operacionais.

# Instruções de Compilação para a Biblioteca C++

Este documento fornece instruções para compilar a biblioteca C++ usando o sistema de build `CMake`. Siga as etapas abaixo para compilar a biblioteca a partir do código-fonte.

## Requisitos

Antes de começar, certifique-se de que você tem as seguintes ferramentas instaladas:

- **CMake**: Ferramenta de configuração e geração de projetos de compilação. [Baixe e instale o CMake](https://cmake.org/download/).
- **Make**: Ferramenta para automatizar a construção de projetos de software. Normalmente já está disponível em sistemas Unix e Linux. [Baixe e instale o Make](https://www.gnu.org/software/make/).

## Passos para Compilar a Biblioteca

Siga as etapas abaixo para compilar a biblioteca.

### 1. Crie uma Pasta `build`

Crie uma pasta chamada `build` na raiz do diretório do projeto. Esta pasta será usada para armazenar todos os arquivos gerados durante o processo de compilação.

```sh
mkdir build
cd build
cmake ../.
```

Compile o projeto usando o Make. Este comando compila o código-fonte e gera a biblioteca e os arquivos executáveis.
```sh
make
```
Se desejar instalar a biblioteca no sistema, você poderá executar o comando make install. Você pode precisar de permissões de superusuário para esta etapa.
```sh
sudo make install
```
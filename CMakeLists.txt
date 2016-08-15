# Esta linha é importante para garantir que não se tente usar uma versão antiga
# do CMake. Freqüentemente são introduzidas novas features, então é importante.
cmake_minimum_required(VERSION 3.0.0)


# Seta o compilador para trabalhar com as diretivas do C++ 11.
SET(GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")
SET( CMAKE_CXX_FLAGS  "${GCC_COVERAGE_COMPILE_FLAGS}" )

# Define modo debug.
#set_directory_properties(PROPERTIES COMPILE_DEFINITIONS_DEBUG "_DEBUG")

# Cria uma variável com um valor inicial e também a torna acessível para o
# usuário através da interface gráfica ou curses.
#set(FW_PATH "../fw" CACHE STRING "Path to the FW")

# Procura pelo OpenCV instalado na máquina. Se não existir, vai dar erro.
find_package(OpenCV REQUIRED)

# Aqui verificamos se o OpenCV foi encontrado. Note que estamos testando a
# variável, e não o valor dela.
if (OpenCV_VERSION)

  # Se o OpenCV foi encontrado, informa ao usuário qual a versão presente no
  # sistema.
  message(STATUS "OpenCV version: " ${OpenCV_VERSION_MAJOR} "." ${OpenCV_VERSION_MINOR} "." ${OpenCV_VERSION_PATCH})

  # Se a versão do OpenCV for menor que 3.0, emitimos um fatal error.
  if(${OpenCV_VERSION_MAJOR} LESS 2 OR (${OpenCV_VERSION_MAJOR} EQUAL 2 AND ${OpenCV_VERSION_MINOR} LESS 3))
    message(FATAL_ERROR "You need OpenCV version 3.0 or later!")
  endif()

endif()

# Adicionamos o diretório de include deste projeto.
include_directories(include/advanced)
include_directories(include/basic)
# O diretório de include do framework também é adicionado,
#include_directories(${FW_PATH}/include)
# assim como o diretório onde espera-se encontrar a biblioteca.
#link_directories(${FW_PATH}/build)

# Este comando busca todos os arquivos *.cpp dentro do diretório src,
# recursivamente, e armazena a lista na variável lib_sources.
file(GLOB_RECURSE lib_sources src/*.cpp)

# Aqui dizemos ao CMake que queremos construir uma biblioteca chamada ex (que
# será libex.so no Linux e ex.dll no Windows) composta pelos arquivos contidos
# na variável lib_sources.
add_library(code STATIC ${lib_sources})

# Esta biblioteca que estamos criando depende das bibliotecas do OpenCV e do
# framework.
#target_link_libraries(code ${OpenCV_LIBS} fw)
target_link_libraries(code ${OpenCV_LIBS} )

# Informamos ao CMake para criar um executável chamado test (test.exe no
# Windows) a partir do arquivo app/test.cpp.
add_executable(run app/run.cpp)

# Este executável depende da biblioteca ex, também construída por este arquivo.
target_link_libraries(run code)

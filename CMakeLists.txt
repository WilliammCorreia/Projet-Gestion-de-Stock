cmake_minimum_required(VERSION 3.24)
project(GestionStockV2 C)

set(CMAKE_C_STANDARD 11)

add_executable(GestionStockV2 main.c gestion_produit.c gestion_fournisseur.c)

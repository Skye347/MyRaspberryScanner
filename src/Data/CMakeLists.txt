cmake_minimum_required(VERSION 3.6)
aux_source_directory(. DATA_LIB)
add_library(DataLib ${DATA_LIB})
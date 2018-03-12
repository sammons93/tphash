cmake_minimum_required(VERSION 3.9)
project(tphash)

set(CMAKE_CXX_STANDARD 11)

add_executable(tphash
        annuaire.c
        hachage.c
        hachage.h
        Makefile)

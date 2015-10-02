CXX = g++
CC = gcc
CFLAGS = -Wall -c
CXXFLAGS = -Wall

OUTPUTDIR = ./executable/
CODEDIR = ./code/
MKDIR = mkdir -p $(OUTPUTDIR)

HEADERS = q.h
CXXSOURCES = \
	$(CODEDIR)proj_1.cpp

all: project

project:
	$(MKDIR)
	$(CXX) $(CXXSOURCES) -o $(OUTPUTDIR)a.out

clean:
	rm -rf $(OUTPUTDIR)


#=====================================
# Example Makefile for project that
# has multiple C and C++ sources
#=====================================
#
#
#CXX = g++
#CC = gcc
#CFLAGS = -Wall -c
#CXXFLAGS = -Wall
#
#OUTPUTDIR = ./executable/
#CODEDIR = ./code/
#MKDIR = mkdir -p $(OUTPUTDIR)
#OBJECTC = \
#	compiler.o \
#
#CSOURCES = \
#	$(CODEDIR)compiler.c
#
#CXXSOURCES = \
#	$(CODEDIR)parser.cpp
#
#all: project
#
#project:
#	$(MKDIR)
#	$(CC) $(CSOURCES) $(CFLAGS) -o $(OUTPUTDIR)$(OBJECTC)
#	$(CXX) $(OUTPUTDIR)$(OBJECTC) $(CXXSOURCES) -o $(OUTPUTDIR)a.out
#
#clean:
#	rm -rf $(OUTPUTDIR)



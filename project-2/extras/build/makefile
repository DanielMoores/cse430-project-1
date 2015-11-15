CC = gcc
CFLAGS = -Wall 

# This path is relative to the test script when being
# called from the test script, or relative from this
# location when strictly being run from here.
OUTPUTDIR = ./executable/
CODEDIR = ./../../code/
MKDIR = mkdir -p $(OUTPUTDIR)

CSOURCES = \
	$(CODEDIR)thread_test.c

all: project

project:
	$(MKDIR)
	$(CC) $(CSOURCES) $(CFLAGS) -o $(OUTPUTDIR)a.out

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



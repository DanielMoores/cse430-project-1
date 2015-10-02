CXX = g++
CC = gcc
CFLAGS = -Wall -c
CXXFLAGS = -Wall

OUTPUTDIR = ./executable/
CODEDIR = ./code/
MKDIR = mkdir -p $(OUTPUTDIR)
OBJECTC = \


CSOURCES = \


CXXSOURCES = \
	$(CODEDIR)proj_1.cpp

all: project

project:
	$(MKDIR)
	$(CC) $(CSOURCES) $(CFLAGS) -o $(OUTPUTDIR)$(OBJECTC)
	$(CXX) $(OUTPUTDIR)$(OBJECTC) $(CXXSOURCES) -o $(OUTPUTDIR)a.out

clean:
	rm -rf $(OUTPUTDIR)

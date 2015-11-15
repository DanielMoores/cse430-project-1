cse430-project-3 
=======================================

###Topic: Semaphores

**NOTE: This project requires the ucontext.h library, which to our knowledge is only available on linux.**

This is a project from our CSE 430 Operating Systems class at Arizona State University.  There is a project specification PDF located inside 

    /cse430-project-3/extras/specifications/project_specifications.pdf

Included in this project is a makefile, and a script to build and run the project. This is located at:

    /cse430-project-3/extras/build/makefile
    /cse430-project-3/extras/build/run.sh

The run script will call the makefile to build the project then will clean up any files it created during the build process. In reality, since the code creates infinite loops, it will never terminate on its own, so the script will never actually get to clean the files created.

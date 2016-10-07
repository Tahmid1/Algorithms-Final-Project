#Tahmid Rahman
#Dylan Jeffers
#Makefile for Algorithms Final Project
#On SPLAVL Trees

CXX = g++ 
CXXFLAGS = -g -Wall

INCLUDES = BST.h \
       pair.h \
	   library/arrayQueue.h library/list.h library/circularArrayList.h \
	   library/queue.h \
       SplayTree.h SplayTree-inl.h SplayTree-private-inl.h \
       AVLTree.h AVLTree-inl.h AVLTree-private-inl.h \
       SPLAVL.h SPLAVL-inl.h SPLAVL-private-inl.h

PROGRAMS = testSplay testSPLAVL cheatDetector

PROGRAMS = testSplay testSPLAVL cheatDetector randomInput


all: $(PROGRAMS)

testSplay: $(INCLUDES) $(OBJECTS) testSplay.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)
	
testSPLAVL: $(INCLUDES) $(OBJECTS) testSPLAVL.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

cheatDetector: $(INCLUDES) $(OBJECTS) cheatDetector.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

randomInput: $(INCLUDES) $(OBJECTS) randomInput.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean

CXX = g++ 
CXXFLAGS = -g -Wall

#Remove the # below when you are ready to work with your AVLTree
INCLUDES = BST.h \
       pair.h \
	   library/arrayQueue.h library/list.h library/circularArrayList.h \
	   library/queue.h \
       SplayTree.h SplayTree-inl.h SplayTree-private-inl.h \
       AVLTree.h AVLTree-inl.h AVLTree-private-inl.h \
       SPLAVL.h SPLAVL-inl.h SPLAVL-private-inl.h


# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS =


# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
PROGRAMS = testSplay testSPLAVL

all: $(PROGRAMS)

testSplay: $(INCLUDES) $(OBJECTS) testSplay.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)
	
testSPLAVL: $(INCLUDES) $(OBJECTS) testSPLAVL.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean

CXX = clang++
CXXFLAGS = -g -Wall

#Remove the # below when you are ready to work with your AVLTree
INCLUDES = BST.h linkedBST.h linkedBST-inl.h linkedBST-private-inl.h pair.h \
	   library/arrayQueue.h library/list.h library/circularArrayList.h \
	   library/queue.h \
           AVLTree.h AVLTree-inl.h AVLTree-private-inl.h 


# If you create any new non-templated classes, add an appropriate .o file
# to the OBJECTS definition below:
OBJECTS =


# If you create a new test program, add the name of the test program
# to the PROGRAMS definition below and then create a rule for that program
PROGRAMS = testBST cheatDetector

all: $(PROGRAMS)

testBST: $(INCLUDES) $(OBJECTS) testBST.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)

cheatDetector: $(INCLUDES) $(OBJECTS) cheatDetector.cpp
	$(CXX) $(CXXFLAGS) -o $@ $@.cpp $(OBJECTS)


#do not modify this command
grading: grading.cpp $(INCLUDES) $(OBJECTS)
	$(CXX) $(CXXFLAGS) grading.cpp $(OBJS) -o grading

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o $(PROGRAMS)

.PHONY: all clean

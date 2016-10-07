/*pair.h
 *
 *Dylan Jeffers
 *Tahmid Rahman
 *
 *This definition of a pair was
 *taken from Joshua Brody's CS31
 *class during fall of 2014 at 
 *Swarthmore 
 */ 


#ifndef PAIR_H_
#define PAIR_H_

/**
 * A Pair is an container class for two pieces of data, which it
 * stores publicly.  
 */
template <typename F, typename S>
class Pair {
  public:
    F first;   // The first item in the pair.
    S second;  // The second item in the pair.

    Pair() {};
    Pair(F f, S s) {first = f; second = s;};
};

#endif

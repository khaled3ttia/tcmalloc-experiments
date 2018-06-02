///-*-C++-*-//////////////////////////////////////////////////////////////////
//
// Hoard: A Fast, Scalable, and Memory-Efficient Allocator
//        for Shared-Memory Multiprocessors
// Contact author: Emery Berger, http://www.cs.utexas.edu/users/emery
//
// Copyright (c) 1998-2000, The University of Texas at Austin.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Library General Public License as
// published by the Free Software Foundation, http://www.fsf.org.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
//////////////////////////////////////////////////////////////////////////////


/**
 * @file threadtest.cpp
 *
 * This program does nothing but generate a number of kernel threads
 * that allocate and free memory, with a variable
 * amount of "work" (i.e. cycle wasting) in between.
*/

#ifndef _REENTRANT
#define _REENTRANT
#endif

#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <iterator>


int niterations = 50;	// Default number of iterations.
int nobjects = 30000;  // Default number of objects.
int nthreads = 1;	// Default number of threads.
int work = 0;		// Default number of loop iterations.
int objSize = 1;

std::map<int,float> pageUtilization;
std::map<int,float> maxUtilization;

class Foo {
public:
  Foo (void)
    : x (14),
      y (29)
    {}

  int x;
  int y;
};


void worker ()
{
  int i, j;
  Foo ** a;
  a = new Foo * [nobjects / nthreads];
  int page_number;
  for (j = 0; j < niterations; j++) {
    		
    for (i = 0; i < (nobjects / nthreads); i ++) {
      a[i] = new Foo[objSize];
      cout << "size of object : " << sizeof(a[i]) << endl;
      
      //get corresponding page number by shifting right the address by 12 bits
      page_number =  reinterpret_cast<std::uintptr_t>(a[i]) >> 12;
      //Check if the page number is currently an existing key in the page utilization map, if so add new allocated space to the coressponding value
      if (pageUtilization.find(page_number) != pageUtilization.end()) {
	pageUtilization[page_number] += objSize*sizeof(a[i])/4096.0;
        if (maxUtilization.find(page_number) != maxUtilization.end()) {
		if (pageUtilization[page_number] > maxUtilization[page_number]){
			maxUtilization[page_number] = pageUtilization[page_number];
		}
	}else {
		maxUtilization[page_number] = pageUtilization[page_number];
	}
        cout << "value to be stored at address: " << a[i] << " and page number " << page_number << "  is : " << pageUtilization[page_number] << endl;
      }else {
	pageUtilization[page_number] = objSize*sizeof(a[i])/4096.0;
	maxUtilization[page_number] = pageUtilization[page_number];
        cout << "value to be stored at page number " << page_number << "  is : " << objSize*sizeof(a[i])/4096.0 << endl;
      }
//      printf("allocated space of %d and address %p and page number is %d\n",objSize, static_cast<void*>(&a[i]), reinterpret_cast<std::uintptr_t>(&a[i]) >> 12);
#if 1
      for (volatile int d = 0; d < work; d++) {
	volatile int f = 1;
	f = f + f;
	f = f * f;
	f = f + f;
	f = f * f;
      }
#endif
      assert (a[i]);
    }
    
    for (i = 0; i < (nobjects / nthreads); i ++) {
      cout << "Deallocating object at address : " << a[i];
      delete[] a[i];
      //cout << "current value of page number: " << page_number << endl;
      
      page_number =  reinterpret_cast<std::uintptr_t>(a[i]) >> 12;
      cout << " and page number " << page_number << endl;  
      pageUtilization[page_number] -= objSize*sizeof(a[i])/4096.0;
#if 1
      for (volatile int d = 0; d < work; d++) {
	volatile int f = 1;
	f = f + f;
	f = f * f;
	f = f + f;
	f = f * f;
      }
#endif
    }
  }

  delete [] a;
}

int main (int argc, char * argv[])
{
  thread ** threads;
  
  if (argc >= 2) {
    nthreads = atoi(argv[1]);
  }

  if (argc >= 3) {
    niterations = atoi(argv[2]);
  }

  if (argc >= 4) {
    nobjects = atoi(argv[3]);
  }

  if (argc >= 5) {
    work = atoi(argv[4]);
  }

  if (argc >= 6) {
    objSize = atoi(argv[5]);
  }

  printf ("Running threadtest for %d threads, %d iterations, %d objects, %d work and %d objSize...\n", nthreads, niterations, nobjects, work, objSize);

  threads = new thread*[nthreads];

  high_resolution_clock t;
  auto start = t.now();

  int i;
  for (i = 0; i < nthreads; i++) {
    threads[i] = new thread(worker);
  }

  for (i = 0; i < nthreads; i++) {
    threads[i]->join();
  }

  auto stop = t.now();
  auto elapsed = duration_cast<duration<double>>(stop - start);

  cout << "Time elapsed = " << elapsed.count() << endl;
  
  //print final page utilization map
  printf("Page Number		Max Utilization\n");
  std::map<int,float>::iterator it = maxUtilization.begin();
  while (it != maxUtilization.end()) {
	std::cout<<it->first<<"			" << it->second<<std::endl;
	it++;
  }
  delete [] threads;

  return 0;
}

include ../Makefile.inc

TARGET = threadtest

$(TARGET): threadtest.cpp
	$(CXX) -std=c++11 $(CXXFLAGS) threadtest.cpp -o $(TARGET) -lpthread -ltcmalloc -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free

clean:
	rm -f $(TARGET)

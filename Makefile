CXX=g++
CXXFLAGS=-g -Wall -std=c++11

# For parser DEBUG
#DEFS=-DDEBUG

OBJS=amazon.o user.o db_parser.o product.o product_parser.o util.o book.o clothing.o movie.o mydatastore.o

all: amazon

amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

amazon.o: amazon.cpp db_parser.h product_parser.h datastore.h
	$(CXX) $(CXXFLAGS) -c $<

book.o: book.cpp book.h product.h
	$(CXX) $(CXXFLAGS) -c $<

clothing.o: clothing.cpp clothing.h product.h
	$(CXX) $(CXXFLAGS) -c $<

db_parser.o: db_parser.cpp db_parser.h product.h product_parser.h user.h datastore.h
	$(CXX) $(CXXFLAGS) -c $<

movie.o: movie.cpp movie.h product.h
	$(CXX) $(CXXFLAGS) -c $<

mydatastore.o: mydatastore.cpp mydatastore.h datastore.h
	$(CXX) $(CXXFLAGS) -c $<

product.o: product.cpp product.h
	$(CXX) $(CXXFLAGS) -c $<

product_parser.o: product_parser.cpp product_parser.h product.h
	$(CXX) $(CXXFLAGS) -c $<

user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c $<

util.o: util.cpp util.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o amazon
	
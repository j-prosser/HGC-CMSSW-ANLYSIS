

#clang++ or g++ ? 
# if OS X Darwin kernel...
SONAME = -soname
CXX = g++
####################
### useful paths ###
####################

# top and current dirs
#CURRENT_DIR = $(shell pwd)

# inc and src dirs 
INC_DIR = ./inc
SRC_DIR = ./src

# obj, lib and bin dirs
BIN_DIR = ./bin
LIB_DIR = ./lib

# dictionary dir
# unused (?) 
DIC_DIR = ./dic

##########################
### flags and libs and INC
##########################

# root
ROOT_CFLAGS = $(shell root-config --cflags)
ROOT_GLIBS = $(shell root-config --glibs)
ROOT_EXTRA_LIBS = -lEG # neede fot TDatabasePDG

# INCLUDES
INC += -I$(INC_DIR)

# CXX flags
CXXFLAGS =  -Wall -std=c++11 -Wno-write-strings -fPIC
CXXFLAGS += $(ROOT_CFLAGS)
CXXFLAGS += $(INC)

# debug flags
DEBUGFLAGS = -g

# CXX LIBS
CXXLIBS =  $(ROOT_GLIBS) $(ROOT_EXTRA_LIBS)


#############
### FILES ###
#############

# all .cpp (we will make exec from them)
MAINS_CPP := $(wildcard ./*.cpp)
EXE       := $(MAINS_CPP:./%.cpp=./bin/%.exe)

# all sources .cc 
SOURCES_CC  := $(wildcard $(SRC_DIR)/*.cc)
LIB         := $(SOURCES_CC:$(SRC_DIR)/%.cc=$(LIB_DIR)/%.o)

# all the dictionaries 
DICTS     = HGC HGCC3D HGCC2D HGCTC HGCgen HGCgenpart HGChit ResolutionStats ### add here the classes you wanna add to ROOT ###
DICTS_CXX = $(DICTS:%=Dict%.cxx)
DICTS_H   = $(DICTS:%=$(INC_DIR)/%.h)


#############
### RULES ###
#############

.PHONY: dict

all: $(EXE) 

#$(EXE): %.exe: %.cpp $(LIB) dict
$(EXE): ./bin/%.exe: %.cpp $(LIB) $(DICTS_CXX)
	@echo " >>> Compiling "$<" <<< " 
	@mkdir -p $(BIN_DIR)
	$(CXX) -o bin/$(notdir $@) $(DICTS_CXX) $< $(DEBUGFLAGS) $(CXXFLAGS) $(CXXLIBS) $(LIB) 


$(LIB): $(LIB_DIR)%.o: $(SRC_DIR)%.cc
	@mkdir -p $(LIB_DIR)
	$(CXX) $(CXXFLAGS) $(CXXLIBS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(LIB_DIR)
	rm -rf Dict*
	rm -rf *.o
	rm -rf $(BIN_DIR)

clean_dict:
	rm -rf Dict*
	rm -rf *.o

init:
	@mkdir -p $(INC_DIR)
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(LIB_DIR)
	@mkdir -p *.o

dict: $(DICTS_CXX)
#dict: $(DICTS)
	@echo ROOT dictionaries generated 

#$(DICTS): $(DICTS_H)
#	@echo $<
#	@echo $@
#	rootcint -f Dict$@.cxx -c $(INC_DIR)/$@.h $(INC_DIR)/$@linkDef.h
#	g++ -g -fPIC $(INC) $(ROOT_CFLAGS) -c Dict$@.cxx $(SRC_DIR)/$@.cc 
##g++ -g $(CXXFLAGS) -c Dict$@.cxx $(SRC_DIR)/$@.cc
#	g++ -g -Wl,-soname,$(LIB_DIR)/$@.so -shared Dict$@.o $(LIB_DIR)/$@.o -o $(LIB_DIR)/$@.so




$(DICTS_CXX): Dict%.cxx: $(INC_DIR)/%.h $(INC_DIR)/%linkDef.h $(SRC_DIR)/%.cc $(LIB_DIR)/%.o
	rootcint -f $@ -c $(filter %.h, $^)
# generate the objects (unlinked) 
	$(CXX) -g -fPIC $(INC) $(ROOT_CFLAGS) -c $@ $(filter %.cc, $^)

	$(CXX) -g  -shared $(patsubst %.cxx, %.o, $@) $(filter %.o, $^) -o $(patsubst %.o, %.so, $(filter %.o, $^))
#g++ -g -fPIC $(INC) $(ROOT_CFLAGS) -c $@ $(filter %.cc, $^) 
#g++ -g $(CXXFLAGS) -c Dict$@.cxx $(SRC_DIR)/$@.cc
# replace soname with install_name
#    $(CXX) -bundle -undefined -dynamic_lookup -fPIC -o $(patsubst $(space)%.o, %.so, $(filter %.o, $^)) $(patsubst %.cxx, %.o, $@) $(filter %.o, $^)  $(patsubst %.o, %.so, $(filter %.o, $^))

# HOW TO MAKE THIS MAKEFILE FUNCTION CORRECTLY ON OS X
#  USING: https://stackoverflow.com/questions/14173260/creating-shared-libraries-in-c-for-osx
# 	replace -shared with -dynamicllib

# -c or -Wl ?????????? -Wl doesn't work
# following command basically is ignored by OS X however doesn't give errors, (because of -c)
	#$(CXX) -g -c $(SONAME) $(patsubst $(space)%.o, %.so, $(filter %.o, $^)) -shared $(patsubst %.cxx, %.o, $@) $(filter %.o, $^) -o $(patsubst %.o, %.so, $(filter %.o, $^))
# trying to compile dynamic libraries on OS X, 
# patsubst := pattern substitute 
# i.e. patsubst x,y, ab x b xd ( replace all x's with y in whitespace-separated pattern. 
	
# WOrking here
# g++ -dynamiclib -undefined suppress -flat_namespace  $(patsubst %.cxx, %.o, $@) $(filter %.o, $^)  -o something.dylib

# Works?
#	$(CXX) -dynamiclib -undefined suppress -flat_namespace $(patsubst %.cxx, %.o, $@) $(filter %.o, $^)   -o $(patsubst %.o, %.so, $(filter %.o, $^))

#$(CXX) -g $(SONAME) $(patsubst $(space)%.o, %.dynlib, $(filter %.o, $^)) -dynamiclib $(patsubst %.cxx, %.o, $@) $(filter %.o, $^) -o $(patsubst %.o, %.dynlib, $(filter %.o, $^))


#$(CXX) -g -c -Wl -install_name $(patsubst $(space)%.o, %.so, $(filter %.o, $^)) -shared $(patsubst %.cxx, %.o, $@) $(filter %.o, $^) -o $(patsubst %.o, %.so, $(filter %.o, $^))

#g++ -g -Wl,-soname,$(patsubst $(space)%.o, %.so, $(filter %.o, $^)) -shared $(patsubst %.cxx, %.o, $@) $(filter %.o, $^) -o $(patsubst %.o, %.so, $(filter %.o, $^))

echo: 
#	@echo $(DIC_H)    
#	@echo $(DIC_CXX)
#	@echo $(DIC_LINKDEF) 
#	@echo $(HEPMCFLAGS)
	@echo $(EXE)
	@echo $(LIB)
#	@echo $(SOURCES_CC)
#	@echo $(CURRENT_DIR)
##	@echo $(BOOST_DIR)
#	@echo $(INC_DIR)
#	@echo $(SRC_DIR)
#	@echo $(SOURCES_CC)
#	@echo $(LIB)
#	@echo $(MAINS_CPP)
#	@echo $(EXE)
#	@echo $(DICTS_H)


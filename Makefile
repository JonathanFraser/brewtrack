SOURCES := $(wildcard *.cpp)
OBJECTS := $(patsubst %.cpp,%.o,$(SOURCES))
DEPENDS := $(patsubst %.cpp,%.d,$(SOURCES))

override LIBRARIES := sqlite3  #libudev gtkmm-3.0
override CXXFLAGS := -g -Wall --std=gnu++0x $(shell pkg-config --cflags $(LIBRARIES)) $(CXXFLAGS)
override LDFLAGS := --std=gnu++11 $(shell pkg-config --libs $(LIBRARIES) )$(LDFLAGS)
override LIBS := $(LIBS)

TARGET := brewtrack

.SILENT:

.PHONY all: $(TARGET)

$(TARGET): $(OBJECTS)
	echo "LD $@"
	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBS)

%.o:%.cpp Makefile
	echo "CXX $@"
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.d:%.cpp Makefile
	echo "DEP $@"
	$(CXX) $(CXXFLAGS) -o $@ -MM $<

.PHONY: clean
clean:
	$(RM) *.d
	$(RM) *.o 
	$(RM) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
include $(DEPENDS) 
endif
	

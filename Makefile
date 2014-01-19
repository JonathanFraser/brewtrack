SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(patsubst src/%.cpp,obj/%.o,$(SOURCES))
DEPENDS := $(patsubst src/%.cpp,deps/%.d,$(SOURCES))
PROTOS := $(wildcard proto/*.proto)
PROTOS_H := $(patsubst %.proto,%.pb.h,$(PROTOS))
PROTOS_CCS := $(patsubst %.proto, %.pb.cc, $(PROTOS))
PROTOS_OBJ := $(patsubst proto/%.proto, obj/%.pb.o, $(PROTOS))

OBJECTS := $(OBJECTS) $(PROTOS_OBJ)

override LIBRARIES := cxxtools protobuf #libudev gtkmm-3.0
override CXXFLAGS := -g -Wall -I ./include --std=gnu++0x $(shell pkg-config --cflags $(LIBRARIES)) $(CXXFLAGS)
override LDFLAGS := -g --std=gnu++0x -ltntdb $(shell pkg-config --libs $(LIBRARIES) )$(LDFLAGS)
override LIBS := $(LIBS)

TARGET := brewtrack

.SILENT:

.PHONY all: $(TARGET)

$(TARGET): $(OBJECTS) 
	echo "LD $@"
	$(CXX) $(LDFLAGS) -o $@ $+ $(LIBS)

proto/%.pb.h proto/%.pb.cc:proto/%.proto
	protoc --proto_path=proto --cpp_out=proto $<
.SECONDARY: $(PROTOS_CCS) $(PROTOS_H)

obj/%.pb.o:proto/%.pb.cc Makefile $(PROTOS_H)
	$(CXX) $(CXXFLAGS) -o$@ -c -Wno-extra -Wno-conversion $<

obj/%.o:src/%.cpp Makefile
	echo "CXX $@"
	$(CXX) $(CXXFLAGS) -o $@ -c $<

deps/%.d:src/%.cpp Makefile $(PROTO_H)
	echo "DEP $@"
	$(CXX) $(CXXFLAGS) -o $@ -MM $<

.PHONY: clean
clean:
	$(RM) deps/*.d
	$(RM) obj/*.o 
	$(RM) $(PROTOS_H)
	$(RM) $(PROTOS_CCS)
	$(RM) $(TARGET)

ifneq ($(MAKECMDGOALS),clean)
include $(DEPENDS) 
endif
	

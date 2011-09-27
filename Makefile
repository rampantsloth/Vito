APPLICATION = vito

SRCDIR = src
OBJDIR = obj

# Source location definitions: TODO (just list them all)
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
LINKOBJECTS =  $(subst $(SRCDIR), $(OBJDIR), $(SOURCES:.cpp=.o))

SOURCES += $(wildcard $(SRCDIR)/Features/*.cpp)
SOURCES += $(wildcard $(SRCDIR)/Classifiers/*.cpp)

FEATURE_PLUGIN_SOURCES    = $(wildcard $(SRCDIR)/FeaturePlugins/*.cpp)
CLASSIFIER_PLUGIN_SOURCES = $(wildcard $(SRCDIR)/ClassifierPlugins/*.cpp)

PLUGIN_SOURCES = $(FEATURE_PLUGIN_SOURCES) $(CLASSIFIER_PLUGIN_SOURCES)
PLUGIN_OBJECTS = $(subst $(SRCDIR), $(OBJDIR), $(PLUGIN_SOURCES:.cpp=.dylib))

#objects
OBJECTS = $(subst $(SRCDIR), $(OBJDIR), $(SOURCES:.cpp=.o))

# include path:
IPATH =  -I./src/ 
IPATH += -I./src/Features
IPATH += -I./src/Classifiers
IPATH += -I./libs/libsvm-3.0/
IPATH += -I/opt/local/include 
IPATH += -I/opt/local/include/opencv

LIBPATH  +=  -L/opt/local/lib 
LIBPATH  +=  -L/usr/local/lib 

#LIBS = -lcxcore -lcvaux -lcv
LIBS = -lopencv_ml -lopencv_core -lopencv_imgproc -lopencv_objdetect -lopencv_highgui -lopencv_legacy


CPPC = g++
LINKER = $(CPPC)
CPPFLAGS = -Wall -DUNIX

all: $(APPLICATION) 


name_sources:
	@echo "sources are: $(SOURCES)"
	@echo "objects are: $(OBJECTS)"

$(APPLICATION): $(OBJECTS) $(PLUGIN_OBJECTS)
	$(LINKER) $(LIBPATH) $(LIBS) -o $(APPLICATION) $(LINKOBJECTS)

$(OBJDIR)/%.dylib: $(SRCDIR)/%.cpp
	$(CPPC) -fPIC $(Global) -c $(CPPFLAGS) -o  $(OBJDIR)/$*.o $< $(IPATH)
	$(CPPC) -fPIC -undefined suppress -flat_namespace -dynamiclib -o $@ $(OBJDIR)/$*.o

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h 
	$(CPPC) -c $(CPPFLAGS)  -o $@ $< $(IPATH)

clean:
	rm $(OBJECTS) $(APPLICATION)




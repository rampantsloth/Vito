APPLICATION = vito

#-------------------------------------------------------------------------------
# locations etc
#-------------------------------------------------------------------------------

SRCDIR = src
OBJDIR = obj

DEFAULT_PARAMETERS_FILE = parameters.xml

FEATUREPLUGINSRCDIR = $(SRCDIR)/FeaturePlugins
CLASSIFIERPLUGINSRCDIR = $(SRCDIR)/ClassifierPlugins

FEATUREPLUGINOBJDIR = $(OBJDIR)/FeaturePlugins
CLASSIFIERPLUGINOBJDIR = $(OBJDIR)/ClassifierPlugins

#-------------------------------------------------------------------------------
# Source location definitions: TODO (just list them all)
#-------------------------------------------------------------------------------

SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
LINKOBJECTS =  $(subst $(SRCDIR), $(OBJDIR), $(SOURCES:.cpp=.o))

FEATURESOURCES += $(wildcard $(SRCDIR)/Features/*.cpp)
SOURCES += $(FEATURESOURCES)
SOURCES += $(wildcard $(SRCDIR)/Classifiers/*.cpp)

FEATURE_PLUGIN_SOURCES    = $(wildcard $(FEATUREPLUGINSRCDIR)/*.cpp)
CLASSIFIER_PLUGIN_SOURCES = $(wildcard $(CLASSIFIERPLUGINSRCDIR)/*.cpp)

PLUGIN_SOURCES = $(FEATURE_PLUGIN_SOURCES) $(CLASSIFIER_PLUGIN_SOURCES)
PLUGIN_OBJECTS = $(subst $(SRCDIR), $(OBJDIR), $(PLUGIN_SOURCES:.cpp=.dylib))

OBJECTS = $(subst $(SRCDIR), $(OBJDIR), $(SOURCES:.cpp=.o))

#-------------------------------------------------------------------------------
# include path:
#-------------------------------------------------------------------------------

IPATH =  -I./src/ 
IPATH += -I./src/Features
IPATH += -I./src/Classifiers
IPATH += -I./libs/libsvm-3.0/
IPATH += -I/opt/local/include 
IPATH += -I/opt/local/include/opencv
IPATH += -I./libs/
LIBPATH  +=  -L/opt/local/lib 
LIBPATH  +=  -L/usr/local/lib 
LIBPATH   += -L./libs/

LIBOBJECTS = 	libs/tinyxml/tinystr.o libs/tinyxml/tinyxml.o \
		libs/tinyxml/tinyxmlerror.o libs/tinyxml/tinyxmlparser.o \
		\
		libs/libsvm-3.0/svm.o

#-------------------------------------------------------------------------------
# Libraries:
#-------------------------------------------------------------------------------

LIBS = 	\
	-lopencv_ml -lopencv_core -lopencv_imgproc \
	-lopencv_objdetect -lopencv_highgui -lopencv_legacy\
	\
	-lboost_filesystem -lboost_system # boost

#-------------------------------------------------------------------------------
# Macros:
#-------------------------------------------------------------------------------

DEFAULTS_PARAMETERS_MACRO = -D 'DEFAULTPARAMETERS="$(DEFAULT_PARAMETERS_FILE)"'
FEATURE_PLUGIN_DIR_MACRO = -D 'FEATUREPLUGINDIR="$(FEATUREPLUGINOBJDIR)"'
CLASSIFIER_PLUGIN_DIR_MACRO = -D 'CLASSIFIERPLUGINDIR="$(CLASSIFIERPLUGINOBJDIR)"'

MACROS = 	$(DEFAULTS_PARAMETERS_MACRO) \
		$(FEATURE_PLUGIN_DIR_MACRO)\
		$(CLASSIFIER_PLUGIN_DIR_MACRO)

#-------------------------------------------------------------------------------
# Compile commands and Make logic
#-------------------------------------------------------------------------------

CPPC = g++
LINKER = $(CPPC)
CPPFLAGS = -g -Wall -DUNIX $(MACROS)

all: libs $(APPLICATION) 

# Locally Compiled Libraries:

libs: svm mpeg7lib tinyxml

tinyxml: 
	cd libs/tinyxml && $(MAKE)

mpeg7lib: 
	cd libs/mpeg7 && $(MAKE)

SVM_Objects = libs/libsvm-3.0/svm.o

svm: $(SVM_Objects)

$(SVM_Objects):
	$(MAKE) -C libs/libsvm-3.0

name_sources:
	@echo "sources are: $(SOURCES)"
	@echo "objects are: $(OBJECTS)"

$(APPLICATION): $(OBJECTS) $(PLUGIN_OBJECTS)
	$(LINKER) $(LIBPATH) $(LIBS) -o $(APPLICATION) $(LINKOBJECTS) $(LIBOBJECTS)

$(OBJDIR)/%.dylib: $(SRCDIR)/%.cpp $(FEATURESOURCES)
	$(CPPC) -fPIC $(Global) -c $(CPPFLAGS) -o  $(OBJDIR)/$*.o $< $(IPATH)
	$(CPPC) -fPIC -undefined suppress -flat_namespace -dynamiclib -o $@ $(OBJDIR)/$*.o

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(SRCDIR)/%.h 
	$(CPPC) -c $(CPPFLAGS)  -o $@ $< $(IPATH)

clean:
	rm $(OBJECTS) $(APPLICATION)

clean_plugins:
	rm $(PLUGIN_OBJECTS)

plugins: clean_plugins all



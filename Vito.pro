#-------------------------------------------------
#
# Project created by QtCreator 2011-10-04T15:45:09
#
#-------------------------------------------------


QT       += core gui

TARGET = Vito
TEMPLATE = app

INCLUDEPATH +=  ./libs/libsvm-3.0 \
                /opt/local/include \
                /opt/local/include/opencv \
                ./libs \
                ./src/

SOURCES +=\
    gui/mainwindow.cpp \
    gui/main.cpp \
    src/XMLParameterDataSource.cpp \
    src/SVMClassifier.cpp \
    src/sharedpointer.cpp \
    src/PluginLoader.cpp \
    src/ParameterDataSource.cpp \
    src/labels.cpp \
    src/imageAccess.cpp \
    src/Image.cpp \
    src/gradient.cpp \
    src/FeaturePluginManager.cpp \
    src/FeatureFactory.cpp \
    src/estimation.cpp \
    src/descriptor.cpp \
    src/demo.cpp \
    src/dataPoint.cpp \
    src/classifier.cpp \
    src/BoostFileSystem.cpp \
    libs/tinyxml/tinyxmlparser.cpp \
    libs/tinyxml/tinyxmlerror.cpp \
    libs/tinyxml/tinyxml.cpp \
    libs/tinyxml/tinystr.cpp

HEADERS  += gui/mainwindow.h \
    src/XMLParameterDataSource.h \
    src/VisualFeatureExtractor.h \
    src/VisualFeatureDecorator.h \
    src/VisualFeatureAlgorithm.h \
    src/SVMClassifier.h \
    src/sharedpointer.h \
    src/PluginType.h \
    src/PluginLoader.h \
    src/ParameterDataSource.h \
    src/matrix.h \
    src/LRUCache.h \
    src/labels.h \
    src/IVisualFeatureFetcher.h \
    src/IVisualFeatureExtractor.h \
    src/imageAccess.h \
    src/Image.h \
    src/gradient.h \
    src/geometry.h \
    src/FileSystem.h \
    src/FeaturePluginManager.h \
    src/FeatureFactory.h \
    src/Example.h \
    src/estimation.h \
    src/descriptor.h \
    src/demo.h \
    src/dataPoint.h \
    src/classifier.h \
    src/CachedFeatureExtractor.h \
    src/BoostFileSystem.h \
    libs/tinyxml/tinyxml.h \
    libs/tinyxml/tinystr.h

FORMS    += gui/mainwindow.ui

OTHER_FILES +=


LIBS  +=  -L/opt/local/lib
LIBS  +=  -L/usr/local/lib
#LIBS  +=  -L./libs/

DEFINES += FEATUREPLUGINDIR=\\\"obj/FeaturePlugins\\\"

unix:!symbian|win32: LIBS += -lboost_filesystem -lboost_system

unix|!symbian|win32: LIBS += -lopencv_ml -lopencv_core -lopencv_imgproc \
                    -lopencv_objdetect -lopencv_highgui -lopencv_legacy\




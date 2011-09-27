#ifndef VISUALFEATUREDECORATOR_H
#define VISUALFEATUREDECORATOR_H

class VisualFeatureDecorator{
  SP<IVisualFeatureExtractor> extractor;
  virtual Descriptor extract(DataPoint dp, RgbImage *visrep = 0) = 0;
};

#endif

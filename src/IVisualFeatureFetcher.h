#ifndef IVISUALFEATUREFETCHER_H
#define IVISUALFEATUREFETCHER_H

class IVisualFeatureFetcher{
public:
  virtual const Descriptor *        extract(DataPoint dp, 
					    RgbImage *visrep = 0) = 0;
  virtual vector<const Descriptor*> extract(DataPointCollection dps) = 0;
};

#endif

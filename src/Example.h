#ifndef EXAMPLE_H
#define EXAMPLE_H

class Example : public Descriptor{
private:
  int label;
public:
  Example() : Descriptor() {}
  Example(size_t size) : Descriptor(size) {}
  Example(std::vector<float> values) : Descriptor(values) {}
  Example(std::vector<float> values, int l) : Descriptor(values), label(l){}

  void set_label(const int i);
  int  get_label() const;
};
};

#endif

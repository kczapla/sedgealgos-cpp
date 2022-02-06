namespace sedgealgos::stack {
  class ResizingArrayStack {
  public:
    ResizingArrayStack();
    ~ResizingArrayStack();

    unsigned long size() const;
    bool is_empty() const;
    void push(int a);
    int pop();

  private:
    void resize(unsigned long);

    unsigned long next_index{0};
    unsigned long capacity{0};
    int* container{nullptr};
  };
}

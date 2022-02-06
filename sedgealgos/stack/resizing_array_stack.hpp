namespace sedgealgos::stack {
  class ResizingArrayStack {
  public:
    ResizingArrayStack();
    ~ResizingArrayStack();

    bool is_empty() const;
    void push(int a);

  private:
    unsigned long index{0};
    int* container{nullptr};
  };
}

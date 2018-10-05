class stack_array   {

private:
    const unsigned int max_allowed_size = 1200;
    int * my_vec;
    unsigned int v_top;

public:

    stack_array();
    ~stack_array();

    int top () const; 
    int pop ();
    void push (const int new_elem);
    int size () const;
};
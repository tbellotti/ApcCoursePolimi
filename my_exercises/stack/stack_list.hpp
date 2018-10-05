class stack_list{

    private:
        stack_list * ptr;
        int elem;

    public:
        stack_list();
        int top () const;
        int pop ();
        void push (const int new_value);
};
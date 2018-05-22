#TODO Implementations


## 1. Correct implementation of special members (Section 2.1)(16 credits);:

- [x] (a)Regular constructor (2 credits);
- [ ] (b)Constructor (size) (2 credits);
- [x] (c)Destructor (2 credits);
- [x] (d)Copy constructor (2 credits);
- [ ] (e)Constructor from range (2 credits);
- [ ] (f)Constructor from initialize list (2 credits);
- [x] (g)Assignment operator ×2 (4 credits);

##2. Correct implementation of the get iterators (Section 3.1) (4 credits);

- [x] (a) begin() (1 credits);
- [x] (b) end() (1 credits);
- [x] (c) cbegin() (1 credits);
- [x] (d) cend() (1 credits);

##3. Correct implementation of common operations (Section 2.2) (20 credits);

- [x] (a) Empty() (1 credits);
- [x] (b) Size() (1 credits);
- [x] (c) Clear() (2 credits);
- [x] (d) Front() (2 credits);
- [x] (e) Back() (2 credits);
- [x] (f) Push_front() (2 credits);
- [x] (g) Push_back() (2 credits);
- [x] (h) Pop_front() (2 credits);
- [x] (i) Pop_back() (2 credits);
- [x] (j) Assign() ×2 (4 credits);
- [ ] (h) Assign wih Range;

##4. Correct implementation of operator overloading (Section 2.3) (2 credits);

- [x] (a) Operator==() (1 credits);
- [x] (b) Operator!=() (1 credits);

##5. Correct implementation of methods that require iterator (Section 3.3) (21 credits);

- [ ] (a) Insert() ×2 (9 credits);
- [x] (b) Find() ×2 (6 credits);
- [x] (c) Erase() ×2 (6 credits);



##6. **Correct implementation of the iterators (Section 3) (15 credits);**

### Const_Iterators

- [x] const_iterator( );
- [x] const T & operator * ( ) const;
- [x] const_iterator & operator ++ ( ); // ++it;
- [x] const_iterator operator ++ ( i n t ); // it++;
- [x] const_iterator & operator -- ( ); // --it;
- [x] const_iterator operator -- ( i n t ); // it--;
- [x] bool operator == ( const const_iterator & rhs ) const;
- [x] bool operator != ( const const_iterator & rhs ) const;

### Iterators

- [x] iterator( ) : const_iterator() { /* Empty */ }
- [x] const T & operator * ( ) const;
- [x] T & operator * ( );
- [x] iterator & operator ++ ( );
- [x] iterator operator ++ ( int );
- [x] iterator & operator --( );
- [x] iterator operator -- ( int );




- [ ] ### **A driver program that comprehensively tests the three classes you should implement (22 credits).**

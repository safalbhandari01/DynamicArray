
	class  DynamicArray {
	private:
		int size;										//number of elements in the array
		int* array;
		int capacity;									//maximu number of elements the array can hold

	public:
		DynamicArray();									//default constructor
		~DynamicArray();								//destructor
		DynamicArray(int size);							//overloading constructor
		int get_size();									//gets the size of the array
		int get_data(int i);							//gets data of index i
		void prepend(int data);							//adds at beginning of the array
		void append(int data);							//adds at the end of the array
		void add_at_i(int position, int data);			//adds at the ith position
		void remove_at_i(int position);					//removes the element of the ith position
		void reverse();									//reverses the array
		void rotate(int r);								//rotates the array by r position
		void random_shuffle();							//randomly shuffles the array
		void display_i(int position);					//display the data of ith index
		void display_range(int position1, int position2);//displays the data of the desired range
		void display_links();							//displays the address of the first element and the last element
		void display_all();								//displays the whole array
		void info();									//displays the info of the array
		void resize();									//resizes the array
	};



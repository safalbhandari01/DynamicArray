#include"string"
#include"iostream"
#include<algorithm>
#include"DynamicArray.h"
using namespace std;

DynamicArray::DynamicArray() {									 //default constructor
	DynamicArray(10);
	
}
 
DynamicArray::~DynamicArray() {									 //destructor
	delete[] array;
}

DynamicArray::DynamicArray(int size) {							 //Overloading constructor
	this->size = size;
	this->capacity = size;
	array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = 0;

	}
	
}

int DynamicArray::get_size() {									//returns the size  of the dynamic array
	return size;
}

int DynamicArray::get_data(int i) {
	return array[i];
}

void DynamicArray::prepend(int data) {							//adds at the beginning of the array
	if (capacity == size)
		resize();

	for (int i = size; i > 0; i--) {
		array[i] = array[i - 1];

	}
	array[0] = data;
	size++;

}

void DynamicArray::append(int data) {							//adds at the end of the array
	if (capacity == size)
		resize();

	array[size] = data;
	size++;
}

void DynamicArray::add_at_i(int position, int data) {			//adds at index i
	if (capacity == size)
		resize();

	for (int i = size; i > position; i--) {
		array[i] = array[i - 1];
	}
	array[position] = data;

	size++;
}

void DynamicArray::remove_at_i(int position) {					//remove at index i
	for (int i = position; i < size - 1; i++) {
		array[i] = array[i + 1];
	}
	array[size - 1] = NULL;
	size--;
}

void DynamicArray::reverse() {									//reverse the dynamic array
	int *temp = new int[capacity];
	int j = size;
	for (int i = 0; i < size; i++) {
		temp[j - 1] = array[i];
		j--;
	}
	delete[] array;
	array = temp;
}

void DynamicArray::rotate(int r) {
	
	
	if (r == 0 || (abs(r)%this->size) == 0)
		return;
	//for positive r
	int temp = abs(r) % size;
	int* rotate_temp = new int[temp];
	
	
	int k = abs(r);

	for (int i = 0; i < temp; i++)
	{
		rotate_temp[i] = array[size - temp+i];
	}
	


	if (r > 0) {
		int j = 0;
		for (int i = temp; i < size; i++) {
			array[i] = array[j];
			j++;
		}
	}
	

	if (r > 0) {
		for (int i = 0; i < temp; i++) {
			array[i] = rotate_temp[i];
		}
	}
	
}

void DynamicArray::random_shuffle() {											//Randomly shuffles the array
	

	int randomNum1;
	int randomNum2;
	int temp1;
	int temp2;

	for (int i = 0; i < this->size; i++)
	{
		randomNum1 = rand() % this->size;
		randomNum2 = rand() % this->size;

		temp1 = array[randomNum1];
		temp2 = array[randomNum2];

		array[randomNum2] = temp1;
		array[randomNum1] = temp2;


	}

	return;

}


void DynamicArray::display_i(int position) {									//display data at index i
	if (position < 0 || position> (capacity - 1))
		cout << "Please enter a valid index\n";
	cout << "Index I: " << array[position] << endl;
}

void DynamicArray::display_range(int position1, int position2) {				//display range from index1 to index2
	cout << "Dipslaying the desired range\n";
	for (int i = position1; i <= position2; i++) {
		
		cout << "Index " << i << ": " << array[i] << endl;

	}

}

void DynamicArray::display_all() {												//display all the index

	cout << "The elements in the array are\n";
	for (int i = 0; i < size; i++) {
	
		cout << "Index " << i << ": " << array[i] << endl;
	}
}

void DynamicArray::display_links() {											//Displays the links
	cout << "Address of 1st element\n" << &array[0] << endl;
	cout << "Address of last element\n" << &array[size - 1] << endl;
}

void DynamicArray::info() {														//gives dynamic array info
	cout << "Array-type: Dynamic Array\n" << "Array Size = " << this->size << "\n" << "Array Capacity = " << this->capacity << endl;
}

void DynamicArray::resize() {													//resize the dynamic array
	int *temp;
	this->capacity = 2 * this->size;											//resizing the array to two times the current size

	temp = new int[capacity];
	for (int i = 0; i < capacity; i++) {
		temp[i] = array[i];
	}
	delete[] array;
	array = temp;
	
}






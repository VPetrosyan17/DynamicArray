#include <iostream>
#include <stdexcept>


template<typename T>

class DynamicArray{
	public:
	//Constructor
	DynamicArray() : data(nullptr), size(0), capacity(0) {}
	//Destructor
	~DynamicArray(){
		delete[] data;
	}
	//adding element to dynamic array
	void push_back(const T& value ){
		if(size == capacity){
			int newCapacity = capacity == 0 ? 1 : capacity * 2;
			T* newData = new T[newCapacity];
			for(size_t i = 0; i < size; ++i){
				newData[i] = data[i];
				}	
			delete[] data;
			data = newData;
		}
		data[size] = value;
		++size;
	}
	//deleting the last element
	void pop_back(){
		if(size > 0){
			T* newData = new T[size - 1];
			for(int i = 0; i < size - 1; ++i){
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			--size;
		}else{
			throw std::underflow_error("Vector is empty!");	
		}
	}
	//insert element using index
	void insert(unsigned int index, const T& value){
		if(index > size){
			throw std::out_of_range("Index is out of range!");
		}
		data[index] = value;
	}
	//the functionality same as push_back
	void insert(const T& value){
		if(size == capacity){
			int newCapacity = capacity == 0 ? 1 : capacity * 2;
			T* newData = new T[newCapacity];
			for(int i = 0; i < size; ++i){
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
		data[size] = value;
		++size;
	}
	
	T& operator[](unsigned int index){
		if(index >= size){
			throw std::out_of_range("Index is out of range!");
		}
		return data[index];
	}
	//removing element using index
	void remove(unsigned int index){
		if(index > size){
			throw std::out_of_range("The index is out of range!");
		}
		T* newData = new T[size];
		for(int i = 0; i < size; ++i){
			if(i != index){
				newData[i] = data[i];
			}
		}
		delete[] data;
		data = newData;
		--size;
	}
	//make the size and capacity equal
	void shrink_to_fit(){
		if(size < capacity){
			T* newData = new T[size];
			for(int i = 0; i < size; ++i){
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			capacity = size;
		}
		return; // already equal;
	}
	//clear all dynamic array`s elements
	void clear(){
		delete[] data;
		data = nullptr;
		size = 0;
		capacity = 0;
	}
	//checking whether the array is empty or not
	bool empty(){
		if(size == 0){
			return true;
		}
		return false;
	} 
	//getters
	size_t getSize(){
		return size;
	}

	size_t getCapacity(){
		return capacity;
	}

	//for range-based loop
	T* begin(){
		return data;
	}

	T* end(){
		return data + size;
	}

	private:
	T* data;
	int size;
	int capacity;
};

int main(){
	DynamicArray<int> arr;
	arr.push_back(8);
	arr.push_back(19);

	arr.pop_back();

	if(arr.empty()){
		std::cout << "empty!" << std::endl;
	}else{
		std::cout << "is not empty!" << std::endl;
	}
	
	arr.insert(1, 20);
	arr.insert(10);

	for(const auto& element : arr){
		std::cout << element << " ";
	}
}

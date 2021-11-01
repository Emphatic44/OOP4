#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cassert>


using namespace std;

//Task 1

class ArrayInt {
private:
	int* m_data;
	int m_length;
public:
	ArrayInt() : m_length(0), m_data(nullptr) {};
	ArrayInt(int length) : m_length(length){
		m_data = new int[length];
	}
	
	int size() const {
		return m_length;
	}

	int& operator[] (int index) {
		return m_data[index];
	}

	void deleteLast() {
		assert(m_length != 0);

		int* new_data = new int[m_length - 1];

		for (int i = 0; i < m_length - 1; i++) {
			new_data[i] = m_data[i];
		}
		delete[] m_data;
		m_data = new_data;
		m_length--;
	}

	void deleteFirst() {
		assert(m_length != 0);

		int* new_data = new int[m_length - 1];

		for (int i = 0; i < m_length - 1; i++) {
			new_data[i] = m_data[i + 1];
		}
		delete[] m_data;
		m_data = new_data;
		m_length--;
	}

	void sort() {

		assert(m_length != 0);

		int tempIndex = 0;
		int lastIndex = m_length - 1;
		int temp;

		while (lastIndex > 0) {

			if (m_data[tempIndex] > m_data[tempIndex + 1]) {

				temp = m_data[tempIndex];
				m_data[tempIndex] = m_data[tempIndex + 1];
				m_data[tempIndex + 1] = temp;
			}

			if (tempIndex == lastIndex - 1)
			{
				tempIndex = 0;
				lastIndex--;
			}
			else {
				tempIndex++;
			}
		}
	}

	void print() const {
		assert(m_length != 0);

		for (int i = 0; i < m_length; i++)
		{
			cout << m_data[i] << " ";
		}
		cout << endl;
		
	}

	~ArrayInt() {
		delete[] m_data;
	}

};

//Task2

void printVector(vector<int>& input)
{
	cout << "\n";
	for (vector<int>::iterator it = input.begin(); it != input.end(); ++it)
		cout << *it << " ";
}
int uniqueNumbers(vector<int> input)
{
	sort(input.begin(), input.end());
	vector<int>::iterator it;
	it = unique(input.begin(), input.end());
	input.resize(distance(input.begin(), it));

	return input.size();
}

int main()
{
	//Task 1
	int const size  = 9;
	ArrayInt array(size);

	//int array[size] ={ 4, 8, 12, 7, 9, 8 }; //При попытке задать значения вручную выходит надпись "array: "int[6]" отличается по уровням косвенного обращения от "ArrayInt". С чем это связано?
	for (int j = 0; j < size; j++)
	{
		array[j] = rand() % 100;
	}
	array.deleteFirst();
	array.deleteLast();
	array.print();


	//Task2

	vector<int> arrays = { 8, 800, 2, 2, 5 , 35, 35, 44, 98, 8 };
	cout << "Array: "<< endl;
	printVector(arrays);
	int count = uniqueNumbers(arrays);
	cout << "Uniquie numbers: " << count<< endl;
}

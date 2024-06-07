#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

#include "../include/ScopedTimer.hpp"

bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

std::vector<int> generate_random_vector(size_t const size, int const max = 100) {
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&max]() { return std::rand() % max;} );
    return vec;
}

// Ex 1

void bubble_sort(std::vector<int> & vec)
{
    int temp{0};
    int sortingSize{vec.size()};

    while(!is_sorted(vec))
    {        
        for (int i = 0; i < sortingSize - 1; i++)
        {
            if(vec[i] > vec[i+1])
            {
                temp = vec[i];
                vec[i] = vec[i+1];
                vec[i+1] = temp;
            }
        }

        sortingSize--;
    }
}

// Ex 2

int pivotChoice(std::vector<int>& vec, int left, int right) {
    int middle = left + (right - left) / 2;
    if (vec[left] > vec[middle]) {
        std::swap(vec[left], vec[middle]);
    }
    if (vec[middle] > vec[right]) {
        std::swap(vec[middle], vec[right]);
        if (vec[left] > vec[middle]) {
            std::swap(vec[left], vec[middle]);
        }
    }
    return middle;
}

int quick_sort_partition(std::vector<int> & vec, int left, int right, int pivot);
void quick_sort(std::vector<int> & vec, int const left, int const right);
void quick_sort(std::vector<int> & vec);

int quick_sort_partition(std::vector<int> & vec, int left, int right, int pivot)
{
    int pivotVal = vec[pivot];
    std::swap(vec[pivot], vec[right]);

    int i = left;

    for (int j = left; j < right; j++)
    {
        if(vec[j] < pivotVal)
        {
            std::swap(vec[i], vec[j]);
            i++;
        }
    }

    std::swap(vec[i], vec[right]);
    return i;
}

void quick_sort(std::vector<int> & vec, int const left, int const right)
{
    if(left > right)
        return;
    
    int pivot = quick_sort_partition(vec, left, right, pivotChoice(vec, left, right));

    quick_sort(vec, left, pivot-1);
    quick_sort(vec, pivot+1, right);
}

void quick_sort(std::vector<int> & vec){
    quick_sort(vec, 0, vec.size()-1);
}

// Ex 4

int search(std::vector<int>& vec, int a)
{
    int left{0};
    int right{vec.size()-1};

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if(vec[middle] == a)
            return middle;

        else if(vec[middle] < a)
            left = middle + 1;  

        else
            right = middle - 1; 
    }

    return -1;
}

// Print array

void printArray(std::vector<int>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];

        if(i < vec.size()-1)
            std::cout << ", ";
    }
    std::cout << "\n";
}

// Pour aller plus loin

void counting_sort(std::vector<int> &vec, int const max) {
    std::vector<int> count(max+1, 0);
    
    for(int num : vec) {
        count[num]++;
    }
    
    int index = 0;
    for(int i = 0; i <= max; ++i) {
        while(count[i] > 0) {
            vec[index++] = i;
            count[i]--;
        }
    }
}

int main()
{
    std::vector<int> array = generate_random_vector(1000, 100);

    // Ex 3

    // Bubble Sort : 6.9 ms -> Lent
    {
        ScopedTimer timer("Bubble sort");
        bubble_sort(array);
    }

    // Quick Sort : 0.14 ms -> Significativement plus rapide que Bubble Sort
    {
        ScopedTimer timer("Quick Sort");
        quick_sort(array);
    }

    // STD Sort : 0.08 ms - Un peu plus rapide que Quick Sort
    {
        ScopedTimer timer("STD Sort");
        std::sort(array.begin(), array.end());
    }

    // Ex 4

    std::vector<int> array1 {1, 2, 2, 3, 4, 8, 12};
    std::vector<int> array2 {1, 2, 3, 3, 6, 14, 12, 15};
    std::vector<int> array3 {2, 2, 3, 4, 5, 8, 12, 15, 16};
    std::vector<int> array4 {5, 6, 7, 8, 9, 10, 11, 12, 13};
    std::vector<int> array5 {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "Index of target : " << search(array1, 8) << "\n";
    std::cout << "Index of target : " << search(array2, 15) << "\n"; 
    std::cout << "Index of target : " << search(array3, 16) << "\n";
    std::cout << "Index of target : " << search(array4, 6) << "\n";
    std::cout << "Index of target : " << search(array5, 10) << "\n";

    // Pour aller plus loin

    std::vector<int> vec = {4, 2, 2, 8, 3, 3, 1};
    int max = 8;

    counting_sort(vec, max);

    std::cout << "Tableau trie avec Counting Sort : ";
    printArray(vec);
    
    return 0;
}
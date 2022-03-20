#include <iostream>
#include <cstring>
#include <stdarg.h>
#include "Sort.h"

void Sort::InsertSort(bool ascendent) {
    // a[0..i-1] e sortat si caut locul pentru a[j]
    for(int j = 0; j < count; j++) {
        for(int i = j; i > 0 && nums[i] < nums[i-1]; i--) {
            std::swap(nums[i], nums[i-1]);
        }
    }
}

int Partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int leftwall = low;
    for(int i = low + 1; i < high; i++)
        if(arr[i] < pivot) {
            std::swap(arr[i], arr[leftwall]);
            leftwall++;
        }
    std::swap(pivot, arr[leftwall]);
    return leftwall;
}

void Sort::QuickSort(int low, int high) {
    if(low < high) {
        int pivot_loc = Partition(nums, low, high);
        QuickSort(low, pivot_loc);
        QuickSort(pivot_loc + 1, high);
    }
}

void Sort::BubbleSort(bool ascendent) {
    bool sorted = false;
    int i = 0;
    while(!sorted && i < count) {
        sorted = true;
        for(int j = i + 1; j < count; j++) {
            if(nums[i] > nums[j]) {
                std::swap(nums[i], nums[j]);
                sorted = false;
            }
        }
        i++;
    }
}

void Sort::Print() {
    for(int i = 0; i < count; i++)
        std::cout << nums[i] << " ";
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    if(index >= 0 && index < count)
        return nums[index];
    return -1;
}

Sort::Sort(int count, int min, int max) {
    std::cout << "constr 1" << "\n";
    nums = new int[count];
    this->count=count;
    for(int i = 0; i < count; i++)
        nums[i] = (rand() % max + min) % max;
}

Sort::Sort(int * nums, int count) {
    std::cout << "constr 3" << "\n";
    this->nums = nums;
    this->count = count;
}

Sort::Sort(char *string) {
    std::cout << "constr 5" << "\n";
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++)
        if(string[i] == ',')
            count++;
    this->count =  count + 1;
    this->nums = new int[count] {};
    int k = 0;
    for(int i = 0; string[i] != '\0'; i++)
        if(string[i] == ',') {
            k++;
        } else {
            this->nums[k] = this->nums[k]*10 + (string[i] - '0');
        }
}

Sort::Sort(int count, ...) {
    std::cout << "constr 4" << "\n";
    this->count = count;
    this->nums = new int[count];
    va_list nums;
    va_start(nums, count);
    for(int i = 0; i < count; i++) {
        int val = va_arg(nums, int);
        this->nums[i] = val;
    }
}
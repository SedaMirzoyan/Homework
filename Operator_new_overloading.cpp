
#include <iostream>
#include <cstdlib>

int counter1 = 0;
int counter2 = 0;

void* operator new(size_t size)
{
    void* p = malloc(size);
    counter1++;

    return p;
}

void operator delete(void* p) 
{
    std::cout << "Overloaded Operator delete\n";
    free(p);
}

void* operator new(size_t size, int num)
{
    void* p = calloc(num, size);
    counter2++;

    return p;
}


void* operator new(size_t size, int num1, int num2)
{
    void* p = malloc(size);
    std::cout << "Overloaded new operator with parameters\n";

    return p;
}

void operator delete(void* p, int num1, int num2) 
{
    std::cout << "Overloaded Operator delete with parameters\n";
    free(p);
}


int main()
{
    int* num = new int(7);
    int* num1 = new int(1);

    int* nums = new(1, 2) int;

    std::cout << "counter1 = " << counter1 << std::endl << "counter2 = " << counter2 << std::endl;

    delete num;
    delete num1;

    delete nums;

    return 0;
}


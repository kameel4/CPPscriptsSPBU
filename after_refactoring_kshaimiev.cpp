#include <cmath>
#include <iostream>

int main()
{
    double sequence[10];
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Введите элемент под номером: " << i + 1 << std::endl;
        std::cin >> sequence[i];
    }

    bool is_increasing = true;
    for (int i = 1; i < 10; i++)
    {
        if (sequence[i]<sequence[i-1]){
            is_increasing = false;
            break;
        }
    }
    
    if (is_increasing) {
        std::cout << "Последовательность возрастающая" << std::endl;
    }
    else{
        std::cout << "Последовательность не возрастающая" << std::endl;
    }

    return 0;
}


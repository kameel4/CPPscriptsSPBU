#include <cmath>
#include <iostream>

int main(){
    const int sequence_size = 10;   
    double sequence[sequence_size];
    for (int i = 0; i < sequence_size; i++)
    {
        std::cout << "Введите элемент под номером: " << i + 1 << std::endl;
        std::cin >> sequence[i];
    }

    bool is_increasing = true;
    for (int i = 1; i < sequence_size; i++)
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


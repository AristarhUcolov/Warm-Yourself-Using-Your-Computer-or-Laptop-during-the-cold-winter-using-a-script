#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/sysinfo.h>
#include <unistd.h>
#endif

float get_cpu_temperature() {
    // Функция для получения температуры процессора
    // В Windows, это можно сделать через API, в Linux - через sysfs
    // Здесь необходимо заменить на реализацию в зависимости от ОС
#ifdef _WIN32
    // Заглушка для Windows, потребуется использовать сторонние библиотеки
    return 50.0; // Укажите здесь способ получения температуры
#else
    // Пример для Linux
    FILE *file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (file == nullptr) {
        std::cerr << "Не удалось открыть файл температуры." << std::endl;
        return 0;
    }
    float temp;
    fscanf(file, "%f", &temp);
    fclose(file);
    return temp / 1000; // Приведение к градусам Цельсия
#endif
}

void cpu_stress_test() {
    while (true) {
        float temp = get_cpu_temperature();
        
        if (temp >= 95.0) {
            // Уменьшаем нагрузку
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Температура высокая! Уменьшаем нагрузку..." << std::endl;
        } else if (temp <= 70.0) {
            // Восстанавливаем нагрузку
            std::cout << "Температура в норме! Восстанавливаем нагрузку..." << std::endl;
            for (volatile int i = 0; i < 100000000; ++i) {} // Увеличиваем нагрузку
        } else {
            // Поддерживаем текущую нагрузку
            for (volatile int i = 0; i < 100000000; ++i) {} // Удерживаем нагрузку
        }
    }
}

int main() {
    const int num_cores = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    for (int i = 0; i < num_cores; ++i) {
        threads.emplace_back(cpu_stress_test);
    }

    for (auto &t : threads) {
        t.join(); // Ждём завершения всех потоков
    }

    return 0;
}

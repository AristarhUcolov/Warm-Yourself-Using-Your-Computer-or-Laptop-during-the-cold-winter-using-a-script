#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

float get_cpu_temperature() {
    // Получаем температуру процессора
    FILE *file = fopen("/sys/class/thermal/thermal_zone0/temp", "r");
    if (file == NULL) {
        perror("Не удалось открыть файл температуры");
        return 0;
    }
    
    float temp;
    fscanf(file, "%f", &temp);
    fclose(file);
    return temp / 1000; // Приведение к градусам Цельсия
}

void* cpu_stress_test(void* arg) {
    while (1) {
        float temp = get_cpu_temperature();
        
        if (temp >= 95.0) {
            printf("Температура высокая! Уменьшаем нагрузку...\n");
            sleep(1); // Пауза для снижения нагрузки
        } else if (temp <= 70.0) {
            printf("Температура в норме! Восстанавливаем нагрузку...\n");
            for (volatile int i = 0; i < 100000000; ++i) {} // Увеличиваем нагрузку
        } else {
            for (volatile int i = 0; i < 100000000; ++i) {} // Удерживаем нагрузку
        }
    }
    return NULL;
}

int main() {
    const int num_cores = sysconf(_SC_NPROCESSORS_ONLN);
    pthread_t threads[num_cores];

    for (int i = 0; i < num_cores; ++i) {
        pthread_create(&threads[i], NULL, cpu_stress_test, NULL);
    }

    for (int i = 0; i < num_cores; ++i) {
        pthread_join(threads[i], NULL); // Ждём завершения всех потоков
    }

    return 0;
}

import multiprocessing
import psutil
import time

def cpu_stress_test():
    while True:
        temp = psutil.sensors_temperatures().get('coretemp', [])[0].current
        
        if temp >= 95:
            # Уменьшаем нагрузку
            time.sleep(1)  # Пауза для снижения нагрузки
            print("Температура высокая! Уменьшаем нагрузку...")
        elif temp <= 70:
            # Восстанавливаем нагрузку
            print("Температура в норме! Восстанавливаем нагрузку...")
            for _ in range(1000000):  # Увеличиваем нагрузку
                pass
        else:
            # Поддерживаем текущую нагрузку
            for _ in range(1000000):  # Удерживаем нагрузку
                pass

if __name__ == "__main__":
    num_cores = multiprocessing.cpu_count()
    processes = []

    for _ in range(num_cores):
        p = multiprocessing.Process(target=cpu_stress_test)
        p.start()
        processes.append(p)

    for p in processes:
        p.join()  # Дождаться завершения всех процессов

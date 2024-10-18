#!/bin/bash

while true; do
    # Получение температуры процессора
    temp=$(cat /sys/class/thermal/thermal_zone0/temp)
    temp=$(echo "scale=1; $temp / 1000" | bc)  # Приведение к градусам Цельсия

    echo "Текущая температура: $temp °C"

    if (( $(echo "$temp >= 95.0" | bc -l) )); then
        echo "Температура высокая! Уменьшаем нагрузку..."
        sleep 1  # Пауза для снижения нагрузки
    elif (( $(echo "$temp <= 70.0" | bc -l) )); then
        echo "Температура в норме! Восстанавливаем нагрузку..."
        for ((i=0; i<100000000; i++)); do :; done  # Увеличиваем нагрузку
    else
        for ((i=0; i<100000000; i++)); do :; done  # Удерживаем нагрузку
    fi
done

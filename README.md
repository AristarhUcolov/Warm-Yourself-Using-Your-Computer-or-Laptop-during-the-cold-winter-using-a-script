# 🌞 The Warm PC / Тёплый ПК 🌞

> **[English](#english) | [Русский](#russian)**

---

## English

### 🔥 Warm Yourself Up This Winter!

Use your computer or laptop as a heater during the cold winter months! These scripts generate CPU load to produce heat while intelligently monitoring temperature to prevent overheating.

![image](https://github.com/user-attachments/assets/72baa13c-e53a-4566-9d87-1baea4442fe8)

### ✨ Features

- 🌡️ **Smart Temperature Monitoring** - Automatically adjusts CPU load based on temperature
- 🛡️ **Overheating Protection** - Reduces load when temperature exceeds 95°C
- 💻 **Multi-platform Support** - Works on Windows, Linux, and macOS
- 🔧 **Multiple Languages** - Choose your preferred programming language
- ⚡ **Multi-core Utilization** - Uses all available CPU cores for maximum heat

### 📁 Available Scripts

| File | Language | Platform |
|------|----------|----------|
| `warm.py` | Python | Cross-platform (requires `psutil`) |
| `warm.bat` | Batch | Windows |
| `warm.sh` | Bash | Linux |
| `warm_mac.sh` | Bash | macOS |
| `warm.cpp` | C++ | Cross-platform |
| `warm.cs` | C# | Linux (uses sysfs) |
| `warm.java` | Java | Linux (uses sysfs) |

### 🚀 Usage

#### Python (Cross-platform)
```bash
pip install psutil
python warm.py
```

#### Windows (Batch)
```cmd
warm.bat
```

#### Linux (Bash)
```bash
chmod +x warm.sh
./warm.sh
```

#### macOS
```bash
chmod +x warm_mac.sh
./warm_mac.sh
```

#### C++
```bash
# Linux
g++ -o warm warm.cpp -lpthread
./warm

# Windows (with MinGW)
g++ -o warm.exe warm.cpp
warm.exe
```

#### Java
```bash
javac warm.java
java CpuStressTest
```

### ⚠️ Safety Warning

> **Use at your own risk!** These scripts intentionally stress your CPU to generate heat.
>
> - 🔥 Monitor your system temperatures regularly
> - 💨 Ensure proper ventilation and airflow
> - 🧹 Keep your computer's cooling system clean
> - ⏱️ Don't run for extended periods unattended
> - 🔌 Be aware of increased power consumption

### 🔧 How It Works

The scripts use a simple temperature-based algorithm:

1. **Temperature ≤ 70°C** → Increase CPU load (safe zone)
2. **Temperature 70-95°C** → Maintain current load
3. **Temperature ≥ 95°C** → Reduce load to prevent damage

### 👤 Author

**Aristarh Ucolov (Аристарх Уколов)**

---

## Russian

### ❄️ Согрейся Этой Зимой!

Используй свой компьютер или ноутбук как обогреватель в холодные зимние месяцы! Эти скрипты создают нагрузку на процессор для выделения тепла, при этом интеллектуально отслеживая температуру для предотвращения перегрева.

![image](https://github.com/user-attachments/assets/0b190f9b-6c83-4bad-818e-038841197590)

### ✨ Особенности

- 🌡️ **Умный мониторинг температуры** - Автоматически регулирует нагрузку на CPU
- 🛡️ **Защита от перегрева** - Снижает нагрузку при температуре выше 95°C
- 💻 **Мультиплатформенность** - Работает на Windows, Linux и macOS
- 🔧 **Множество языков** - Выберите предпочитаемый язык программирования
- ⚡ **Использование всех ядер** - Задействует все ядра CPU для максимального нагрева

### 📁 Доступные скрипты

| Файл | Язык | Платформа |
|------|------|-----------|
| `warm.py` | Python | Кроссплатформенный (требует `psutil`) |
| `warm.bat` | Batch | Windows |
| `warm.sh` | Bash | Linux |
| `warm_mac.sh` | Bash | macOS |
| `warm.cpp` | C++ | Кроссплатформенный |
| `warm.cs` | C# | Linux (использует sysfs) |
| `warm.java` | Java | Linux (использует sysfs) |

### 🚀 Использование

#### Python (Кроссплатформенный)
```bash
pip install psutil
python warm.py
```

#### Windows (Batch)
```cmd
warm.bat
```

#### Linux (Bash)
```bash
chmod +x warm.sh
./warm.sh
```

#### macOS
```bash
chmod +x warm_mac.sh
./warm_mac.sh
```

#### C++
```bash
# Linux
g++ -o warm warm.cpp -lpthread
./warm

# Windows (с MinGW)
g++ -o warm.exe warm.cpp
warm.exe
```

#### Java
```bash
javac warm.java
java CpuStressTest
```

### ⚠️ Предупреждение о безопасности

> **Используйте на свой страх и риск!** Эти скрипты намеренно нагружают процессор для выделения тепла.
>
> - 🔥 Регулярно следите за температурой системы
> - 💨 Обеспечьте надлежащую вентиляцию
> - 🧹 Содержите систему охлаждения в чистоте
> - ⏱️ Не запускайте на длительное время без присмотра
> - 🔌 Учитывайте повышенное энергопотребление

### 🔧 Как это работает

Скрипты используют простой алгоритм на основе температуры:

1. **Температура ≤ 70°C** → Увеличиваем нагрузку (безопасная зона)
2. **Температура 70-95°C** → Поддерживаем текущую нагрузку
3. **Температура ≥ 95°C** → Снижаем нагрузку для предотвращения повреждений

### 👤 Автор

**Аристарх Уколов (Aristarh Ucolov)**

---

## 🤝 Contributing / Участие

Contributions are welcome! Feel free to submit issues and pull requests.

Приветствуются любые предложения! Не стесняйтесь создавать issues и pull requests.

---

## 📝 License / Лицензия

This project is open source. / Этот проект с открытым исходным кодом.

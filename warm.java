import java.io.BufferedReader;
import java.io.InputStreamReader;

public class CpuStressTest {

    public static float getCpuTemperature() {
        try {
            ProcessBuilder pb = new ProcessBuilder("cat", "/sys/class/thermal/thermal_zone0/temp");
            Process process = pb.start();
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line = reader.readLine();
            if (line != null) {
                return Float.parseFloat(line) / 1000; // Приведение к градусам Цельсия
            }
        } catch (Exception e) {
            System.err.println("Не удалось получить температуру: " + e.getMessage());
        }
        return 0;
    }

    public static void cpuStressTest() {
        while (true) {
            float temp = getCpuTemperature();

            if (temp >= 95.0) {
                System.out.println("Температура высокая! Уменьшаем нагрузку...");
                try {
                    Thread.sleep(1000); // Пауза для снижения нагрузки
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            } else if (temp <= 70.0) {
                System.out.println("Температура в норме! Восстанавливаем нагрузку...");
                for (volatile int i = 0; i < 100000000; i++); // Увеличиваем нагрузку
            } else {
                for (volatile int i = 0; i < 100000000; i++); // Удерживаем нагрузку
            }
        }
    }

    public static void main(String[] args) {
        int numCores = Runtime.getRuntime().availableProcessors();
        Thread[] threads = new Thread[numCores];

        for (int i = 0; i < numCores; i++) {
            threads[i] = new Thread(CpuStressTest::cpuStressTest);
            threads[i].start();
        }

        for (int i = 0; i < numCores; i++) {
            try {
                threads[i].join(); // Ждём завершения всех потоков
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}

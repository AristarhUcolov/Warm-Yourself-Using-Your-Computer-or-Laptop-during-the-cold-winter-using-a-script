@echo off
setlocal enabledelayedexpansion

:loop
rem Получение температуры процессора
for /f "skip=1" %%i in ('wmic path win32_perfformatteddata_thermalthermalzone get currenttemperature') do (
    set temp=%%i
    set /a temp=!temp! / 10 - 273
)

echo Текущая температура: !temp! °C

if !temp! GEQ 95 (
    echo Температура высокая! Уменьшаем нагрузку...
    timeout /t 1 >nul
) else if !temp! LEQ 70 (
    echo Температура в норме! Увеличиваем нагрузку...
    for /L %%j in (1,1,10000000) do (
        set /a x=%%j
    )
) else (
    echo Поддерживаем текущую нагрузку...
    for /L %%j in (1,1,10000000) do (
        set /a x=%%j
    )
)

goto loop

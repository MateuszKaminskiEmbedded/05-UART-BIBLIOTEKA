# 05-UART-BIBLIOTEKA

Biblioteka umożliwia komunikację poprzez UART. Zawiera dwie funkcje. Pierwsza z nich inicjalizuje komunikację ustawiając niezbędne wartości konfiguracyjne. Druga funkcja daje możliwość wysłania danych przez magistralę. Wysyła dane do strumienia wyjściowego, dzięki czemu używając biblioteki stdio.h można wysłać dane funkcją printf(„”).

UART.h
Zawiera deklaracje obu funkcji.

UART.c
Zawiera definicje funkcji. Potrzebuje stałej SYS_FREQ, która przechowuje wartość częstotliwości taktowania mikrokontrolera. W funkcji UART_Init() można ustawić parametry komunikacji.

main.c
Zawiera konfigurację pinów używanych przez moduł UART.

W celu użycia biblioteki, należy:
1) Dodać pliki do projektu
2) W razie potrzeby zmienić parametry pracy magistrali (w pliku UART.c)
3) Magistrala jest gotowa do wysyłania danych przy użyciu printf().

UWAGA 1
Mikrokontroler można połączyć z komputerem poprzez konwerter łącząc Tx mikrokontrolera z Rx konwertera i analogicznie Rx mikrokontrolera z Tx konwertera.

UWAGA 2
Podczas budowania programu może pojawić się błąd dotyczący rozmiaru sterty. W takim przypadku należy we właściwościach projektu ręcznie ustawić rozmiar sterty w bajtach.
![image](https://user-images.githubusercontent.com/104322532/199330062-3e3fb2ce-9d71-4053-bb04-200bc3552f7b.png)

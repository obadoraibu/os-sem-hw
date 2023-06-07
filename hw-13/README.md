# Домашнее задание 13
Написание на языке C, прогон и компиляция программы, определяющей глубину рекурсии для символьных связей при открытии файлов.

Примечание. Глубина рекурсии для символических связей может отличаться от системы к системе и в рамках одной системы быть разной для различных операций. Встречались значения 8 и 41. Могут быть и другие, зависящие от операции. Поэтому в задаче предполагается конкретная операция открытия файлов.

Предлагается следующий алгоритм решения.

Условие задачи. Необходимо написать программу, определяющую глубину рекурсии для символьных связей при открытии файлов. При запуске программа создает некоторый регулярный файл, допустим, с именем «а». Затем создается символьная связь с именем, например, «aa» на файл «a» и делается попытка открыть файл аа». Если это удалось, то создается символьная связь с именем, например, «ab» на файл «aa» и делается попытка открыть файл «ab». И так далее, пока открыть файл не удастся. Это и будет означать, что достигнyта глубина рекурсии (количества допустимых символьных связей) при открытии файла. Значение глубины рекурсии должно быть выведено на экран.

Рекомендуется создание всех файлов проводить в отдельной директории, чтобы в случае ошибки можно было легко удалить большое количество образовавшихся файлов. Не забывайте проверять возвращаемые значения из системных вызовов и своевременно закрывать файлы!



## Сборка и запуск

1. `gcc -o main main.c`
2. `./main`


### ![Иллюстрация](https://github.com/obadoraibu/os-sem-hw/blob/main/hw-13/1.png)
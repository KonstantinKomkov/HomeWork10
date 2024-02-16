#include <stdio.h>
#include <locale.h>

int write_file (FILE *f, int size, char array[]) // Запись в файл
{
	int i;
	for (i = 0; i < size; i++)
	{
		fprintf (f, "%c", array[i]);
	}
	return i;
}

int read_file (FILE *f, int size, char array[]) // Чтение файла
{
	int i;
	for (i = 0; i < size; i++)
	{
		fscanf (f, "%c", &array[i]);
	}
	return i;
}

int input_array (char array[]) // Считывание введенного массива
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n')
	{
		array[i] = c;
		i++;
	}
	return i;
}

void find_long_word (int size, char array[]) // Поиск самого длинного слова
{
	int counter = 0, max = 0, flag = 0;
	for (int i = 0; i < size; i++) 
	{
		if (array[i] == ' ' || i == (size - 1))
		{
			if (counter > max)
			{
				max = counter;
				flag = i;
			}
			counter = 0;
		}
		else
		{
			counter++;
		}
	}
	for (int i = (flag - max); i <= flag; i++)
	{
		printf("%c", array[i]); // Печатаем массив
	}
}

int main (void)
{
	FILE *f;
	char array[1000], *pa, *filename = "taskG10.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите строку из английских букв и пробелов. Не более 1000 символов.");
	printf("Данные на входе: ");
	n = input_array(pa);
	f = fopen(filename, "w+");
	write_file(f, n, pa);
	fclose(f);
	printf("Запись введенных данных в файл %s\n", filename);
	f = fopen(filename, "r");
	read_file(f, n, pa);
	fclose(f);
	printf("Данные на выходе: ");
	find_long_word(n, pa);
	return 0;
}
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

void sort_rise_array (int size, int array[]) // Сортировка массива по возрастанию 
{
	int value;
	do
	{
		for (int j = 0; j < size; j++)
		{
			if (array[j] > array[j+1])
			{
				value = array[j];
				array[j] = array[j + 1];
				array[j + 1] = value;
			}
		}
		size--;
	} while (size >= 0);
}

void find_numbers (int size, char array[]) // Поиск введенных чисел и упаковка их в новый int массив
{
	int mas[size];
	int value = 0, j = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] >= '0' && array[i] <= '9')
		{
			value = value*10 + array[i] - '0';
			if (array[i+1] <= '0' || array[i+1] >= '9')
			{
				mas[j] = value;
				j++;
				value = 0;
			}
		}
	}
	sort_rise_array (j-1, mas); // Сортировка массива по возрастанию 
	for (int i = 0; i < j; i++)
	{
		printf("%d ", mas[i]); // Печатаем массив
	}
}

int main (void)
{
	FILE *f;
	char array[100], *pa, *filename = "taskG8.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите строку из английских букв, цифр и знаков препинания");
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
	find_numbers(n, pa);
	return 0;
}
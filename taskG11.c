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

int word_end_a (int size, char array[]) // Заканчивается на а
{
	int counter = 0;
	for (int i = 0; i < size; i++) 
	{
		if (array[i] == 'a' && (array[i+1] == ' ' || i == (size - 1)))
		{
			counter++;
		}
	}
	return counter;
}

int main (void)
{
	FILE *f;
	char array[1000], *pa, *filename = "taskG11.txt";
	int n;
	pa = array;
	setlocale(LC_ALL, "ru_RU.UTF-8");
	puts("Введите строку из английских букв и пробелов не более 1000 символов.");
	printf("Данные на входе: ");
	n = input_array(pa);
	f = fopen(filename, "w+");
	write_file(f, n, pa);
	fclose(f);
	printf("Запись введенных данных в файл %s\n", filename);
	f = fopen(filename, "r");
	read_file(f, n, pa);
	fclose(f);
	printf("Данные на выходе: %d", word_end_a(n, pa));
	printf("\nЗапись количества букв 'а' в файл taskG11new.txt");
	f = fopen("taskG11new.txt", "w+");
	fprintf(f, "%d", word_end_a(n, pa));
	fclose(f);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inputArray(int *arr, int size);// генерує випадкове число в діапазоні від -100 до 100. 
void printArray(int *arr, int size);//виведення елементів 
int countPositiveElements(int *arr, int size);//перевіряє кількість додатніх ел.
int calculateProduct(int *arr, int size);//знаходить індекс мін. за модулем значення та продовжує розрахунок добутку елементів масиву. 

int main() {
    int n;
    printf("Введіть розмір масиву: ");
    scanf("%d", &n);

    int *array = (int*)malloc(n * sizeof(int));//виділення пам'яті для масиву array
    if (array == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }//повідомлення про виникнення помилки

    srand(time(0)); // Ініціалізація генератора випадкових чисел
    inputArray(array, n);//заповнює масив випадковими числами
    printf("Введений масив: ");
    printArray(array, n);//виведення ел. масиву

    int countPositives = countPositiveElements(array, n);//кк. додат. номерів
    printf("Кількість додатних елементів: %d\n", countPositives);

    int product = calculateProduct(array, n);//добуток ел. масиву
    printf("Добуток елементів до мінімального за модулем елемента: %d\n", product);

    free(array);//звільнення пам'яті
    return 0;
}
// функція генерує випадкове число в діапазоні від -100 до 100.
void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201 - 100; 
    }
}
//- функція виводить елементи
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//функція обчислює кількість додатних елементів в масиві.
int countPositiveElements(int *arr, int size) {
    int count = 0;//кк. додатніх елементів
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            count++;
        }
    }
    return count;
}
// функція обчислює добуток елементів масиву, розташованих до мінімального за модулем елемента.
int calculateProduct(int *arr, int size) {
    int minIndex = 0;//індекс мінімального за модулем елемента.
    for (int i = 1; i < size; i++) {
        if (abs(arr[i]) < abs(arr[minIndex])) {
            minIndex = i;
        }
    }

    int product = 1;
    for (int i = 0; i < minIndex; i++) {
        product *= arr[i];//множення
    }
    return product;
}
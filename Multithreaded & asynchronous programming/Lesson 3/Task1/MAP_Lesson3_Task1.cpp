#include <iostream>
#include <future>

using namespace std;

void find_smallest_element(int arr[], int size, int start_position, promise<int> prom)
{
    int smallest_position = start_position;
    for (int i = start_position; i < size; ++i)
    {
        if (arr[i] < arr[smallest_position])
        {
            smallest_position = i;
        }
    }
    prom.set_value(smallest_position);
}

void selection_sort(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        promise<int> prom;
        future<int> f = prom.get_future();
        async(find_smallest_element, arr, size, i, move(prom));
        f.wait();
        int smallest_position = f.get();
        swap(arr[i], arr[smallest_position]);
    }
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int arr[] = { 5, 7, 9 ,13, 56, 0, 21, -4, 12, -5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Начальный массив: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    selection_sort(arr, size);

    cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
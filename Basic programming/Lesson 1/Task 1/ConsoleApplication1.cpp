#include <iostream>
#include <fstream>


int main(int argc, char** argv)
{
    std::string fileName = "in.txt";
    std::ifstream fin(fileName);
    std::ofstream fout("out.txt");

    if(!fin.is_open())
    {
        std::cout << "Файл не найден!\n";
        return 1;
    }

    int N = 0;
    fin >> N;
    int* arrN = new int[N];

    for (int i = 0; i < N; ++i)
    {
        fin >> arrN[i];
    }

    int M = 0;
    fin >> M;
    int* arrM = new int[M];

    for (int i = 0; i < M; ++i)
    {
        fin >> arrM[i];
    }

    fout << M << std::endl;
    fout << arrM[M - 1] << " ";
    for (int i = 0; i < M - 1; ++i)
    {
        fout << arrM[i] << " ";
    }
    fout << std::endl;

    fout << N << std::endl;
    for (int i = 1; i < N; ++i)
    {
        fout << arrN[i] << " ";
    }
    fout << arrN[0];

    fin.close();
    fout.close();
    delete[]arrN;
    arrN = nullptr;
    delete[]arrM;
    arrM = nullptr;
    return 0;
}
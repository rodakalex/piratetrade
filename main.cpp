#include "vector"
#include <iostream>
#include <c++/4.8.3/sstream>
#include <c++/4.8.3/fstream>
#include <c++/4.8.3/iterator>

using namespace std;

struct inputParam {
    int id;         // Идентификатор ордера
    int instr;      // Идентификатор инструмента
    int count;      // Количество в ордере
    int amount;     // Оставшееся количество в ордере
    int res1;       // Зарезервировано (всегда 0)
    int action;     // Действие (0 - удаление, 1 - добавление, 2 – исполнение)
    int vec;        // Направление (0 - покупка, 1 - продажа)
    int custom;     // Цена ордера
    int dealCost;   // Цена сделки
    int res2;       // Зарезервировано (пустая запись)
    int res3;       // Зарезервировано (пустая запись)
    int date;       // Дата GMT+3 (%4Y%m%d)
    int time;       // Время GMT+3 (%H%M%S%3N)
    int flag;       // Битовый флаги - различные признаки записи, выраженные в десятичном представлении 64-битного числа
    int deal;       // Идентификатор сделки (если нет то 0)
};


int main() {
    freopen("test.log/test.log", "r", stdin);
    inputParam line;
    string tmp = "";
    int index = 0;

    while(getline(cin, tmp, '\t')){
        long long x = 25567940313089;

        cout << x << endl;
        index++;
        if(index == 1) {
            break;
        }
    }

    return 0;
}


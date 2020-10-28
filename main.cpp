#include "vector"
#include <iostream>

using namespace std;

struct inputParam {
    unsigned long id;    // 1. Идентификатор ордера
    int instr;           // 2. Идентификатор инструмента
    int count;           // 3. Количество в ордере
    int amount;          // 4. Оставшееся количество в ордере
    int res1;            // 5. Зарезервировано (всегда 0)
    int action;          // 6. Действие (0 - удаление, 1 - добавление, 2 – исполнение)
    int vec;             // 7. Направление (0 - покупка, 1 - продажа)
    int custom;          // 8. Цена ордера
    int dealCost;        // 9. Цена сделки
    int res2;            // 10. Зарезервировано (пустая запись)
    int res3;            // 11. Зарезервировано (пустая запись)
    int date;            // 12. Дата GMT+3 (%4Y%m%d)
    int time;            // 13. Время GMT+3 (%H%M%S%3N)
    int flag;            // 14. Битовый флаги - различные признаки записи, выраженные в десятичном представлении 64-битного числа
    int deal;            // 15. Идентификатор сделки (если нет то 0)
};

inputParam func(string *line) {
    inputParam o{
        static_cast<unsigned long>(stol(line[0])),
    };
    return o;
};

int main() {
    freopen("./test.log", "r", stdin);
    string tmp;
    int index = 0;
    string line[15];

    while(getline(cin, tmp, '\t')){
        line[index] = tmp;

        if(index == 14) {
            break;
        }
        index++;
    }
//    inputParam o = func(line);
    return 0;
}


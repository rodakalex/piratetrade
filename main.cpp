#include "vector"
#include <iostream>

using namespace std;

struct inputParam {
    unsigned long id;    // 1. Идентификатор ордера
    int instr;           // 2. Идентификатор инструмента
    short count;         // 3. Количество в ордере
    short amount;        // 4. Оставшееся количество в ордере
    short action;        // 5. Действие (0 - удаление, 1 - добавление, 2 – исполнение)
    bool vec;            // 6. Направление (0 - покупка, 1 - продажа)
    double custom;       // 7. Цена ордера
    double dealCost;     // 8. Цена сделки
    int date;            // 9. Дата GMT+3 (%4Y%m%d)
    long time;           // 10. Время GMT+3 (%H%M%S%3N)
    int flag;            // 11. Битовый флаги - различные признаки записи, выраженные в десятичном представлении 64-битного числа
    bool deal;           // 12. Идентификатор сделки (если нет то 0)
};

inputParam func(string *line) {
    inputParam fLine{
        static_cast<unsigned long>(stol(line[0])),
        stoi(line[1]),
        static_cast<short>(stoi(line[2])),
        static_cast<short>(stoi(line[3])),
        static_cast<bool>(stoi(line[4])),
        static_cast<bool>(stoi(line[5])),
        static_cast<double>(stoi(line[6])),
        static_cast<double>(stoi(line[7])),
        static_cast<int>(stoi(line[8])),
        static_cast< long>(stol(line[12])),
        stoi(line[13]),
        static_cast<bool>(stoi(line[14]))
    };
    return fLine;
};

inputParam getStructFromLine() {
        string tmp;
        string line[15];

        int index = 0;
        while(getline(cin, tmp, '\t')){
            line[index] = tmp;
            if(index == 14) {
                return func(line);
            }
            index++;
        }

};

int main() {
    int x = 0;
    freopen("./test.log", "r", stdin);
    inputParam fline;

    while(x != 10) {
        fline = getStructFromLine();
        x++;
    }

    return 0;
}


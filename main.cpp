#include <map>
#include <vector>
#include <iostream>

struct structOfLine {
    unsigned long id;    // 1. Идентификатор ордера
    int instr;           // 2. Идентификатор инструмента
    short count;         // 3. Количество в ордере
    short amount;        // 4. Оставшееся количество в ордере
                         // 5. Зарезервировано (всегда 0)
    short action;        // 6. Действие (0 - удаление, 1 - добавление, 2 – исполнение)
    bool vec;            // 7. Направление (0 - покупка, 1 - продажа)
    double custom;       // 8. Цена ордера
    double dealCost;     // 9. Цена сделки
    int date;            // 10. Дата GMT+3 (%4Y%m%d)
    long time;           // 11. Время GMT+3 (%H%M%S%3N)
    int flag;            // 12. Битовый флаги - различные признаки записи, выраженные в десятичном представлении 64-битного числа
    bool deal;           // 13. Идентификатор сделки (если нет то 0)
};

structOfLine getStructFromLine() {

    std::string tmp;
    std::string line[15];

    int index = 0;
    while(getline(std::cin, tmp, '\t')) {
        line[index] = tmp;
        if (index == 14) {
            structOfLine fLine{
                static_cast<unsigned long>(stol(line[0])),
                static_cast<int>(stoi(line[1])),
                static_cast<short>(stoi(line[2])),
                static_cast<short>(stoi(line[3])),
                static_cast<bool>(stoi(line[4])),
                static_cast<bool>(stoi(line[5])),
                static_cast<double>(stoi(line[7])),
                static_cast<double>(stoi(line[8])),
                static_cast<int>(stoi(line[11])),
                static_cast< long>(stol(line[12])),
                static_cast<int>(stoi(line[13])),
                static_cast<bool>(stoi(line[14]))
            };
            return fLine;
        }
        ++index;
    }
};

int main() {
    int x = 0;
    freopen("./test.log", "r", stdin);
    structOfLine fline;

    std::map <short,double> Orderbook;

    while(x != 10) {
        fline = getStructFromLine();
        Orderbook[fline.custom] = fline.count;
        ++x;
    }

    return 0;
}


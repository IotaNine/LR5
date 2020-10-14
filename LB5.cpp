#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;
void Proverka(pair<int, string> n)
{
    cout << "Ключ: " << n.first << " \t" << "Значение: " << n.second << "\n";
}
void Vivod(int x)
{
    cout << x << ", ";
}
bool Pravilo1(pair<int, string> n)
{
    return(n.first > 4);
}
bool Pravilo2(int x)
{
    return(x < 0);
}
bool Pravilo3(int x, int y)
{
    return(x > y);
}
int FromMap(pair<int, string> n)
{
    return(n.first);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unordered_multimap<int, string> map1({ {6,"ONE"}, {-3,"TWO"}, {-3,"THREE"}, {-7,"FOUR"}, {-2,"FIVE"}, {5,"SIX"}, {8,"SEVEN"}, {-1,"EIGHT"} });
    map1.insert(make_pair(-4, "NINE"));
    map1.insert(make_pair(-4, "TEN"));
    map1.insert(make_pair(-4, "ELEVEN"));
    for_each(map1.begin(), map1.end(), Proverka); cout << "\n";
    cout << "\t" << "End of 1.1" << "\n" << "\n";
    bool IsNextStep = true;
    for (auto i = map1.begin(); i != map1.end();)
    {
        if (!IsNextStep) 
        {
            IsNextStep = true;
        }
        if (i->first == -3)
        {
           i = map1.erase(i);
           IsNextStep = false;
        }
        if (IsNextStep)
        {
            i++;
        }
    }
    for_each(map1.begin(), map1.end(), Proverka); cout << "\n";
    cout << "\t" << "End of 1.2" << "\n" << "\n";
    map<int, string> map2;
    for (auto i : map1)
    {
        map2.insert(make_pair(i.first, i.second));
    }
    for_each(map2.begin(), map2.end(), Proverka); cout << "\n";
    cout << "\t" << "End of 1.3" << "\n" << "\n";
    auto Kolvo = count_if(map2.begin(), map2.end(), Pravilo1);
    cout << "Количестов элементов с ключами >4 : " << Kolvo << "\n" << "\n";
    cout << "\t" << "End of 2.1" << "\n" << "\n";
    vector<int> vec2;
    transform(map2.begin(), map2.end(), back_inserter(vec2), FromMap);
    for_each(vec2.begin(), vec2.end(), Vivod); cout << "\n" << "\n";
    cout << "\t" << "End of 2.2" << "\n" << "\n";
    auto result1 = find(vec2.begin(), vec2.end(), 0);
    if (result1 == vec2.end())
    {
        cout << "Элемент не найден";
    }
    else
    {
        cout << "Элемент найден";
    }
    cout << "\n" << "\n";
    cout << "\t" << "End of 3.1" << "\n" << "\n";
    replace_if(vec2.begin(), vec2.end(), Pravilo2, 3);
    for_each(vec2.begin(), vec2.end(), Vivod); cout << "\n" << "\n";
    cout << "\t" << "End of 3.2" << "\n" << "\n";
    sort(vec2.begin(), vec2.end(), Pravilo3);
    for_each(vec2.begin(), vec2.end(), Vivod); cout << "\n" << "\n";
    cout << "\t" << "End of 3.3" << "\n" << "\n";
    set<int> set2;
    for (auto i : vec2)
    {
        set2.insert(i);
    }
    for_each(set2.begin(), set2.end(), Vivod); cout << "\n" << "\n";
    cout << "\t" << "End of 3.3" << "\n" << "\n";
}    
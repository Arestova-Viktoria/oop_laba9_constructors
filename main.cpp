#include <iostream>
#include <cstring>

using namespace std;

class date{
private:
    int day;
    int year;
    int month;
public:
    date(){ //без параметров
        day = 31;
        month = 12;
        year = 2020;
    }
    date(int year){ //с одним параметром
        this->year = year;
        month = 12;
        day = 31;
    }
    date(int day, int month, int year){ //со всеми параметрами
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void output_date_postavk();
    int Read_Int();
    //void Init(int day,int month,int year);
    void Display();
    int Add(date a,date b);
    int get_year();
    date& operator=(const date &icecream_date);
};
class icecream {
private:
    int id;
    static int id_gener;
    string name;
    int massa;
    int milk;
    int expiration_date, chocolate;
    string country;
    date date_post;
    char* data;
public:
    icecream(){
        name = "IceBerg";
        massa = 400;
        milk = 300;
        expiration_date = 120;
        chocolate = 0;
        country = "Germany";
        date_post = date();
        char new_string[] = "Welcome";
        data=new char(strlen(new_string)-1);
        strcpy(data,new_string);
    }
    icecream(string name){
        this->name = name;
        massa = 400;
        milk = 300;
        expiration_date = 120;
        chocolate = 0;
        country = "Germany";
        date_post = date();
    }
    icecream(string name, int massa, int milk, int expiration_date, int chocolate, string country, int day, int month, int year){
        this->name = name;
        this->massa = massa;
        this->milk = milk;
        this->expiration_date = expiration_date;
        this->chocolate = chocolate;
        this->country = country;
        date_post = date(day,month,year);
    }
    icecream(const icecream &ice){  //конструктор копии
        name = ice.name;
        massa = ice.massa;
        milk = ice.milk;
        expiration_date = ice.expiration_date;
        chocolate = ice.chocolate;
        country = ice.country;
        /*if(ice.data){
            char new_string[]="Welcome";
            data=new char(strlen(new_string)-1);
            strcpy(data,new_string);
        }
        else data=0;*/
    }

    icecream& operator= (const icecream &ice){
        name = ice.name;
        massa = ice.massa;
        milk = ice.milk;
        expiration_date = ice.expiration_date;
        chocolate = ice.chocolate;
        country = ice.country;
        date_post = ice.date_post;
        /*if(this==&ice)
            return *this;
        delete[] data;
        if(ice.data){
            char new_string[] = "Welcome";
            data = new char(strlen(new_string)-1);
            strcpy(data,new_string);
        }
        else data = 0;*/
        return *this;
    }

    ~icecream(){
        delete[] data;
    }

    string Read_String();
    int Read_Int();
    void Display();
    //void Init(string name, int massa, int milk, int expiration_date, int chocolate, string country, int day, int month, int year);
    int Add(icecream a, icecream b);
    void Country();
    void Sod_Chocolate();
    void output_date_postavk();
    int& get_massa();
    void get_milk(int *icecream_milk);
    friend void Display_name(icecream& icecream_a);
    friend icecream operator+(const icecream &p_1,const icecream &p_2);  //добавлено
    icecream& operator++();  //добавлено
    icecream operator++(int);  //добавлено
    int one(icecream *p);
    //int two();
    int get_id();
    static int get_id_now();
    char* get_data();

};
int icecream::id_gener = 1;

int icecream::get_id(){
    id = id_gener++;
    return id;
}
//статический метод для получения значения текущего ID без создания объекта класса

int icecream::get_id_now(){
    return id_gener;
}
icecream operator+(const icecream &p_1,const icecream &p_2){
    icecream p_3;
    p_3.massa=p_1.massa+p_2.massa;
    return p_3;
}
icecream& icecream::operator++(){ //постфикс
    massa++;
    return *this;
}
icecream icecream::operator++(int temp){ //префикс
    icecream p_2;
    p_2.massa=temp;
    ++(*this);
    return p_2;
}
string icecream::Read_String(){
    string str;
    getline(cin,str);
    return str;
}
void date::Display() {
    cout << "Day:" << day << endl;
    cout << "Month:" << month << endl;
    cout << "Year:" << year << endl;
}
void icecream::Display() {
    cout<<"Name:"<<name<<endl;
    cout<<"Massa:"<<massa<<endl;
    cout<<"Chocolate:";
    if (chocolate == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cout<<"Milk:"<<milk<<endl;
    cout<<"Exp.Date:"<<expiration_date<<endl;
    cout<<"Country:"<<country<<endl;
    date_post.Display();
    cout<<" "<<endl;
}
int date::Add(date d1, date d2) {
    date d3;
    d3.year = d1.year + d2.year;
    return d3.year;
}
int icecream::Add(icecream ice1, icecream ice2) {
    icecream ice3;
    ice3.massa = ice1.massa + ice2.massa;
    return ice3.massa;
}

int icecream::Read_Int() {
    int c;
    cin >> c;
    return c;
}
int date::Read_Int() {
    int c;
    cin >> c;
    return c;
}
/*void date::Init(int x, int y, int k) {
    day = x;
    month = y;
    year = k;
}*/
/*void icecream::Init(string nazv, int mas, int sod_milk, int ex_date, int ch, string c, int x, int y, int k) {
    name = nazv;
    massa = mas;
    milk = sod_milk;
    expiration_date = ex_date;
    chocolate = ch;
    country = c;
    date_post.Init(x, y, k);
}*/
void icecream::Country() {
    cout << country;
}
void icecream::Sod_Chocolate() {
    cout<<"Chocolate:";
    if (chocolate == 1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
void date::output_date_postavk() {
    cout << day << "." << month << "." << year << endl;
}
void icecream::output_date_postavk() {
    date_post.output_date_postavk();
}
int& icecream::get_massa(){
    return massa;
}
void icecream::get_milk(int *milk_ice){
    *milk_ice=milk;
}
void Display_name(icecream &icecream_a){
    cout<<icecream_a.name;
}

int date::get_year(){
    return year;
}
char* icecream::get_data(){
    return data;
}
date& date::operator=(const date &icecream_date){
    day = icecream_date.day;
    month = icecream_date.month;
    year = icecream_date.year;
    return *this;
}

int main()
{
    //icecream ice1,ice2;
    string str_1 = "Slastena";
    string str_2 = "Russia";
    int m = 250;
    int mil = 100;
    int ex = 60;
    int ch = 1;
    int x = 12;
    int y = 10;
    int k = 2020;
    //ice1.Init(str_1, m, mil, ex, ch, str_2, x, y, k);

    //вызов всех конструкторов
    cout<<"Calling all constructors:"<<endl<<endl;

    icecream ice1;
    ice1.Display();
    icecream ice2("Milka");
    ice2.Display();
    icecream ice3(str_1, m, mil, ex, ch, str_2, x, y, k);
    ice3.Display();

    str_1 = "Fixiki";
    str_2 = "Usa";
    m = 120;
    mil = 98;
    ex = 90;
    ch = 0;
    x = 31;
    y = 12;
    k = 2020;


    //вызов всех конструкторов со статическими объектами
    cout<<"Calling all constructors with static objects"<<endl;
    static icecream static_ice1;
    static_ice1.Display();
    static icecream static_ice2("Limon Ice");
    static_ice2.Display();
    static icecream static_ice3(str_1, m, mil, ex, ch, str_2, x, y, k);
    static_ice3.Display();

    //вызов конструкторов с динамическими объектами
    cout<<"Calling all constructors with dynamic objects"<<endl;
    icecream *dynamic_ice1 = new icecream();
    dynamic_ice1->Display();
    icecream *dynamic_ice2 = new icecream("Milka");
    dynamic_ice2->Display();
    icecream *dynamic_ice3 = new icecream(str_1, m, mil, ex, ch, str_2, x, y, k);
    dynamic_ice3->Display();

    //инициализация массива конструктором с 1 параметром
    cout<<"Initializing an array with 1 parameter constructor"<<endl;
    icecream massiv[3];
    string m1 = "Ice 1";
    string m2 = "Ice 2";
    string m3 = "Ice 3";
    massiv[0] = icecream(m1);
    massiv[1] = icecream(m2);
    massiv[2] = icecream(m3);
    massiv[0].Display();
    massiv[1].Display();
    massiv[2].Display();

    //демонстрация использования конструктора копирования
    cout<<"Demonstration of using the copy constructor"<<endl;
    icecream copy_icecream(ice1);
    copy_icecream.Display();

    //демонстрация опреатора присваивания
    cout<<"Demonstration of using an overloaded assignment operator"<<endl;
    ice1 = ice3;
    ice1.Display();

    icecream ice;
    cout<<ice.get_data()<<endl;
    {
        icecream ice_one = ice;
    }
    cout<<ice.get_data()<<endl;
}

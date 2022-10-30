#include "Item.h"

void operator >> (string cont, Item& h)

{
    int count = 1;
    string temp = "";
    for (int i = 0; i < cont.length(); i++)
    {
        if (cont[i] == '~')
        {
            switch (count)
            {
            case 1:
            {
                h._strCode = temp;
                break;
            }
            case 2:
            {
                h._strName = temp;
                break;
            }
            case 3:
            {
                h._strProductionPlace = temp;
                break;
            }
            case 4:
            {
                h._strColor = temp;
                break;
            }
            case 5:
            {
                h._iPrice = stoi(temp);
                break;
            }
            case 6:
            {
                h._strDayIn = temp;
                break;
            }
            
            default:
                break;
            }
            count++;
            temp = "";
            continue;
        }
        temp += cont[i];
    }
        h._iProducts = stoi(temp);
     
}
ofstream& operator << (ofstream& os,  Item& h)
{
    os  << h.getCode() << '~' << h.getName() << '~' << h.getProductionPlace() << '~' << h.getColor()
        << '~' << h.getPrice() << '~' << h.getDay() << '~' << h.getProduct() ;
    return os;
}

ostream& operator << (ostream& os, const Item& h)
{
    SPACE(NUB - WIDTH); VER(WIDTH);
    os << setw(SP1) << h._strCode; VER(WIDTH);
    os<< setw(SP3) << h._strName; VER(WIDTH);
    os<< setw(SP2) << h._strProductionPlace; VER(WIDTH);
    os<<setw(SP1) << h._strColor; VER(WIDTH);
    os<< setw(SP1) << h._iPrice; VER(WIDTH);
    os<< setw(SP2) << h._strDayIn; VER(WIDTH);
    os << setw(SP1) << h._iProducts; VER(WIDTH);
   

    NEWLINE(1);
    SPACE(NUB - WIDTH);
    VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP3); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP1); VER(WIDTH); HOR(SP2); VER(WIDTH); HOR(SP1); VER(WIDTH);
    NEWLINE(1);
    return os;
}
istream& operator >> (istream& is, Item& i)
{
    SPACE(NUB2); cout << "Ten mat hang: ";
    getline(is, i._strName);
    SPACE(NUB2); cout << "Noi san xuat: ";
    getline(is , i._strProductionPlace);
    SPACE(NUB2); cout << "Mau sac: ";
    getline(is , i._strColor);
    SPACE(NUB2); cout << "Gia ca: ";
    is >> i._iPrice;
    SPACE(NUB2); cout << "Ngay nhap hang: ";
    is >> i._strDayIn;
    SPACE(NUB2); cout << "So luong: ";
    is >> i._iProducts;
    return is;
}


string Item::getCode()
{
    return _strCode;
}
int Item::getNumber()
{
    return _iProducts;
}
string Item::getName()
{
    return _strName;
}
void Item::update(int products)
{
    _iProducts += products;
}
void Item::setCode(const string& code)
{
    _strCode = code;
}
string Item::getProductionPlace()
{
    return _strProductionPlace;
}
string Item::getColor()
{
    return _strColor;
}
string Item::getDay()
{
    return _strDayIn;
}
int Item::getPrice()
{
    return _iPrice;
}
int Item::getProduct()
{
    return _iProducts;
}


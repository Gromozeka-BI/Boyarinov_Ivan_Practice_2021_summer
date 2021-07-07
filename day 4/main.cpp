#include <iostream>
#include <fstream> 
#include <Windows.h> 
#include <limits>

using namespace std;
const double g = 10;

struct flight
{
    int mh = 120;
    int mt = 57;
    int* points;
    double v=0;
    double a=0;
    double h=0;
    double t=0;
    double InputFlight(flight n_flight, double v0, double h0, double t0);
    void createImage(int t, int h);
    void initImage();
    void saveToPnmFile(string fileName);
    flight* next;
};

class List
{
    flight* head;
public:
    List() :head(NULL) {}; 
    ~List();   
    void AddFlight(flight n_flight);
    void ShowFlight(double t0, double t1);
};


List::~List()
{
    while (head != NULL)            
    {
        flight* temp;
        temp = head->next; 
        delete head;                   
        head = temp;                    
    }

}


double flight::InputFlight(flight n_flight, double v0, double h0, double t0)
{
    t = t0;
    h = h0 + v0 * t0 - g * t0 * t0 / 2;
    v = v0 - g * t0;
    a = -g;
    return h;
}


void List::AddFlight(flight n_flight)
{
    flight* temp;
    temp = new flight; 
    temp->next = head;
    temp->t = n_flight.t;
    temp->h = n_flight.h;
    temp->v = n_flight.v;
    temp->a = n_flight.a;
    head = temp;
}

int TestTime(double t1, double t2)
{
    if ((t1 > t2)||(t1<0)||(t2<0))
    {
        cout << "Ошибка в задании диапазона времени" << endl;
        return -1;
    }
    return 0;
}

int TestHight(double h0)
{
    double hMax = 20000;
    if ((h0 < 0) || (h0 > hMax))
    {
        cout << "Ошибка в задании начальной высоты" << endl;
        return -1;
    }
    return 0;
}

void List::ShowFlight(double t1,double t2)
{
    flight* temp;
    temp = head;
    while (temp != NULL)
    {
        if ((temp->t >= t1) && (temp->t <= t2))
        {
            cout << "t= " << temp->t << "\t\t";
            cout << "h= " << temp->h << "\t\t";
            cout << "v= " << temp->v << "\t\t";
            cout << "a= " << temp->a << endl;
            
        }
        temp = temp->next;
    }
    cout << endl;
}

void flight::initImage()
{
    int n = mt * mh;
    points = new int[n];
    for (int i = 0; i < n; i++)
        points[i] = 0;
}

void flight::createImage(int t, int h)
{
    int n;
    n = h * mt + t;
    points[n] = 1;

}

void flight::saveToPnmFile( string fileName)
{
    fstream fout(fileName, ios::out);
    int n;
    fout << "P1" << endl;
    fout << mt << " " << mh << endl;
    for (int i = mh-1; i >=0; i--)
    {
        for (int j = 0; j < mt; j++)
        {
            n = (i * mt + j);
            fout << points[n] << " ";
        }
        fout << endl;
    }
    fout << endl;
    fout.close();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    flight n_flight;
    List lst;
    double v0 = 10;
    double g = 10;
    double m = 1;
    double h0 = 100;
    double t0;
    double h1=100;
    double t1 = 0;
    double t2 = 3;
    double dt = 0.1;
    t0 = t1;
    if ((TestTime(t1, t2) == -1)||(TestHight(h0)==-1))
    {
        return -1;
    }
    n_flight.initImage();
    while (h1 >=0)
    {
        h1 = n_flight.InputFlight(n_flight, v0, h0, t0);
        n_flight.createImage(t0*10, h1);
        lst.AddFlight(n_flight);
        t0 = t0 + dt;
    }
    lst.ShowFlight(t1,t2);
    n_flight.saveToPnmFile("image.pnm");
}

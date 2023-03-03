#include <iostream>
#include <fstream>
using namespace std;
ifstream f("Pointeri_introducere_in.txt");
ofstream g("Pointeri_introducere_out.txt");
void afis_v(int *v, int n)
{
    for(int i = 0;i < n;i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n\n";
}
int main()
{
    int x = 17;
    int *p = &x;
    cout << &x << endl << p << "\n\n"; // pointrul p indica adresa variabilei x in memorie(&x = p);
    cout << x << endl << p << "\n\n"; // adresa pointerului p;
    cout << x << endl << *p << "\n\n"; // valoarea din adresa pe care o indica pointerul p;

    int *v, n;
    f >> n;
    v = new int[n];
    for(int i = 0;i < n;i++)
    {
        f >> v[i];
    }

    //
    for(int i = 0;i < n;i++)
    {
        g << v[i] << "\n";
    }
    //

    afis_v(v, n);

    cout << *v << endl; // v[0];
    cout << *v + 1 << endl; // v[0] + 1;
    cout << *(v + 1) << endl; // v[1];
    cout << *(v + 3) << endl; // v[3]; 
    cout << *(v + 4) + 100 << endl; // v[4] + 100;

    cout << v << endl; // adresa de inceput a vectorului v;
    cout << v + 1 << endl; // adresa in memorie a celui de-al doilea element din vectorul v;
    cout << v + 2 << endl; // adresa in memorie a celui de-al treilea element din vectorul v;
    cout << v + 4 << endl; // adresa in memorie a celui de-al cincilea element din vectorul v;
    // !! Elementele din vector sunt pozitionate din 4 in 4 in adrese in hexa(ca in assembly);

    afis_v(v, n);
    int *pt;
    pt = v; // pt indica adresa vectorului v;
    *pt = 20; // *pt = v[0] = 20;
    afis_v(v, n);
    pt++; // pt = pt + 1 = v[1];
    *pt = -1; // *pt = v[1] = -1;
    afis_v(v, n);
    *(pt + 2) = -11; // *(pt + 2) = v[1 + 2] = -11;
    afis_v(v, n);
    pt++; // *pt = v[2];
    *(pt + 2) = -200; // *(pt + 2) = v[2 + 2] = -200;
    afis_v(v, n);

    pt = &v[3]; // pt indica adresa lui v + 3 = v[3];
    cout << *pt << endl; // afiseaza *pt = v[3];
    pt = v + 2;
    cout << *pt << endl; // afiseaza *pt = v[2];
    pt = v;
    *(pt + 4) = -1000; // *pt = v[0 + 4] = -1000;
    afis_v(v, n);
    cout << "\n\n";

    int v2[4] = {5, 2, 89, 1};
    afis_v(v2, 4);
    int *t = v2; // t indica adresa primului element din vectorul v2;
    t++; // t = t + 1 = &v[0 + 1];
    *(t + 1) = -*(t + 2); // *(t + 1) = t[1 + 1] = -t[1 + 2] = -*(t + 2);
    afis_v(v2, 4);
    t = &v2[0]; // t indica adresa lui v2[0];
    cout << *t << endl;
    t += 2; // t indica adresa lui v2[0 + 2];
    cout << *t << endl;
    t = v - 1; // !! t indica adresa primei casute la stanga lui &v2[0];
    cout << t << endl;
    *t = 12345; // !! adresa inaintea lui v[0] are valoarea 12345;
    cout << *t << endl;
    afis_v(v2, 4);
    cout << "\n\n";

    int a = 10, b = 13;
    int *p1, *p2;
    p1 = &a;
    p2 = &a;
    cout << p1 << " " << p2 << endl; // p1 = p2 = &a (adresa variabilei a);

    cout << a << " " << b << endl;

    *p1 = 4; // *p1 = *p2 = a = 4;
    cout << *p1 << " " << *p2 << " " << a << " " << b << endl;

    *p2 = 5; // *p2 = *p1 = a = 5;
    cout << *p1 << " " << *p2 << " " << a << " " << b << endl;

    p1 = &b; // *p1 = b = 13;
    cout << *p1 << " " << *p2 << " " << a << " " << b << endl;

    *p1 = 20; // *p1 = b = 20;
    cout << *p1 << " " << *p2 << " " << a << " " << b << endl;

    *p2 = 21; // *p2 = a = 21;
    cout << *p1 << " " << *p2 << " " << a << " " << b << endl;
    cout << "\n\n";

    int c = -10, d = 15;
    int *t1 = &c, *t2 = &d;
    cout << *t1 << " " << *t2 << " " << c << " " << d << endl;

    *t1 = *t2 + 10; // *t1 = c = *t2 + 10 = d + 10 = 15 + 10 = 25;
    cout << *t1 << " " << *t2 << " " << c << " " << d << endl;

    t1 = t2; // t1 = t2 = &d;
    cout << *t1 << " " << *t2 << " " << c << " " << d << endl;

    *t2 = *t1 + 1024; // *t2 = *t1 = d = *t1 + 1024 = *t2 + 1024 = d + 1024 = 15 + 1024 = 1039;
    cout << *t1 << " " << *t2 << " " << c << " " << d << endl;
    cout << "\n\n";


    delete[] v;
    f.close();
    g.close();
    return 0;
}
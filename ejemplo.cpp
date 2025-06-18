#include<iostream>
#include<string>
using namespace std;
struct EMP{
    int num;
    string nom;
    float ven[12], sal;
};

int main (){
    EMP EMPLEADOS[100];
    int n, sum, mayor, numEMP;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        for (int j=0; j<12;j++)
            cin>>EMPLEADOS[i].ven[j];
        cin>>EMPLEADOS[i].sal;
    }
    for (int i=0; i<n;i++){
        sum=0;
        mayor=0;
        numEMP=0;
        for (int j=0; i<12;j++)
            sum=sum+EMPLEADOS[i].ven[j];
        if (sum > mayor){
            numEMP=i;
        }
    }
    cout<<"La mayor venta fue del empleado:"<<endl;
    cout<<"Nro: "<<EMPLEADOS[numEMP].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[numEMP].nom<<endl;

    return 0;
}
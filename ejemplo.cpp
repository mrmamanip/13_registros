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
    int n, sum, mayor, numEMP, increm;
    cout<<"Inserte el numero de empleados: ";
    cin>>n;
    for(int i=0;i<n;i++){
    	cout<<"Inserte el numero de orden del empleado: ";
        cin>>EMPLEADOS[i].num;
        cin.ignore();
        cout<<"Inserte el nombre del empleado Nro "<<EMPLEADOS[i].num<<": ";
        getline(cin,EMPLEADOS[i].nom);
        cout<<"***Ventas del empleado '"<<EMPLEADOS[i].nom<<"'***"<<endl;
		for (int j=0; j<12;j++){
        	cout<<"Venta del mes ("<<j+1<<"): ";
            cin>>EMPLEADOS[i].ven[j];
            if (EMPLEADOS[i].ven[j] > 100){
            	increm=1;
			}
    	}
        cout<<"Inserte el salario base del empleado "<<EMPLEADOS[i].nom<<": ";
        cin>>EMPLEADOS[i].sal;
        EMPLEADOS[i].sal = EMPLEADOS[i].sal * 1.1; 
    }
	numEMP=0;
    for (int i=0; i<n;i++){
        sum=0;
        mayor=0;

        for (int j=0; j<12;j++)
            sum=sum+EMPLEADOS[i].ven[j];
        if (sum > mayor){
            numEMP=i;
        }
    }
    cout<<"La mayor venta fue del empleado:"<<endl;
    cout<<"Nro: "<<EMPLEADOS[numEMP].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[numEMP].nom<<endl;
    cout<<"Salario total del empleado "<<EMPLEADOS[numEMP].nom<<": "<<EMPLEADOS[numEMP].sal;
    

    return 0;
}

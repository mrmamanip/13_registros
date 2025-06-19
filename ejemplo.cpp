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
    int n, sum, mayor, numEMP, empBajos;
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
    	}
        cout<<"Inserte el salario base del empleado "<<EMPLEADOS[i].nom<<": ";
        cin>>EMPLEADOS[i].sal;

    }
	numEMP=0;
    mayor=0;
    for (int i=0; i<n;i++){
        sum=0;
        for (int j=0; j<12;j++){
            sum=sum+EMPLEADOS[i].ven[j];
		}
		if (sum > 100){
        	EMPLEADOS[i].sal = EMPLEADOS[i].sal * 1.1; 
		}
        if (sum > mayor){
        	mayor=sum;
            numEMP=i;
        }
    }
    cout<<"***EMPLEADO CON MAYOR VENTA***"<<endl;
    cout<<"Nro: "<<EMPLEADOS[numEMP].num<<endl;
    cout<<"Nombre: "<<EMPLEADOS[numEMP].nom<<endl;
    cout<<"Salario total del empleado "<<EMPLEADOS[numEMP].nom<<": "<<EMPLEADOS[numEMP].sal<<endl<<endl;
    cout<<"**EMPLEADOS CON MENOS DE 30 VENTAS REALIZADAS**"<<endl;
    for (int i=0; i<n;i++){
        sum=0;

        for (int j=0; j<12;j++){
            sum=sum+EMPLEADOS[i].ven[j];
		}
        if (sum < 30){
        	empBajos = 1;
            cout<<"Nro "<<EMPLEADOS[i].num<<" : "<<EMPLEADOS[i].nom<<" - Ventas realizadas: "<<sum<<endl;
        }
        if ( i==(n-1) && empBajos == 0 ){
        	cout<<"No hay empleados con ventas menores a 30.";
		}
    }
    return 0;
}

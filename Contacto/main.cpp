#include<iostream>
#include"contacto.h"
using namespace std;

int main(){
    int n, op, modifi, mod, modcorreo, opt, elim, numelim;
    string nom, user, domain;
    char sex, option;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    opt = 0;
    do{
        system("cls");
        cout<<"Menu de opciones :::::::::::::::::::::::::::::::::"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contactos"<<endl;
        cout<<"4. Eliminar contactos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"\nElige una opcion: "; cin>>op;
        switch(op){
            case 1:
            	system("cls");
            	cout<<
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                //imprimeContacto(cont);

                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<(i+1)<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system("pause");
                break;
            case 3:
            	system("cls");
            	cout<<"Menu de modificaciones en el contacto: --------"<<endl<<endl;
            	cout<<"Lista de contactos:"<<endl;
            	for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<(i+1)<<": "<<lista[i].nom<<"."<<endl;
                }
            	cout<<"\nInserte el numero de orden del contacto: ";cin>>mod;
            	system("pause");
                do{
                	system("cls");
                	cout<<"Menu de modificaciones en el contacto #"<<mod<<": ---"<<endl<<endl;
                	cout<<"Datos del contacto:"<<endl;
                	imprimeContacto(lista[mod-1]);
                	cout<<endl<<endl;
					cout<<"1. Modificar nombre"<<endl;
                	cout<<"2. Modificar sexo"<<endl;
                	cout<<"3. Modificar edad"<<endl;
                	cout<<"4. Modificar correo electronico"<<endl;
                	cout<<"0. Volver"<<endl;
                	cout<<"\nElige una opcion: ";cin>>modifi;
                	switch(modifi){
                		case 1:
                			cin.ignore();
                			cout<<"Inserte nuevo nombre: "; cin>>lista[mod-1].nom;
                			system("pause");
                			break;
                		case 2:
                			cout<<"Inserte nuevo sexo: "; cin>>lista[mod-1].sex;
                			system("pause");
                			break;
                		case 3:
                			cout<<"Inserte nueva edad: "; cin>>lista[mod-1].edad;
                			system("pause");
                			break;
                		case 4:
                			do{
								system("cls");
                				cout<<"Menu de cambios en correo electronico: -----"<<endl<<endl;
                				cout<<"1. Cambiar usuario"<<endl;
                				cout<<"2. Cambiar dominio"<<endl;
                				cout<<"0. Volver"<<endl;
                				cout<<"\nElige una opcion: ";cin>>modcorreo;
                				switch(modcorreo){
                					case 1:
                						cout<<"Inserte nuevo usuario: ";cin>>lista[mod-1].email.user;
                						system("pause");
                						break;
                					case 2:
                						cout<<"Inserte nuevo dominio: "; cin>>lista[mod-1].email.domain;
                						system("pause");
                					case 0:
                						break;
                					default:
                						cout<<"Opcion no valida!"<<endl;
                						system("pause");
                						break;
                					}
							} while(modcorreo != 0);
						case 0:
							break;
						default:
							cout<<"Opcion no valida!"<<endl;
							break;
                	}
                } while(modifi != 0);
                break;
            case 4:
            	do{
            		system("cls");
					cout<<"Menu de eliminacion de contactos: -------------"<<endl<<endl;
            		cout<<"Lista de contactos:"<<endl;
            		for(int i = 0; i < n; i++){
                	    cout<<"Contacto #"<<(i+1)<<": "<<lista[i].nom<<"."<<endl;
                	}
                	cout<<"\n1. Eliminar contacto"<<endl;
                	cout<<"0. Volver"<<endl;
                	cout<<"\nElige una opcion: ";cin>>elim;
                	switch(elim){
                		case 1:
                			cout<<"\nElige el numero de lista del contacto a eliminar:";cin>>numelim;
                			for(int j = (numelim-1); j<n;j++){
                			lista[j]=lista[j+1];
							}
							n--;
							system("pause");
							break;
						case 0:
							break;
						default:
							cout<<"Opcion no valida!"<<endl;
                			system("pause");
                			break;
					}
				}while(elim != 0);
            	break;
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";cin>>option;
                if (option == 's' || option == 'S'){
                	opt=1;
				}
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(opt != 1);
    return 0;
}
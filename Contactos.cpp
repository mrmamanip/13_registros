#include<iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
    int n, op, modifi, mod, modcorreo, opt;
    string nom, user, domain;
    char sex, option;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    opt = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Mostrar contactos"<<endl;
        cout<<"3. Modificar contactos"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 1:
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
            	cout<<"Inserte el numero de orden del contacto: ";cin>>mod;
                do{
                	system("cls");
                	cout<<"Menu de cambios en el contacto #"<<mod<<": ---"<<endl<<endl;
                	cout<<"Datos del contacto:"<<endl;
                	imprimeContacto(lista[mod-1]);
                	cout<<endl<<endl;
					cout<<"1. Modificar nombre"<<endl;
                	cout<<"2. Modificar sexo"<<endl;
                	cout<<"3. Modificar edad"<<endl;
                	cout<<"4. Modificar correo electronico"<<endl;
                	cout<<"0. Volver"<<endl;
                	cout<<"Elige una opcion: ";cin>>modifi;
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
                				cout<<"Menu de cambios en correo electronico: -----"<<endl;
                				cout<<"1. Cambiar usuario"<<endl;
                				cout<<"2. Cambiar dominio"<<endl;
                				cout<<"0. Volver"<<endl;
                				cout<<"Elige una opcion: ";cin>>modcorreo;
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

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}

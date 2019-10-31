#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario
{
    private:

        char nombre[30];
        char apellido[30];
        ///int edad;
        int cuit;
        int Cod_Postal;
        char Ciudad[30];
        char domicilio[30];
        int Cod_Consumidor;
        bool MesesAdeudados[12];
        bool Estado;

    public:

        void setNombre(char aux[30]){strcpy(nombre,aux);}
        char *getNombre(){return nombre;}

        void setApellido(char aux[30]){strcpy(apellido,aux);}
        char *getApellido(){return apellido;}

       /* void setEdad(int aux){edad = aux;}
        int getEdad(){return edad;}*/

        void setCuit(int aux){cuit = aux;}
        int getCuit(){return cuit;}

        void setCod_Postal(int aux){Cod_Postal = aux;}
        int getCod_Postal(){return Cod_Postal;}

        void setCiudad(char aux[30]){strcpy(Ciudad,aux);}
        char *getCiudad(){return Ciudad;}

        void setDomicilio(char aux[30]){strcpy(domicilio,aux);}
        char *getDomicilio(){return domicilio;}

        void setCod_Consumidor(char aux){Cod_Consumidor = aux;}
        int getCod_Consumidor(){return Cod_Consumidor;}

        void setEstado(bool aux){Estado = aux;}
        bool getEstado(){return Estado;}

        int grabarenDisco();

        void Cargar();

        int listarTodos();

        int listarXCodigo();

       // int  modificar();
};

void holaMUNDO(){
  cout << "hola mundo";
}



int AutonumericoUsuario(){
    Usuario obj;
    FILE *p;
    p=fopen("Usuarios.dat","rb");
    if(p==NULL){
        return 0;
    }
    fseek(p, 0, SEEK_END);
    return ftell(p)/sizeof obj;
}

int Usuario::grabarenDisco(){

        FILE *p;
        p = fopen("Usuarios.dat","ab");
        if(p == NULL){
            cout << "ERROR DE ARCHIVO EN LA FUNCION 'grabarenDisco()'";
            fclose(p);
            return 0;
        }
        fwrite(this,sizeof(Usuario),1,p);
        fclose(p);
        cout << "USUARIO GUARDADO..."<<endl;
        system("pause");
        return 1;

}

void Usuario::Cargar(){

        int autonum;

        autonum=AutonumericoUsuario();

        setCod_Consumidor(autonum+1);

        cout<< "NOMBRE: ";
        cin >> nombre;

        cout << "APELLIDO: ";
        cin >> apellido;

        /*cout << "EDAD: ";
        cin >> edad;*/

        cout << "CUIT: ";
        cin >> cuit;

       /* cout << "CODIGO DE CONSUMIDOR: ";
        cin >> Cod_Consumidor;*/

        cout << "CODIGO POSTAL: ";
        cin >> Cod_Postal;

        cout << "CIUDAD: ";
        cin >> Ciudad;

        cout << "DOMICILIO: ";
        cin >> domicilio;

        }

int listarTodos(){

    Usuario obj;

    FILE *p;

    p = fopen("Usuarios.dat","rb");
    if(p == NULL){
        cout << "ERROR AL ABRIR EL ARCHIVO" << endl;
        return 1;
    }

    while(fread(&obj,sizeof(Usuario),1,p)){
         cout<< "NOMBRE: ";
        cout << obj.getNombre();

        cout << "APELLIDO: ";
        cout << obj.getApellido();

        /*cout << "EDAD: ";
        cout << obj.getEdad();*/

        cout << "CUIT: ";
        cout << obj.getCuit();

        cout << "CODIGO DE CONSUMIDOR: ";
        cout << obj.getCod_Consumidor();

        cout << "CODIGO POSTAL: ";
        cout << obj.getCod_Postal();

        cout << "CIUDAD: ";
        cout << obj.getCiudad();

        cout << "DOMICILIO: ";
        cout << obj.getDomicilio();
        cout << "========================================" << endl;
    }
    fclose(p);
    system("pause");
    return 0;
}

void nuevoUsuario(){

    Usuario obj;
    obj.Cargar();
    obj.grabarenDisco();

}

int listarXCodigo(){

Usuario obj;
char CodConsumidor;
bool bandera=true;

cout << "INGRESE CODIGO DE CONSUMIDOR" << endl;
cin >> CodConsumidor;

FILE *p;

p = fopen("Usuarios.dat","rb");
if(p == NULL){
    cout << "ERROR EN ABRIR EL ARCHIVO..." << endl;
    system("pause");
    fclose(p);
    return 1;
}

while(fread(&obj,sizeof(obj),1,p)){
    if(CodConsumidor == obj.getCod_Consumidor()){
        cout << "===============================================" << endl;
        cout << "CODIGO DE CONSUMIDOR: " << obj.getCod_Consumidor() << endl;
        cout << "NOMBRE: " << obj.getNombre() << endl;
        cout << "APELLIDO: " << obj.getApellido() << endl;
        ///cout << "EDAD: " << obj.getEdad() << endl;
        cout << "DOMICILIO: " << obj.getDomicilio() << endl;
        cout << "CUIT: " << obj.getCuit() << endl;
        cout << "CODIGO POSTAL: " << obj.getCod_Postal() << endl;
        cout << "CIUDAD: " << obj.getCiudad() << endl;
        cout << "===============================================" << endl;

        system("pause");
        fclose(p);
        return 1;

    }
    else{
        bandera =false;
    }
}

if(bandera==1){
        system("cls");
        cout<<"No hay USUARIOS activos actualmente con ese CODIGO." << endl << endl;
        system("pause");
        system("cls");
        fclose(p);
        return 0;
    }
    fclose(p);
    system("cls");
    return 1;

}

int eliminarUsuario(){
    Usuario obj;
    int Codigo;

    cout << "INGRESE EL CODIGO DE USUARIO QUE DESEA ELIMINAR: ";
    cin >> Codigo;

    FILE *p;

    p = fopen("Usuarios.dat","rb+");
    if(p == NULL){
        cout << "ERROR DE ARCHIVO" << endl;
        system("pause");
        fclose(p);
        return 0;
    }

    while(fread(&obj,sizeof obj,1,p)){

        if(Codigo == obj.getCod_Consumidor()){
            system("cls");
            cout << "DESEA DAR DE BAJA AL USUARIO " << obj.getApellido() << " " << obj.getNombre() << "?" << endl;
            cout << "1- SI / 2 - NO" << endl;
            int  opc;
            cin >> opc;

            if(opc == 1){
                bool aux = false;
                obj.setEstado(aux);
                fseek(p, ftell(p)-sizeof obj, 0);
                fwrite(&obj, sizeof obj, 1, p);
                cout << "USUARIO ELIMINADO..." << endl;
                system("pause");
                fclose(p);
                return 1;
            }
            else{
                cout << "BAJA CANCELADA..." << endl;
                system("pause");
                fclose(p);
                return 0;
                }
            }
        }
        cout << "USUARIO NO ENCONTRADO..." << endl;
        system("pause");
        fclose(p);
        return 0;
}

int modificarUsuario(){

    Usuario obj;
    int CUIT;
    int bandera=0;
    cout << "INGRESE EL CUIT DEL PACIENTE A MODIFICAR:";
    cin >> CUIT;

    FILE *p;

    p = fopen("Usuarios.dat","rb+");
    if(p == NULL){
            cout << "ERROR DE ARCHIVO";
            fclose(p);
            return 0;}

    while(fread(&obj,sizeof(obj),1,p)){///le paso la direccion del objistro, el tama�o y cuanto me quiero desplazar
    if(obj.getCuit() == CUIT){
       if(obj.getEstado() == true){
          cout << "INGRESE EL NUEVO DOMICILIO: ";
          char aux[30];
          cin >> aux;
          obj.setDomicilio(aux);
          fseek(p, ftell(p)-sizeof obj, 0);///puntero, cantidad de bites a desplazar, desde donde
          fwrite(&obj, sizeof obj, 1, p);
          fclose(p);
          return 0;
                }
        else{
            bandera = 1;
                }
            }

       }
}

void gestionUsuarios()
{
    int opcion;
    bool bandera;

    while(bandera!=false){

        menuUsuarios();
        cin>>opcion;
        system("cls");

        ///ingresa un codigo de cliente y anula el envio de energia
        switch(opcion)
            {
            case 1:
                nuevoUsuario();
                break;
            case 2:
                listarTodos();
                break;
            case 3:
                listarXCodigo();
                system("cls");
                break;
            case 4:
                eliminarUsuario();
                break;
            case 5:
                modificarUsuario();
                break;
            case 0:
                cout<<"SALIR Y GUARDAR"<<endl;
                bandera=false;
                break;
            default:
                break;
            }
        }
}
#endif // USUARIO_H_INCLUDED

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

struct Fecha{

    int dia, mes, anio;
};

int biciesto(int anio){                                                                                                                                 //

    if(anio % 4 == 0){
        if(anio % 100 == 0){
            if(anio % 400 == 0){
                return 29;
            }
            else {
                return 28;
            }
        }
        else{
           return 29;
        }
    }
    else{
        return 28;
    }
}

//------------Ve cuantos dias tiene el mes------------
int validar_dia (int mes,int dia,int anio){

    int vMeses[12];
    vMeses[0] = 31;
    vMeses[1] = biciesto(anio);
    vMeses[2] = 31;
    vMeses[3] = 30;
    vMeses[4] = 31;
    vMeses[5] = 30;
    vMeses[6] = 31;
    vMeses[7] = 31;
    vMeses[8] = 30;
    vMeses[9] = 31;
    vMeses[10] = 30;
    vMeses[11] = 31;
    if(dia > 0 && dia <= vMeses[mes-1]){
        return 1;
    }
    else{
        return 0;
    }
}

//-------------------------------------------------------
void cargar_fecha (struct Fecha *fecha){
    int bandera = 0, condicion1, condicion2, condicion3;
    cout<< "Ingrese el dia: ";
    cin>>fecha->dia;
    cout<<"Ingrese el mes: ";
    cin>>fecha->mes;
    cout<<"Ingrese el año: ";
    cin>>fecha->anio;
//------------Validar Fecha------------
    while(bandera == 0){
        condicion1=condicion2=condicion3= 0;
        if(fecha->anio < 2500 && fecha->anio > 1900){
            condicion1 = 1;
        }
        if(fecha->mes > 0 && fecha->mes < 13){
            condicion2 = 1;
        }
        if(condicion2 == 1){
            condicion3 = validar_dia(fecha->mes, fecha->dia, fecha->anio);
        }
        if(condicion1 == 1 && condicion2 == 1 && condicion3 == 1){
            bandera = 1;
        }
            else{
                cout << "\nLA FECHA ES INVALIDA, ingresar nuevamente.";
                cout << "Ingresar el dia: ";
                cin >> fecha->dia;
                cout << "Ingresar el mes: ";
                cin >> fecha->mes;
                cout << "Ingresar el año: ";
                cin >> fecha->anio;
            }
    }
}


void mostrar_fecha (struct Fecha *fecha){
    cout << fecha->dia << "/" << fecha->mes << "/" << fecha->anio;
}

#endif // FECHA_H_INCLUDED

///Comenzar con Facturas.h
///falta modificar() de Usuario.h
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#include "Menus.h"
#include "Usuario.h"
#include "Consumo.h"
#include "Facturas.h"
#include "fecha.h"

///---------------------------------------------------------------------------------


///---------------------------------------------------------------------------------
void despacho()
{
    int mes;
    int a=0,b=0,c=0;
char mat[12][25];
cout<<"-----------------------------"<<endl;
cout<<"|         DESPACHO          |"<<endl;
cout<<"-----------------------------"<<endl;
cout<<"INGRESAR EL MES DE FACTURACION A DESPACHAR"<<endl;
cin>>mes;
strcpy(mat[0],"enero");
strcpy(mat[1],"febrero");
strcpy(mat[2],"marzo");
strcpy(mat[3],"abril");
strcpy(mat[4],"mayo");///hacer funcion
strcpy(mat[5],"junio");
strcpy(mat[6],"julio");
strcpy(mat[7],"agosto");
strcpy(mat[8],"septiembre");
strcpy(mat[9],"octubre");
strcpy(mat[10],"noviembre");
strcpy(mat[11],"diciembre");
cout<<mat[mes-1]<<endl;
cout<<endl;
cout<<endl;
///if(mes==getmes()){
   srand(getpid());
   a=rand()%2;
   b=rand()%2;
   c=rand()%2;
   ///guardar en el vector de bool azar
  /// }
cout<<a<<endl; ///en verificar
cout<<b<<endl;
cout<<c<<endl;
///%2 (entre 1=true y 0=false)
system("pause");
system("cls");
system("pause");
system("cls");
///luego una bandera(pagos) al azar seria manipulada (poniendola en true o false)
}

///---------------------------------------------------------------------------------
///---------------------------------------------------------------------------------


void verificar()
{
cout<<"-----------------------------"<<endl;
cout<<"|        VERIFICAR          |"<<endl;
cout<<"-----------------------------"<<endl;
cout<<endl;
cout<<endl;
cout<<endl;
///ingresar usuario para verificar los meses pagados
///verificara las facturas( la bandera(azar)) y dependiendo si este en true o false le cobra un recargo
///por no pagar a tiemp�
///si no paga por 6 meses seguidos se le cortara el suministro de energia=eliminar usuario
}


///---------------------------------------------------------------------------------


int main ()
{
bool n=false;
int opcion;
while(n==false){

    menuPrincipal();
    cin>>opcion;
    system("cls");
    switch(opcion)
    {
        case 1:
            gestionUsuarios();
            break;
        case 2:
            factura();///2-baja,modificar y listar
            break;
        case 3:
            despacho();///3-azar
            break;
        case 4:
            verificar();///4-baja y modificar
            break;
        case 0:
            n=true;
            break;
        default :
            break;
        }
    }
return 0;
}

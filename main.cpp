#include <iostream>
#include <cstdlib>
#include <string>
#include "VGeneral.h"
#include "Lista.h"

using namespace std;

int main ()
{
	int valor, valor2, respuesta,lim,lim2;
	Lista<int> Lista10Num;
	Lista<int> ListaAux;
	VGeneral vg;
	do
	{
		lim=Lista10Num.Contar();
		lim2=ListaAux.Contar();
		vg.Limpiar();
		cout<<"=============================================================================="<<endl;
		cout<<"-----------------------------  MENU DE OPCIONES  -----------------------------"<<endl;
		cout<<"=============================================================================="<<endl;
		cout<<"\n1-) INSERTAR n NUMEROS ENTEROS"<<endl;
		cout<<"2-) IMPRIMIR NUMEROS ENTEROS"<<endl;
		cout<<"3-) ELIMINAR ELEMENTOS DE LA LISTA"<<endl;
		cout<<"4-) ELEMENTOS ACTUALES EN LA LISTA"<<endl;
		cout<<"5-) SALIR\n"<<endl;
		cout<<"=============================================================================="<<endl;
		respuesta= vg.LeerValidarNro("\n Opcion seleccionada : ",1,5);
		switch (respuesta)
		{
			case 1:
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				cout<<"\n1-) INDIQUE EL NUMERO DE ELEMENTOS A INSERTAR"<<endl;
				cout<<"=============================================================================="<<endl;
				valor2= vg.LeerValidarNroValorInicial("\n Numero de elementos : ",0);
				vg.Limpiar();
				cout<<"=============================================================================="<<endl;
				cout<<"------------------------------  LLENAR LA LISTA  -----------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				for(int i=1;i<valor2+1;i++)
				{
					valor=vg.LeerNro("\n Numero de elementos : ");
					if(!Lista10Num.InsComienzo(valor))
					{
						cout<<"\n\n\tNO SE PUDO INSERTAR EL NUMERO"<<endl;
						system("pause");
						break;
					}
				}
				cout<<"=============================================================================="<<endl;
				cout<<"---------------------  ELEMENTOS INSERTADOS CON EXITO   ----------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				vg.Pausa();
				break;
			case 2:
				vg.Limpiar();   	
				cout<<"=============================================================================="<<endl;   	
				cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				cout<<"1-) Imprimir y vaciar"<<endl;
				cout<<"2-) Imprimir"<<endl;
				cout<<"3-) Atras\n"<<endl;
				valor2 = vg.LeerValidarNro(" Opcion seleccionada : ",1,3);
				if (!Lista10Num.Vacia())
				{
					if(valor2==1)
					{	
						for(int i=0;i<lim;i++)
						{
							if(Lista10Num.EliComienzo(valor))
							{
								cout<<"\t -) "<<valor<<"\n";
							}	
						}
						vg.Pausa();
					}
					else if(valor2==2)
					{
						for(int i=0;i<lim;i++)
						{
								if(Lista10Num.EliComienzo(valor))
								{
									cout<<"\t -) "<<valor<<"\n";
									ListaAux.InsComienzo(valor);
								}	
						}
						lim2=ListaAux.Contar();
						for(int i=0;i<lim2;i++)
						{
							if(ListaAux.EliComienzo(valor))
							{
								Lista10Num.InsComienzo(valor);
							}	
						}
						vg.Pausa();
					}
				}
				else
				{
					cout<<"=============================================================================="<<endl;
					cout<<"-----------------------------  LISTA VACIA -----------------------------------"<<endl;
					cout<<"==============================================================================\n"<<endl;
					system("pause");
					break;
				}
				break;
			case 3:
				vg.Limpiar();   	
				cout<<"=============================================================================="<<endl;   	
				cout<<"---------------------------  SUB-MENU DE OPCIONES  ---------------------------"<<endl;
				cout<<"=============================================================================="<<endl;
				cout<<"1-) Vaciar Lista"<<endl;
				cout<<"2-) Eliminar ultimo elemento"<<endl;
				cout<<"3-) Atras\n"<<endl;
				valor2 = vg.LeerValidarNro(" Opcion seleccionada : ",1,3);
				if (!Lista10Num.Vacia())
				{
					if (valor2==1)
					{
						vg.Limpiar(); 
						Lista10Num.~Lista();
						cout<<"=============================================================================="<<endl;
						cout<<"------------------------------  LISTA VACIADA  -------------------------------"<<endl;
						cout<<"=============================================================================="<<endl;
						vg.Pausa();
					}
					else if (valor2==2)
					{
						if(!Lista10Num.Vacia())
						{
							if (!Lista10Num.Vacia())
							{
								if(Lista10Num.EliComienzo(valor))
								{
								cout<<"\n\tElmento eliminado:  "<<valor<<"\n";
								vg.Pausa();
								}	
							}
						}
					}
				}
				else
				{
					cout<<"\n=============================================================================="<<endl;
					cout<<"-----------------------------  LISTA VACIA -----------------------------------"<<endl;
					cout<<"==============================================================================\n"<<endl;
					system("pause");
				}
				break;
			case 4:
				vg.Limpiar();
				cout<<"\n TOTAL DE NUMEROS EN LA LISTA : "<<Lista10Num.Contar()<<"\n "<<endl;
				vg.Pausa();
				break;
			default:
				break;
			}
   	}while(respuesta!=5);   
	return 0;
}

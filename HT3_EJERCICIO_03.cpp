

#include<iostream> 
#include<fstream>  
#include<string>   
#include<cstdlib>
using namespace std;
void ingreso();
void reporte();
int main(){
	ingreso();
	reporte();
}
void ingreso(){
	int edad;
	char modelo;
	char color;
	float precio=0;
	int n,i;
	cout<<"Cu�ntos datos ingresar�? "<<endl;
	cin>>n;
	for(i=0;i<n;i++){
		cout<<"Ingrese datos para el c�lculo de p�liza"<<endl;
		cout<<"Ingrese modelo (A o B) "<<endl;
		cin>>modelo;
		cout<<"Ingrese color: (B)lanco / (M)etalizado / (O)tros "<<endl;
		cin>>color;
		cout<<"Ingrese edad del conductor: "<<endl;
		cin>>edad;
		modelo=toupper(modelo);
		modelo=toupper(color);
		if (modelo=='A'){
			if (color=='B'){
				precio = 240.50;
			}
				else if (color=='M'){
				precio = 330.00;
			}
			else if (color=='O'){
				precio = 270.50;
			}
		}
		else if(modelo =='B'){
			if (color=='B'){
				precio = 300.00;
			}
			else if (color=='M'){
				precio = 360.50;
			}
			else if (color=='O'){
				precio = 330.00;
			}
		}	
	}
	
	if (edad >= 16 && edad<31){
		precio = precio + (precio*0.25);
	}
	else if (edad > 61 && edad <80){
		precio = precio + (precio*0.30);
	}
	cout<<"Datos ingresados: \n "<<endl;
	cout<<"Modelo: \t"<<modelo<<endl;
	cout<<"Color: \t"<<color<<endl;
	cout<<"Edad: \t"<<edad<<endl;
	cout<<"Precio de p�liza: \t"<<precio<<endl;
	ofstream archivo;
	
	
	try{
		archivo.open("poliza.txt",ios::app);
		archivo<<modelo<<"\t"<<color<<"\t"<<precio<<endl;
		archivo.close();
	}
	catch(exception X){
		cout<<"Error al abrir el archivo"<<endl;
	}
	
}
void reporte(){
	int edad;
	char modelo;
	char color;
	float precio;
	ifstream reporte;
	int lineas;
	int i;
	string s;
	reporte.open("poliza.txt",ios::in);
	while(getline(reporte,s)){
		lineas++;
	}
	cout<<"Reporte de p�lizas: "<<endl;
	cout<<"#"<<"\t"<<"Modelo"<<"\t"<<"Color"<<"\t"<<"Edad"<<endl;
	for (i=0;i<lineas;i++){
		reporte>>modelo>>"\t">>color>>"\t">>precio>>endl;
	}
	reporte.close();
}




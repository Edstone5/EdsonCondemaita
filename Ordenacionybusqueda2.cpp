#include <iostream>
using namespace std;
template <class T>
class Ordenador{
    public:
        virtual void Ordena(T *A, int n) = 0;
        void Intercambia(T *A, int ind1, int ind2);
};


template <class T>
void Ordenador<T> :: Intercambia(T *A, int ind1, int ind2){
    T aux;
    aux = A[ind1];
    A[ind1] = A[ind2];
    A[ind2] = aux;
}


template <class T>
class InterDirDer : public Ordenador <T>{
    public:
        void Ordena(T *A, int n);
};
template <class T>
void InterDirDer<T> :: Ordena(T *A, int n){
    for(int i = 1; i <= n-1; i++)
        for(int j = 1; j <= n-i; j++)
            if(A[j] > A[j+1])
                this->Intercambia(A,j,j+1);
}

class Alumno{
    private:
        int cod;
        char nombre[40];
    public:
        Alumno(){}
        bool operator>(Alumno);
        friend istream& operator>>(istream &, Alumno &);
        friend ostream& operator<<(ostream &, Alumno &);
};


bool Alumno::operator>(Alumno objA){
    if(cod > objA.cod)
        return true;
    else
        return false;
} 


istream& operator>>(istream &Lee, Alumno &objA){
    cout<<"Ingrese codigo: "; Lee>>objA.cod;
    cout<<"Ingrese nombre: "; Lee>>objA.nombre;
    return Lee;
}


ostream& operator<<(ostream &Escribe, Alumno &objA){
    Escribe<<"Codigo: "<<objA.cod<<endl;
    Escribe<<"Nombre: "<<objA.nombre<<endl;
    return Escribe;
}

int main(){
    Alumno A[10];
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>A[i];
        cout<<endl;       
    }
    
    InterDirDer<Alumno> objIDD;
    objIDD.Ordena(A,n);


    cout<<endl<<"Datos ordenados"<<endl;
    for(int i = 1; i <= n; i++){
        cout<<A[i]<<endl; 
    }
    return 0;
}

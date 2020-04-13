public class Nodo 
{
 
 //Declaración de atributos
 private int dato;
 private Nodo siguiente;
  
 //Constructor Nodo null
 public Nodo(int dato)
 {
  this.dato=dato;
  this.siguiente=null;
 }
 //Constructor Nodo con parametro
 public Nodo(int dato, Nodo siguiente)
 {
  this.dato=dato;
  this.siguiente=siguiente;
 }
 
 //Metodos getters and setters
 public int getDato() {
  return dato;
 }
 
 public void setDato(int dato) {
  this.dato = dato;
 }
 
 public Nodo getSiguiente() {
  return siguiente;
 }
 
 public void setSiguiente(Nodo siguiente) {
  this.siguiente = siguiente;
 }
  
}

public class Lista 
{
 
 private Nodo inicio;
 private Nodo fin;
  
 public Lista()
 {
  inicio=fin=null;
 }
  
 //Metodo para agregar inicio
 public void agregarInicio(int info)
 {
  Nodo nuevo=new Nodo(info, inicio);
  if(inicio==null)
  {
   inicio=fin=nuevo;
  }
  inicio=nuevo;
 }
  
 //Metodo para agregar fin
 public void agregarFin(int info)
 {
  Nodo nuevo=new Nodo(info, null);
  if(inicio==null)
  {
   inicio=fin=nuevo;
  }
  else
  {
   fin.setSiguiente(nuevo);
   fin=nuevo;
  }
 }
  
 //Metodo para imprimir
 public void imprimir()
 {
  Nodo aux=inicio;
  while(aux!=null)
  {
   System.out.println(aux.getDato());
   aux=aux.getSiguiente();
  }
 }
  
 //Metodo para eliminar el nodo
 public void eliminarNodo(int numero)
 {
  if(inicio!=null)
  {
   if((inicio==fin)&&(inicio.getDato()==numero))
   {
    inicio=fin=null;
   }
   else if(inicio.getDato()==numero)
   {
    inicio=inicio.getSiguiente();
   }
   else
   {
    Nodo anterior=inicio;
    Nodo siguiente=inicio.getSiguiente();
    while((siguiente!=null)&&(siguiente.getDato()!=numero))
    {
     anterior=siguiente;
     siguiente=siguiente.getSiguiente();
    }
    if(siguiente!=null)
    {
     anterior.setSiguiente(siguiente.getSiguiente());
     if(siguiente==fin)
     {
      fin=anterior;
     }
    }
   }
  }
 }
  
 //Metodo para agregar un nodo
 public void agregarNodo(int numero)
 {
  if(inicio!=null)
  {
   if(inicio==fin && inicio.getDato()==numero)
   {
    inicio=fin=null;
   }
   else if(inicio.getDato()==numero)
   {
    inicio = inicio.getSiguiente();
   }
   else
   {    
    Nodo anterior = inicio;
    Nodo siguiente = inicio.getSiguiente();   
    while(siguiente!=null && anterior.getDato()!=numero)
    {
    anterior = siguiente;
    siguiente = siguiente.getSiguiente();
    }
    if (siguiente!=null)
    {
     Nodo nuevo = new Nodo(calculo(anterior.getDato(),siguiente.getDato()),siguiente);     
     anterior.setSiguiente(nuevo);
     nuevo.setSiguiente(siguiente);
     if(siguiente == fin)
     {
      fin = anterior;
     }
    }
   }  
  }
 }
 
 //Metodo para calcular el valor absoluto entre dos numeros ubicados en los nodos
 public int calculo(int primer, int segundo)
 {
  int num = primer -segundo;   
  num =Math.abs(num);
  return num;  
 }
 
}


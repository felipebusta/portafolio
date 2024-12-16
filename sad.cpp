#include <stdio.h>
#include <iostream>
using namespace std;

void imprimir (int mat[5][5]){
for(int i=0; i < 5 ;i++){
for(int j=0; j < 5 ; j++){
printf("%5d ",mat[i][j]);
}
cout << endl;
}
}
int menor(int d[5],int visitados[5])
{
int m=0,c=1;

while ((c < 5) && (d[c] != -1) && (visitados[c] == 1))
c++;
m=c;
c++; 
while (c < 5)
{
if ((d[c] != -1)&& (visitados[c] == 0)&& (d[m] > d[c]))
m=c;
c++;
}
return m;
}

void caminoMin(int padre[5],int d[5],int mat[5][5],int v)
{
int vert=padre[v],ant;
ant=v;
cout << " V: " <<ant << " V: " <<vert << " Dist: " <<mat[ant][vert]<< endl;
while (vert != 0)
{ ant=vert;
vert=padre[vert];
cout << " V: " <<ant<< " V: " <<vert << " Dist: " <<mat[ant][vert]<< endl;
}
cout << " Distancia total: " <<d[v]<< endl;
}
int main()
{
cout << "Algoritmo de Dijkstra" << endl;
int mat[5][5]={0,40,0,100,0, 40,0,150,0,30, 0,150,0,0,200, 100,0,0,0,150, 0,30,200,150,0};
imprimir (mat);
int padre[5],d[5],visitados[5],v=1;
for(int i=0; i < 5 ;i++)
{padre[i]=-1;
d[i]=-1;
visitados[i]=0;
}

visitados[0]=1;

d[0]=0; 
d[1]=40;
d[3]=100; 
padre[1]=0;
padre[3]=0;

int a;
while (v < 5)
{
a=menor(d,visitados);

visitados[a]=1;
for(int i=1; i < 5 ;i++)
{
if ((mat[a][i] != 0)&& ((d[i]==-1) || (d[i] > (d[a]+ mat[a][i]))) )
{ 

d[i] = d[a]+ mat[a][i];
padre[i]=a;
}
}
v++;
}
cout << endl ;
cout << " Imprimo el arreglo de distancias" <<endl;
for(int j=0; j < 5 ; j++)
printf("%5d ",d[j]);
cout << endl ;
cout << " Imprimo el arreglo de padres" <<endl;
for(int j=0; j < 5 ; j++)
printf("%5d ",padre[j]);
cout << endl ;
cout << " Imprimo el camino minimo de (v0) A a (v5) E" <<endl;
caminoMin(padre,d,mat,4);
return 0;
}
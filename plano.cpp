#include <iostream>
#include <vector>

using namespace std;

class Plane{
private:
    int rows, columns;
    vector<vector<int>> plane;

public:
    Plane(int, int);
    void fill();
    void print();
    vector<vector<int>>& getPlane(); // Devuelve una referencia al vector plane
};

Plane::Plane(int _rows, int _columns){
    rows = _rows;
    columns = _columns;
    plane = vector<vector<int>>(rows + 1, vector<int>(columns + 1, 0)); // Inicializa toda la matriz con 0
}

void Plane::fill(){
    int count;
    for (int i = 0; i <= rows; i++){
        count = i;
        for(int j = 0; j <= columns; j++){
            if(i == 0){
                plane[i][j] = count - 1;
            }
            if (j == 0){
                plane[i][j] = count - 1;
            }
            if(j == 0 && i == 1){
                plane[i][j] = 0;
            }
            if(j == 1 && i == 0){
                plane[i][j] = 0;
            }
            if (j == 0 && i == 0){
                plane[i][j] = 0;
            }
            if (i == 1 || j == 1){
                plane[i][j] = 150;
            }
            count++;
        }
    }
}

void Plane::print(){
    for (int i = rows; i >= 0; i--){
        for(int j = 0; j <= columns; j++){
            if(plane[i][j] == 150){
                cout << "+ ";
            } else if(plane[i][j] == 200){
                cout << "/ ";
            } else if(plane[i][j] == 0){
                cout << "  ";
            }
            else {
                cout << plane[i][j] << " ";
            }
        }
        cout << endl;
    }
}

vector<vector<int>>& Plane::getPlane() {
    return plane;
}

class Lineal{
private:
    int a, b;

public:
    Lineal(int, int);
    void print(vector<vector<int>>& matriz);
};

Lineal::Lineal(int _a, int _b){
    a = _a;
    b = _b;
}

void Lineal::print(vector<vector<int>>& matriz){
    for(int i = 1; i < matriz.size(); i++){
        int x = i;
        int y = x * a + b;
        if (y >= 0 && y < matriz[0].size()) { // Verificar que y esté dentro del rango de columnas
            matriz[x][y] = 200;
        }
    }
}

int main(){
    Plane plane(11, 11);
    Lineal lineal(1, 0);

    plane.fill();

    vector<vector<int>>& planeMatrix = plane.getPlane(); // Obtener una referencia al vector plane

    lineal.print(planeMatrix);

    plane.print();

    return 0;
}

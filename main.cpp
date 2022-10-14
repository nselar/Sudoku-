#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class sudoku{
public:
    vector<int> lineaHorizontal;
    vector<int> lineaVertical;
    vector<int> cuadrante;
    int celda;
public:
    sudoku(){};
    sudoku(vector<int> lineaH, vector<int> lineaV,
           vector<int> cuad){
        lineaHorizontal = lineaH;
        lineaVertical = lineaV;
        cuadrante = cuad;
    }

    bool busquedaVertical(int numero, vector<int> linea);
    bool busquedaHorizontal(int numero, vector<int> linea);
    bool busquedaCuadrante(int numero, vector<int> linea);
    sudoku leerArchivo(string nombreArchivo);

    vector<int> getLineaHorizontal(void){
        return lineaHorizontal;
    }

    vector<int> getLineaVertical(void){
        return lineaVertical;
    }

    vector<int> getCuadrante(void){
        return cuadrante;
    }

    void setLineaHorizontal(vector<int> lineaH){
        lineaHorizontal = lineaH;
    }

    void setLineaVertical(vector<int> lineaV){
        lineaVertical = lineaV;
    }

    void setCuadrante(vector<int> cuad){
        cuadrante = cuad;
    }
};

bool sudoku::busquedaHorizontal(int numero, vector<int> linea){
    for(int i = 0; i <= linea.size() - 1; i++){
        if(numero == linea.at(i)){
            return false;
        }
    }
    return true;
}


bool sudoku::busquedaVertical(int numero, vector<int> linea){
    for(int i = 0; i <= linea.size() - 1; i++){
        if(numero == lineaVertical.at(i)){
            return false;
        }
    }
    return true;
}

bool sudoku::busquedaCuadrante(int numero, vector<int> linea){
    for(int i = 0; i <= linea.size() - 1; i++){
        if(numero == cuadrante.at(i)){
            return false;
        }
    }
    return true;
}

sudoku sudoku::leerArchivo(string nombreArchivo){
    ifstream ficheroEntrada;
    string frase;
    string::size_type sz;
    while(! ficheroEntrada.eof()){
        ficheroEntrada.open(nombreArchivo);
        getline(ficheroEntrada, frase);
        int i = 0;
        while(i <= 9){
            for(int j = 1; j <= frase.length(); j++){
                char caracter = frase.at(j);
                string caracter2 = "";
                caracter2.push_back(caracter);
                int decimal = stoi(caracter2, &sz);
                lineaHorizontal.push_back(decimal);
            }
            i++;
        }
    }
    ficheroEntrada.close();
    int i = 0;
    while(i <= 9){
        lineaVertical.push_back(lineaHorizontal.at(i));
        lineaVertical.push_back(lineaHorizontal.at(i + 9));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 2));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 3));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 4));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 5));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 6));
        lineaVertical.push_back(lineaHorizontal.at(i + 9 * 7));
        i++;
    }
    int k = 0;
    while(k <= 9){
        cuadrante.push_back(lineaHorizontal.at(i + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 1 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 2 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 9 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 10 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 11 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 19 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 20 + 3 * i));
        cuadrante.push_back(lineaHorizontal.at(i + 21 + 3 * i));
        k++;
    }
    sudoku MiSudoku(lineaHorizontal, lineaVertical, cuadrante);

    return MiSudoku;
}

ostream &operator << (ostream &o, const sudoku &n){
    for(int j = 0; j <= 9; j++){
        for(int i = 0; i <= 9; i++){
            o << n.lineaHorizontal.at(i) ;
        }
        o << endl;
    }
    return o;
}

int main(){
    string nombreArchivo = "sudoku.txt";
    sudoku MiSudoku;
    sudoku MiNuevoSudoku = MiSudoku.leerArchivo(nombreArchivo);

    //Creamos nueve vectores, uno por cada línea horizontal
    int a1, a2,a3, a4, a5, a6, a7, a8, a9;
    vector<int> lineaHorizontal1, lineaHorizontal2, lineaHorizontal3,
            lineaHorizontal4, lineaHorizontal5, lineaHorizontal6, lineaHorizontal7,
            lineaHorizontal8, lineaHorizontal9;
    for(a1 = 0; a1 <= 8; a1++){
        lineaHorizontal1.push_back(a1);
    }
    for(a2 = 0; a2 <= 8; a2++){
        lineaHorizontal2.push_back(a2);
    }
    for(a3 = 0; a3 <= 8; a3++){
        lineaHorizontal3.push_back(a3);
    }
    for(a4 = 0; a4 <= 8; a4++){
        lineaHorizontal4.push_back(a4);
    }
    for(a5 = 0; a5 <= 8; a5++){
        lineaHorizontal5.push_back(a5);
    }
    for(a6 = 0; a6 <= 8; a6++){
        lineaHorizontal6.push_back(a6);
    }
    for(a7 = 0; a7 <= 8; a7++){
        lineaHorizontal7.push_back(a7);
    }
    for(a8 = 0; a8 <= 8; a8++){
        lineaHorizontal8.push_back(a8);
    }
    for(a9 = 0; a9 <= 8; a9++){
        lineaHorizontal9.push_back(a9);
    }

    //Creamos nueve vectores, uno por cada línea vertical
    int b1, b2,b3, b4, b5, b6, b7, b8, b9;
    vector<int> lineaVertical1, lineaVertical2, lineaVertical3,
            lineaVertical4, lineaVertical5, lineaVertical6, lineaVertical7,
            lineaVertical8, lineaVertical9;
    for(b1 = 0; b1 <= 8; b1++){
        lineaVertical1.push_back(b1);
    }
    for(b2 = 0; b2 <= 8; b2++){
        lineaVertical2.push_back(b2);
    }
    for(b3 = 0; b3 <= 8; b3++){
        lineaVertical3.push_back(b3);
    }
    for(b4 = 0; b4 <= 8; b4++){
        lineaVertical4.push_back(b4);
    }
    for(b5 = 0; b5 <= 8; b5++){
        lineaVertical5.push_back(b5);
    }
    for(b6 = 0; b6 <= 8; b6++){
        lineaVertical6.push_back(b6);
    }
    for(b7 = 0; b7 <= 8; b7++){
        lineaVertical7.push_back(b7);
    }
    for(b8 = 0; b8 <= 8; b8++){
        lineaVertical8.push_back(b8);
    }
    for(b9 = 0; b9 <= 8; b9++){
        lineaVertical9.push_back(b9);
    }

    //Creamos nueve vectores, uno por cada cuadrante
    int c1, c2, c3, c4, c5, c6, c7, c8, c9;
    vector<int> cuadrante1, cuadrante2, cuadrante3, cuadrante4, cuadrante5,
            cuadrante6, cuadrante7, cuadrante8, cuadrante9;
    for(c1 = 0; c1 <= 8; c1++){
        cuadrante1.push_back(c1);
    }
    for(c2 = 0; c2 <= 8; c2++){
        cuadrante2.push_back(c2);
    }
    for(c3 = 0; c3 <= 8; c3++){
        cuadrante3.push_back(c3);
    }
    for(c4 = 0; c4 <= 8; c4++){
        cuadrante4.push_back(c4);
    }
    for(c5 = 0; c5 <= 8; c5++){
        cuadrante5.push_back(c5);
    }
    for(c6 = 0; c6 <= 8; c6++){
        cuadrante6.push_back(c6);
    }
    for(c7 = 0; c7 <= 8; c7++){
        cuadrante7.push_back(c7);
    }
    for(c8 = 0; c8 <= 8; c8++){
        cuadrante8.push_back(c8);
    }
    for(c9 = 0; c9 <= 8; c9++){
        cuadrante9.push_back(c9);
    }

    cout << MiNuevoSudoku << endl;

    return 0;
}

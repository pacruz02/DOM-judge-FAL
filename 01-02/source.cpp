// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// función que resuelve el problema
void resolver(vector<string> const& ganadores, string pais) {
    int ultimo = -1, cont = 1, i = ganadores.size();

    for (auto it = ganadores.rbegin(); it != ganadores.rend(); ++it) {
        if (*it == pais) {
            ultimo = cont;
            break;
        }
        cont++;
    }

    cout << (ultimo == -1 ? "NUNCA" : to_string(ultimo)) << '\n';
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int a;
    string pais, ganador;
    cin >> a;

    if (!a)
        return false;

    cin >> pais;
    vector<string> ganadores;

    for (int i = 0; i < a; i++) {
        cin >> ganador;
        ganadores.push_back(ganador);
    }
    resolver(ganadores, pais);

    // escribir sol

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}

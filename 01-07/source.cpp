// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const & cotas, int D) {
    int act = cotas[0], i = 1, desnivel = 0;
    bool apto = true;

    while (apto && i < cotas.size()) {
        if (cotas[i] <= act)
            desnivel = 0;
        else
            desnivel += cotas[i] - act;
    
        act = cotas[i];

        if (desnivel > D)
            apto = false;

        i++;
    }

    return apto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, D;

    cin >> D >> N;

    if (!std::cin)
        return false;

    vector <int> datos(N);

    for (int& x : datos) cin >> x;

    cout << (resolver(datos, D) ? "APTA" : "NO APTA");

    cout << '\n';

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
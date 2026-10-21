// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector <int> const& v) {
    int sol = 0;

    if (v.size() == 0)
        return 0;
    if (v.size() == 1)
        return 1;

    int act = 1, prev = v[0];

    for (int i = 1; i < v.size(); i++) {
        if (abs(v[i] - prev) == 1)
            act++;
        else {
            if (act > sol)
                sol = act;
            act = 1;
        }
        prev = v[i];
    }

    if (act > sol)
        sol = act;

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n;

    cin >> n;

    vector<int> v(n);

    for (int& x : v) cin >> x;

    cout << resolver(v) << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
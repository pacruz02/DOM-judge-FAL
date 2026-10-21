// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

// función que resuelve el problema
int resolver(vector<int> const & tension, vector<int> const& dbs, int T, int V) {
    int n = tension.size();
    int ini = 0;
    long long sumaTension = 0; // Usamos long long para evitar desbordamientos en la suma si T y N son grandes
    int subidasVolumen = 0;

    int mejorInicio = -1;
    bool encontrado = false;

    for (int fin = 0; fin < n; ++fin) {
        sumaTension += tension[fin];

        // Contamos si el volumen sube respecto al elemento anterior
        if (fin > 0 && dbs[fin] > dbs[fin - 1]) {
            subidasVolumen++;
        }

        while (subidasVolumen > V) {
            if (ini + 1 < n && dbs[ini + 1] > dbs[ini]) {
                subidasVolumen--;
            }
            sumaTension -= tension[ini];
            ini++;
        }

        if (sumaTension >= T && subidasVolumen <= V) {
            if (!encontrado || ini < mejorInicio) {
                encontrado = true;
                mejorInicio = ini;
            }
        }
    }

    return mejorInicio;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, t, v;

    cin >> n >> t >> v;

    if (!std::cin)
        return false;

    vector<int> tension(n);
    vector<int> dbs(n);

    for (int &x : tension) cin >> x;
    for (int &x : dbs) cin >> x;

    int sol = resolver(tension, dbs, t, v);
    if (sol >= 0)
        cout << "SI " << sol << '\n';
    else
        cout << "NO\n";

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
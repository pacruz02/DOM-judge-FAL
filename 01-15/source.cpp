// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(vector<int> const& v, int l) {
    int max, act = 0, sol = 0;
    int i = 0, j = l;

    for (int t = 0; t < l; t++)
        act++;
    max = act;

    while (j < v.size()) {
        act -= v[i], act += v[j];

        if (act >= max) {
            max = act;
            sol = i + 1;
        }

        i++;j++;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int n, l;

    cin >> n >> l;
    if (!n && !l)
        return false;

    vector <int>v(n);

    for (int& x : v) cin >> x;

    cout << resolver(v, l ) << '\n';

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
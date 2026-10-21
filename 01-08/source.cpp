// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FALL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolver(vector<int> const& datos, int D, int L) {
    int n = datos.size();
    if (n == 0) return -1;

    int ini = 0;
    for (int i = 1; i < n; ++i) {
        if (datos[i] < datos[i - 1]) {
            int longitud = (i - 1) - ini + 1;
            int desnivel = datos[i - 1] - datos[ini];

            if (longitud > L && desnivel >= D) {
                return ini;
            }
            ini = i;
        }
    }

    int longitud = (n - 1) - ini + 1;
    int desnivel = datos[n - 1] - datos[ini];
    if (longitud > L && desnivel >= D) {
        return ini;
    }

    return -1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int N, D, L;

    cin >> N >> D >> L;

    if (!std::cin)
        return false;

    vector<int> datos(N);

    for (int& x : datos) cin >> x;

    int sol = resolver(datos, D, L);

    if (sol > -1)
        cout << "SI " << sol;
    else
        cout << "NO";

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
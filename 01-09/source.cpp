// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

pair<int, int> resolver(vector<int> const& datos, int t) {
    int max_len = 0;
    int sol_ini = 0;
    int sol_fin = 0;

    int n = datos.size();
    int i = 0;

    while (i < n) {
        if (datos[i] > t) {
            int ini = i;
            int act_len = 0;

            while (i < n && datos[i] > t) {
                act_len++;
                i++;
            }

            if (act_len > max_len) {
                max_len = act_len;
                sol_ini = ini;
                sol_fin = i - 1;
            }
        }
        else {
            i++;
        }
    }

    return { sol_ini, sol_fin };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    int n, t; 

    cin >> n >> t;

    vector<int> datos(n);

    for (int& x : datos) cin >> x;

    auto sol = resolver(datos, t);

    cout << sol.first << ' ' << sol.second << '\n';
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
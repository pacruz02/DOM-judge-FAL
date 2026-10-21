// Nombre del alumno Pablo Cruz Sojo
// Usuario del Juez FAL-F22


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(vector<int> const& datos, int t) {
    int i = 1, l = datos[0], cont = 1;
    bool b = false;

    while (i < datos.size() && !b) {
        if (datos[i] == l) {
            cont++;
        }
        else {
            b = cont >= t && datos[i] < l;
            l = datos[i];
            cont = 1;
        }

        i++;
    }
    return b;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N, t, c;

    cin >> N >> t;

    if (!N && !t)
        return false;

    vector<int> datos(N);

    for (int i = 0; i < N; i++) {
        cin >> c;
        datos[i] = c;
    }

    cout << (resolver(datos, t) ? "SI" : "NO") << '\n';

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
